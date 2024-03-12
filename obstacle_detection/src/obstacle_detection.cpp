#include"obstacle_detection.hpp"

ObsDetection::ObsDetection():Node("obstacle_detection_node"){
	sub_scan_ = this->create_subscription<LidarMSG>("/scan", 1, std::bind(&ObsDetection::scan_callback ,this ,std::placeholders::_1));
	sub_area_ = this->create_subscription<AreaMSG>("/drive/obstacle/area", 1, std::bind(&ObsDetection::area_callback ,this ,std::placeholders::_1));
	sub_gps_ = this->create_subscription<GpsMSG>("/sensor/ublox/fix", 1, std::bind(&ObsDetection::gps_callback ,this ,std::placeholders::_1));
	sub_odom_ = this->create_subscription<OdomMSG>("/odom", 1, std::bind(&ObsDetection::odom_callback ,this ,std::placeholders::_1));

	cb_group_status_ = create_callback_group(rclcpp::CallbackGroupType::MutuallyExclusive);
	rclcpp::PublisherOptions pub_status_options;
	pub_status_options.callback_group = cb_group_status_;
	pub_status_ = this->create_publisher<StatusMSG>("/drive/obstacle/status", 1,pub_status_options);
}

void ObsDetection::odom_callback(const std::shared_ptr<OdomMSG> odom)
{
	odom_vel_x=odom->twist.twist.linear.x;
}
void ObsDetection::gps_callback(const std::shared_ptr<GpsMSG> gps)
{
	robot_lat=gps->latitude;
	robot_long=gps->longitude;

}
void ObsDetection::area_callback(const std::shared_ptr<AreaMSG> area)
{
	area_status=area->obstacle_area_status;

	//status 1 : relative obstacle
	obstacle_direction=area->obstacle_direction;
	obstacle_distance=area->obstacle_distance;
	obstacle_length=area->obstacle_length;

	//status 2 : lat,long
	area_lat_1=area->obstacle_lat_1;
	area_long_1=area->obstacle_long_1;
	area_lat_2=area->obstacle_lat_2;
	area_long_1=area->obstacle_long_2;
}

void ObsDetection::scan_callback(const std::shared_ptr<LidarMSG> scan){
	int robot_detect_x,robot_detect_y;
	int lp,lp_x,lp_y;

	StatusMSG status;
	////tmp value
	switch(area_status)
	{
		case 1:
			area_x1=0;
			area_y1=0;
			area_x2=0;
			area_y2=0;
			break;	
		case 2:
			area_x1=0;
			area_y1=0;
			area_x2=0;
			area_y2=0;
			break;	
		default:
			area_x1=-CAR_WIDTH/2;
			area_x2=CAR_WIDTH/2;
			if(odom_vel_x >= 0)
			{
				area_y1=-OBS_MOVE_DIST;
				area_y2=0;
			}
			else
			{
				area_y1=0;
				area_y2=OBS_MOVE_DIST;
			}
			break;	
	}
	int num_ranges = scan->ranges.size();

	unsigned int detect_arealen = (float)DETECT_SIZE*(float)DETECT_RES*2;
	int detect_area[detect_arealen][detect_arealen]={0,};
	memset(detect_area,0,sizeof(detect_area));
	float occ_x,occ_y;
	for(lp=1;lp<num_ranges;lp++)
	{
		if((!std::isnan(scan->ranges[lp])) && (scan->ranges[lp] > 0.019 && ((scan->ranges[lp]-scan->ranges[lp-1]) < SCAN_FILTER_DIST )))
		{
			occ_x=-scan->ranges[lp]*sin( (scan->angle_min+scan->angle_increment*lp) );
			occ_y=-scan->ranges[lp]*cos( (scan->angle_min+scan->angle_increment*lp) );
			if((fabs(occ_x) < DETECT_SIZE) && (fabs(occ_y) < DETECT_SIZE))
			{
				detect_area[int((DETECT_SIZE+occ_x)*DETECT_RES)][int((DETECT_SIZE+occ_y)*DETECT_RES)]=1;
			}
		}
	}

	detect_val=0;
	robot_detect_x=(DETECT_SIZE + (float)(area_x1))*DETECT_RES;
	robot_detect_y=(DETECT_SIZE + (float)(area_y1))*DETECT_RES;
	obs_dist=DETECT_SIZE;
	for(lp_y=0;lp_y < DETECT_RES*(area_y2-area_y1);lp_y++)
	{
		for(lp_x=0;lp_x < DETECT_RES*(area_x2-area_x1);lp_x++)
		{
			if(detect_area[robot_detect_x+lp_x][robot_detect_y+lp_y] == 1)
			{
				detect_area[robot_detect_x+lp_x][robot_detect_y+lp_y] = 2;
				detect_val=1;
				if(obs_dist > sqrt(pow(detect_arealen/2-(robot_detect_x+lp_x),2) + pow(detect_arealen/2-(robot_detect_y+lp_y),2))/DETECT_RES)
				{
					obs_dist = sqrt(pow(detect_arealen/2-(robot_detect_x+lp_x),2) + pow(detect_arealen/2-(robot_detect_y+lp_y),2))/DETECT_RES;
				}
			}
		}
	}
	status.obstacle_status = area_status;
	status.obstacle_value = detect_val;
	status.obstacle_distance = obs_dist;
	pub_status_->publish(status);
	/*
	detect_area[detect_arealen/2][detect_arealen/2]=5;
	printf("\e[1;1H\e[2J");
	for(lp_y=0;lp_y < detect_arealen;lp_y++)
	{
		for(lp_x=0;lp_x < detect_arealen;lp_x++)
		{
			printf("%d",detect_area[lp_x][lp_y]);
		}
		printf("\n");
	}
	printf("\n\n\n");
	*/
}



