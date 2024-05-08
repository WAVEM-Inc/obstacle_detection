#include"obstacle_detection.hpp"

ObsDetection::ObsDetection():Node("obstacle_detection_node"){
	sub_scan_ = this->create_subscription<LidarMSG>("/scan/multi", 1, std::bind(&ObsDetection::scan_callback ,this ,std::placeholders::_1));
	sub_gps_ = this->create_subscription<GpsMSG>("/sensor/ublox/fix", 1, std::bind(&ObsDetection::gps_callback ,this ,std::placeholders::_1));
	sub_odom_ = this->create_subscription<OdomMSG>("/drive/odom/origin", 1, std::bind(&ObsDetection::odom_callback ,this ,std::placeholders::_1));

	sub_drive_ = this->create_subscription<DriveMSG>("/drive/info", 1, std::bind(&ObsDetection::drive_callback ,this ,std::placeholders::_1));
	sub_detect_ = this->create_subscription<DetectMSG>("/drive/object_detect", 1, std::bind(&ObsDetection::detect_callback ,this ,std::placeholders::_1));
	cb_group_status_ = create_callback_group(rclcpp::CallbackGroupType::MutuallyExclusive);
	rclcpp::PublisherOptions pub_status_options;
	pub_status_options.callback_group = cb_group_status_;
	pub_status_ = this->create_publisher<StatusMSG>("/drive/obstacle/status", 1,pub_status_options);
	rclcpp::PublisherOptions pub_coop_options;
	pub_coop_options.callback_group = cb_group_coop_;
	pub_coop_ = this->create_publisher<StringMSG>("/drive/obstacle/cooperative", 1,pub_coop_options);
	memset(coop_detect_axis,0,sizeof(coop_detect_axis));
	memset(coop_detect_id,0,sizeof(coop_detect_id));
	log_time=end_time;
}

