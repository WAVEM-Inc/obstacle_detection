#include"obstacle_detection.hpp"

ObsDetection::ObsDetection():Node("obstacle_detection_node"){
	sub_scan_ = this->create_subscription<LidarMSG>("/sensor/scan_merge", 1, std::bind(&ObsDetection::scan_callback ,this ,std::placeholders::_1));
	sub_area_ = this->create_subscription<AreaMSG>("/drive/obstacle/area", 1, std::bind(&ObsDetection::area_callback ,this ,std::placeholders::_1));
}

void ObsDetection::area_callback(const std::shared_ptr<AreaMSG> area)
{

}

void ObsDetection::scan_callback(const std::shared_ptr<LidarMSG> scan){
	int robot_detect_x,robot_detect_y;
	int lp,lp_x,lp_y;

	////tmp value
	float distance_x,lidar_range;
	int distance_val,detect_val, detect_flag;
	float vel_x;
	switch(area_status)
	{
		case 0:
			area_x1=-CAR_WIDTH/2;
			area_x2=CAR_WIDTH/2;
			if(vel_x >= 0)
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
			
	}
	if(distance_x < 0)
	{
		area_x1=-0.27;
		area_x2=0.27;
		area_y1=0.0;
		area_y2=lidar_range - 0.0;
	}
	else
	{
		area_x1=-0.27;
		area_x2=0.27;
		area_y1=-lidar_range+0.0;
		area_y2=0.0;
	}
	int num_ranges = scan->ranges.size();

	unsigned int detect_arealen = (float)DETECT_SIZE*(float)DETECT_RES*2;
	int detect_area[detect_arealen][detect_arealen]={0,};

	float occ_x,occ_y;
	for(lp=1;lp<scan->ranges.size();lp++)
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

	robot_detect_x=(DETECT_SIZE + (float)(area_x1))*DETECT_RES;
	robot_detect_y=(DETECT_SIZE + (float)(area_y1))*DETECT_RES;
	for(lp_y=0;lp_y < DETECT_RES*(area_y2-area_y1);lp_y++)
	{
		for(lp_x=0;lp_x < DETECT_RES*(area_x2-area_x1);lp_x++)
		{
			if(detect_area[robot_detect_x+lp_x][robot_detect_y+lp_y] == 1)
			{
				detect_area[robot_detect_x+lp_x][robot_detect_y+lp_y] = 2;
				detect_flag=1;
				break;
			}
			else
			{
				detect_flag=0;
			}
		}
		if(detect_flag)
		{
			break;
		}
	}
	if(detect_flag)
	{
		detect_val=1;
	}
	else
	{
		detect_val=0;
	}

}



