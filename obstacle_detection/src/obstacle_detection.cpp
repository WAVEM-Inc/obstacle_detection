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
	qua_.setterX(odom->pose.pose.orientation.x);
	qua_.setterY(odom->pose.pose.orientation.y);
	qua_.setterZ(odom->pose.pose.orientation.z);
	qua_.setterW(odom->pose.pose.orientation.w);
	qua_.QuaternionToEulerAngles();
}
void ObsDetection::gps_callback(const std::shared_ptr<GpsMSG> gps)
{
	robot_lat=gps->latitude;
	robot_long=gps->longitude;

}
/*
   public static boolean isInside(GeoPoint B, List<GeoPoint> p) {
   int crosses = 0;
   int n = p.size();

   for (int i = 0; i < n; i++) 
   {
   int j = (i + 1) % n;

   if ((p.get(i).getLongitude() > B.getLongitude()) != (p.get(j).getLongitude() > B.getLongitude())) 
   {
   double atX = 
   (p.get(j).getLatitude() - p.get(i).getLatitude()) 
 * (B.getLongitude() - p.get(i).getLongitude()) 
 / (p.get(j).getLongitude() - p.get(i).getLongitude()) 
 + p.get(i).getLatitude();

 if (B.getLatitude() < atX)
 crosses++;
 }
 }

 return crosses % 2 > 0;
 }
 */
bool ObsDetection::area_check(double point_x, double point_y, double *check_area)
{
	int num_crosses=0;
	int area_num=4;
	
	for( int lp=0;lp < area_num;lp++)
	{
		int lp_y = (lp+1)%area_num;
		if ((check_area[lp*2+1] > point_y) != (check_area[lp_y*2+1] > point_y)) 
		{
			double atX=(check_area[lp_y*2] - check_area[lp*2]) 
				* (point_y - check_area[lp*2+1])
				/ (check_area[lp_y*2+1] - check_area[lp*2+1])
				+ check_area[lp*2];
			if( point_x < atX )
			{
				num_crosses++;
			}
		}
	}
	return num_crosses % 2 > 0;
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
	resutlt_distance gps_distance;
	CalcDistance calc;
	int robot_detect_x,robot_detect_y;
	int lp,lp_x,lp_y;

	memset(obs_area,0,sizeof(obs_area));
	StatusMSG status;
	////tmp value
	//
	double node_lat, node_long, node_offset, node_x, node_y,area_start_x, area_start_y;
	double area_width_l,area_width_r, area_height;
	double route_angle;
	
	if(fabs(odom_vel_x >= 0.1))
	{
		area_status=0;
	}
	switch(area_status)
	{
		case 1:
		case 2:
			robot_angle=qua_.getterYaw();
			gps_distance = calc.getDistance(robot_lat, robot_long, node_lat, node_long,KTM);
			if((node_lat - robot_lat) > 0)
			{
				node_y=gps_distance.distance_y;
			}
			else
			{
				node_y=-gps_distance.distance_y;
			}
			if((node_long - robot_long) > 0)
			{
				node_x=gps_distance.distance_x;
			}
			else
			{
				node_x=-gps_distance.distance_x;
			}
			area_start_x=node_x+node_offset*cos(route_angle);
			area_start_y=node_y+node_offset*sin(route_angle);

			area_x1=area_start_x+area_width_l*cos(route_angle+90*M_PI/180);
			area_y1=area_start_y+area_width_r*sin(route_angle+90*M_PI/180);
			area_x2=area_x1+area_height*cos(route_angle);
			area_y2=area_x1+area_height*sin(route_angle);
			area_x3=area_start_x+area_width_l*cos(route_angle-90*M_PI/180);
			area_y3=area_start_y+area_width_r*sin(route_angle-90*M_PI/180);
			area_x4=area_x3+area_height*cos(route_angle);
			area_y4=area_y3+area_height*sin(route_angle);
			obs_area[0] =area_x1;
			obs_area[1] =area_y1;
			obs_area[2] =area_x2;
			obs_area[3] =area_y2;
			obs_area[4] =area_x3;
			obs_area[5] =area_y3;
			obs_area[6] =area_x4;
			obs_area[7] =area_y4;
			break;	
		default:
			robot_angle=0;
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
			obs_area[0] =area_x1;
			obs_area[1] =-area_y1;
			obs_area[2] =area_x2;
			obs_area[3] =-area_y1;
			obs_area[4] =area_x2;
			obs_area[5] =area_y2;
			obs_area[6] =area_x1;
			obs_area[7] =area_y2;
			break;	
	}
	int num_ranges = scan->ranges.size();

	int detect_arealen = (double)DETECT_SIZE*(double)DETECT_RES*2;
	int detect_area[detect_arealen][detect_arealen]={0,};
	memset(detect_area,0,sizeof(detect_area));
	double occ_x,occ_y;
	for(lp=1;lp<num_ranges;lp++)
	{
		if((!std::isnan(scan->ranges[lp])) && (scan->ranges[lp] > 0.019 && ((scan->ranges[lp]-scan->ranges[lp-1]) < SCAN_FILTER_DIST )))
		{
			occ_x=-scan->ranges[lp]*sin( (scan->angle_min+scan->angle_increment*lp+robot_angle) );
			occ_y=-scan->ranges[lp]*cos( (scan->angle_min+scan->angle_increment*lp+robot_angle) );
			if((fabs(occ_x) < DETECT_SIZE) && (fabs(occ_y) < DETECT_SIZE))
			{
				detect_area[int((DETECT_SIZE+occ_x)*DETECT_RES)][int((DETECT_SIZE+occ_y)*DETECT_RES)]=1;
			}
		}
	}

	detect_val=0;
	obs_dist=DETECT_SIZE*2;
	for(lp_y=0;lp_y < detect_arealen;lp_y++)
	{
		for(lp_x=0;lp_x < detect_arealen;lp_x++)
		{
			if(detect_area[lp_x][lp_y] > 0)
			{
				if(area_check((double)(lp_x-detect_arealen/2)/DETECT_RES ,(double)(detect_arealen/2-lp_y)/DETECT_RES,obs_area ) )
				{
					detect_area[lp_x][lp_y] = 2;
					detect_val=1;
					if(area_status >= 1)
					{
						if(obs_dist > sqrt(pow(detect_arealen/2-lp_x,2) + pow(detect_arealen/2-lp_y,2))/DETECT_RES)
						{
							obs_dist = sqrt(pow(detect_arealen/2-lp_x,2) + pow(detect_arealen/2-lp_y,2))/DETECT_RES;
						}

					}
					else
					{
						if(obs_dist >  fabs((detect_arealen/2-lp_y)/DETECT_RES))
						{
							obs_dist = fabs((double)(detect_arealen/2-lp_y)/DETECT_RES);
						}
					}
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