void ObsDetection::detect_callback(const std::shared_ptr<DetectMSG> detect)
{
	memset(coop_detect_axis,0,sizeof(coop_detect_axis));
	memset(coop_detect_id,0,sizeof(coop_detect_id));
	coop_detect_num = detect->objects.size();
	area_status=2;
	area_status_val=2;
	coop_flag=true;
	coop_pub_flag=false;
	for(int lp=0;lp<coop_detect_num;lp++)
	{
		coop_detect_id[lp]=detect->objects[lp].object_id;
		coop_detect_axis[2*lp]=detect->objects[lp].y; //latitude
		coop_detect_axis[2*lp+1]=detect->objects[lp].x; //longitude
	}
}
void ObsDetection::drive_callback(const std::shared_ptr<DriveMSG> drive)
{
	resutlt_distance gps_distance;
	CalcDistance calc;
	StringMSG coop;

	int lp;
	double tm_x,tm_y;
	if(drive->code.compare(std::string("arrive"))==0)
	{
		memset(node_offset,0,sizeof(node_offset));
		memset(area_width_l,0,sizeof(area_width_l));
		memset(area_width_r,0,sizeof(area_width_r));
		memset(area_height,0,sizeof(area_height));
		//printf("detection_range SIZE=%ld,%f,%f\n\n", drive->end_node.detection_range.size(),drive->end_node.detection_range[0].offset,drive->end_node.detection_range[2].offset);
		if(drive->end_node.kind.compare(std::string("waiting"))==0)
		{

			if(drive->end_node.detection_range.size() > 0 )
			{
				if(drive->end_node.detection_range[0].action_code.compare(std::string("cooperative"))==0)
				{
					coop_pub_flag=true;
					coop.data = "START";
					pub_coop_->publish(coop);
				}
				else
				{
					area_status=1;
					area_status_val=1;
				}
			}
			else
			{
				area_status=1;
				area_status_val=1;
			}
			node_lat=drive->end_node.position.latitude;
			node_long=drive->end_node.position.longitude;
			for(lp =0;lp< drive->end_node.detection_range.size() ;lp++)
			{
				node_offset[lp]=drive->end_node.detection_range[lp].offset;
				area_width_l[lp] = drive->end_node.detection_range[lp].width_left;
				area_width_r[lp] = drive->end_node.detection_range[lp].width_right;
				area_height[lp] = drive->end_node.detection_range[lp].height;
			}
			gps_distance = calc.getDistance(drive->start_node.position.latitude, drive->start_node.position.longitude, drive->end_node.position.latitude, drive->end_node.position.longitude,KTM);
			if((drive->end_node.position.latitude - drive->start_node.position.latitude) > 0)
			{
				tm_y=gps_distance.distance_y;
			}
			else
			{
				tm_y=-gps_distance.distance_y;
			}
			if((drive->end_node.position.longitude - drive->start_node.position.longitude) > 0)
			{
				tm_x=gps_distance.distance_x;
			}
			else
			{
				tm_x=-gps_distance.distance_x;
			}
			route_angle=atan2(tm_y,tm_x);
		}
	}
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

bool ObsDetection::area_check(double point_x, double point_y, double *check_area)
{
	int num_crosses=0;
	int area_num=4;
	for( int lp=0;lp < area_num;lp++)
	{
		int lp_y = (lp+1)%area_num;
		if (((check_area[lp*2+1]) > point_y) != ((check_area[lp_y*2+1]) > point_y)) 
		{
			double atX=((check_area[lp_y*2])- (check_area[lp*2])) 
				* (point_y - (check_area[lp*2+1]))
				/ ((check_area[lp_y*2+1]) - (check_area[lp*2+1]))
				+ (check_area[lp*2]);
			if( point_x < atX )
			{
				num_crosses++;
			}
		}
	}
	return num_crosses % 2 > 0;
}

void ObsDetection::scan_callback(const std::shared_ptr<LidarMSG> scan){
	resutlt_distance gps_distance;
	CalcDistance calc;
	int lp,lp_x,lp_y;
	log_time= clock();
	memset(obs_area,0,sizeof(obs_area));
	StatusMSG status;
	StringMSG coop;
	////tmp value
	//
	double node_x, node_y,area_start_x, area_start_y, coop_x,coop_y;
	/*
	   if(fabs(odom_vel_x) >= 0.1)
	   {
	   area_status=0;
	   }
	   */
	switch(area_status)
	{
		case 1:
		case 2:
			robot_angle=qua_.getterYaw();
			global_angle=(GLOBAL_ANGLE)*M_PI/180;
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
			area_start_x=-node_x+(node_offset[0]+GPS_OFFSET)*cos(route_angle);
			area_start_y=-node_y+(node_offset[0]+GPS_OFFSET)*sin(route_angle);

			area_x1=area_start_x+area_width_l[0]*cos(route_angle+90*M_PI/180);
			area_y1=area_start_y+area_width_l[0]*sin(route_angle+90*M_PI/180);
			area_x2=area_x1+area_height[0]*cos(route_angle);
			area_y2=area_y1+area_height[0]*sin(route_angle);
			area_x3=area_start_x+area_width_r[0]*cos(route_angle-90*M_PI/180);
			area_y3=area_start_y+area_width_r[0]*sin(route_angle-90*M_PI/180);
			area_x4=area_x3+area_height[0]*cos(route_angle);
			area_y4=area_y3+area_height[0]*sin(route_angle);
			obs_area[0] =area_x1;
			obs_area[1] =area_y1;
			obs_area[2] =area_x2;
			obs_area[3] =area_y2;
			obs_area[4] =area_x4;
			obs_area[5] =area_y4;
			obs_area[6] =area_x3;
			obs_area[7] =area_y3;
			break;
		default:
			area_status=0;
			robot_angle=0;
			global_angle=0;
			area_x1=-(CAR_WIDTH/2);
			area_x2=CAR_WIDTH/2;
			if(odom_vel_x >= 0)
			{
				car_offset=FRONT_CAR_OFFSET;
				area_y1=-(OBS_MOVE_DIST+FRONT_CAR_OFFSET);
				area_y2=-car_offset;
			}
			else
			{
				car_offset=REAR_CAR_OFFSET;
				area_y1=car_offset;
				area_y2=OBS_MOVE_DIST + REAR_CAR_OFFSET;
			}
			obs_area[0] =area_x1;
			obs_area[1] =-area_y1;
			obs_area[2] =area_x2;
			obs_area[3] =-area_y1;
			obs_area[4] =area_x2;
			obs_area[5] =-area_y2;
			obs_area[6] =area_x1;
			obs_area[7] =-area_y2;
			break;	
	}
	int num_ranges = scan->ranges.size();

	int detect_arealen = (double)DETECT_SIZE*(double)DETECT_RES*2;
	int detect_area[detect_arealen][detect_arealen]={0,};
	double occ_x,occ_y;
	for(lp=1;lp<num_ranges;lp++)
	{
		if((!std::isnan(scan->ranges[lp])) && (scan->ranges[lp] > 0.019 && ((scan->ranges[lp]-scan->ranges[lp-1]) < SCAN_FILTER_DIST )))
		{
			occ_x=-scan->ranges[lp]*sin( double(scan->angle_min+scan->angle_increment*lp)+robot_angle+global_angle );
			occ_y=-scan->ranges[lp]*cos( double(scan->angle_min+scan->angle_increment*lp)+robot_angle+global_angle );
			if((fabs(occ_x) < DETECT_SIZE) && (fabs(occ_y) < DETECT_SIZE))
			{
				detect_area[(int)((DETECT_SIZE+occ_x)*DETECT_RES)][(int)((DETECT_SIZE+occ_y)*DETECT_RES)]=1;
			}
		}
	}
	detect_val=0;
	obs_dist=DETECT_SIZE;

	if(area_status==2)
	{
		for(lp=0;lp<coop_detect_num;lp++)
		{
			gps_distance = calc.getDistance(robot_lat, robot_long,coop_detect_axis[2*lp] , coop_detect_axis[2*lp+1],KTM);
			if((coop_detect_axis[2*lp] - robot_lat) > 0)
			{
				coop_y=gps_distance.distance_y;
			}
			else
			{
				coop_y=-gps_distance.distance_y;
			}
			if((coop_detect_axis[2*lp+1] - robot_long) > 0)
			{
				coop_x=gps_distance.distance_x;
			}
			else
			{
				coop_x=-gps_distance.distance_x;
			}
			if(area_check(coop_x ,coop_y,obs_area ) )
			{
				area_status_val=2;
				detect_val=1;
				obs_dist=0;
				status.obstacle_id = coop_detect_id[lp];
			}
		}	
	}
	if(!detect_val)
	{
		for(lp_y=0;lp_y < detect_arealen;lp_y++)
		{
			for(lp_x=0;lp_x < detect_arealen;lp_x++)
			{
				if(detect_area[lp_x][lp_y] > 0)
				{
					if(area_check((double)((lp_x-detect_arealen/2)/DETECT_RES) ,(double)((detect_arealen/2-lp_y)/DETECT_RES),obs_area ) )
					{
						if(area_status > 0)
						{
							area_status_val=1;
						}
						else
						{
							area_status_val=0;
						}
						detect_area[lp_x][lp_y] = detect_area[lp_x][lp_y]+1;
						detect_val=true;
						if(area_status >= 1)
						{
							/*
							   if(obs_dist > sqrt(pow(detect_arealen/2-lp_x,2) + pow(detect_arealen/2-lp_y,2))/DETECT_RES)
							   {
							   obs_dist = sqrt(pow(detect_arealen/2-lp_x,2) + pow(detect_arealen/2-lp_y,2))/DETECT_RES;
							   }
							   */
							obs_dist = 0;
						}
						else
						{
							if(obs_dist >  fabs((double)(detect_arealen/2-lp_y)/DETECT_RES-car_offset))
							{
								obs_dist = fabs((double)(detect_arealen/2-lp_y)/DETECT_RES)-car_offset;
							}
						}
					}
				}
			}
		}
	}
	if(!detect_val)
	{
		obs_dist = 0;
	}
	status.obstacle_status = area_status_val;
	status.obstacle_value = detect_val;
	status.obstacle_distance = obs_dist;
	pub_status_->publish(status);
	if( detect_val==0 && coop_flag)
	{	
		coop.data = "STOP";
		pub_coop_->publish(coop);
		coop_flag=false;
		area_status=0;
		area_status_val=0;
	}
	else if(coop_flag && detect_val ==1)
	{
		area_status_val=2;
	}
	else if(detect_val==0)
	{
		area_status=0;
		area_status_val=0;
	}
	/*
	if(fabs(log_time - end_time) > 20)
	{
		end_time=log_time+20;
		char test[1000000];
		int lp_test=0;
		memset(test,0,sizeof(test));
		detect_area[detect_arealen/2][detect_arealen/2]=8;
		printf("\e[1;1H\e[2J");
		//printf("\e[1;1H");
		for(int i=0;i<4;i++)
		{
			//			detect_area[(int)((DETECT_SIZE+obs_area[i*2])*DETECT_RES)][(int)(-(DETECT_SIZE+obs_area[i*2+1])*DETECT_RES)]=1;
		}
		for(lp_y=0;lp_y < detect_arealen;lp_y++)
		{
			for(lp_x=0;lp_x < detect_arealen;lp_x++)
			{
				//printf("\e[1;1H\e[2J");
				//	   if(detect_area[lp_x][lp_y]>0)
				//	   {
				//	   printf("\e[%d,%d]%d",lp_x,lp_y,detect_area[lp_x][lp_y]);
				//	   }

				test[lp_test]=(char)(detect_area[lp_x][lp_y]+48);
				lp_test++;
				test[lp_test]=' ';
				lp_test++;
				test[lp_test]=' ';
				lp_test++;
			}
			//printf("\n");
			test[lp_test]='\n';
			lp_test++;
		}
		printf("%d\n",lp_test);
		printf("%s\n",test);
		printf("route_angle=%lf\n",route_angle);
		printf("\n\n\n");
	}
	*/
}
