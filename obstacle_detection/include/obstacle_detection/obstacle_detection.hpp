#ifndef OBS_DETECTION_LISTENER_HPP__
#define OBS_DETECTION_LISTENER_HPP__

#define DETECT_SIZE 25
#define DETECT_RES 4
#define CAR_WIDTH 1.4
#define SCAN_FILTER_DIST 0.2
#define OBS_MOVE_DIST 4
#define CAR_OFFSET 2.7

#include <iostream>
#include <fstream>
#include <fcntl.h>
#include <malloc.h>
#include "rclcpp/rclcpp.hpp"
#include "sensor_msgs/msg/laser_scan.hpp"
#include "std_msgs/msg/string.hpp"
#include "sensor_msgs/msg/nav_sat_fix.hpp"
#include "ktp_data_msgs/msg/detected_object.hpp"
#include "obstacle_msgs/msg/area.hpp"
#include "obstacle_msgs/msg/status.hpp"
#include "nav_msgs/msg/odometry.hpp"
#include "route_msgs/msg/drive_state.hpp"
#include "distance/geo_trans.hpp"
#include "distance/calc_distance.hpp"
#include <unistd.h>
#include "quaternion/quaternion.hpp"
#include <list>
#include <boost/geometry.hpp>
using GpsMSG = sensor_msgs::msg::NavSatFix;
using LidarMSG = sensor_msgs::msg::LaserScan;
using AreaMSG = obstacle_msgs::msg::Area;
using StatusMSG = obstacle_msgs::msg::Status;
using OdomMSG = nav_msgs::msg::Odometry;
using DriveMSG = route_msgs::msg::DriveState;
using StringMSG = std_msgs::msg::String;
using DetectMSG = ktp_data_msgs::msg::DetectedObject;
class ObsDetection : public rclcpp::Node{
	private :
		rclcpp::CallbackGroup::SharedPtr cb_group_status_;
		rclcpp::Publisher<StatusMSG>::SharedPtr pub_status_;
		rclcpp::CallbackGroup::SharedPtr cb_group_coop_;
		rclcpp::Publisher<StringMSG>::SharedPtr pub_coop_;

		rclcpp::Subscription<OdomMSG>::SharedPtr sub_odom_;
		rclcpp::Subscription<GpsMSG>::SharedPtr sub_gps_;
		rclcpp::Subscription<LidarMSG>::SharedPtr sub_scan_;
		rclcpp::Subscription<DriveMSG>::SharedPtr sub_drive_;
		rclcpp::Subscription<DetectMSG>::SharedPtr sub_detect_;
		Quaternion qua_;
		clock_t log_time, end_time;
		void scan_callback(const std::shared_ptr<LidarMSG> scan);
		void gps_callback(const std::shared_ptr<GpsMSG> gps);
		void odom_callback(const std::shared_ptr<OdomMSG> odom);

		void drive_callback(const std::shared_ptr<DriveMSG> drive);
		void detect_callback(const std::shared_ptr<DetectMSG> detect);
		bool area_check(double point_x, double point_y, double *area);
		double area_x1, area_x2, area_y1, area_y2,area_x3,area_y3,area_x4,area_y4;
		double obs_area[8];
		int obstacle_direction;
		double obstacle_distance, obstacle_length;
		double area_lat_1, area_long_1, area_lat_2,area_long_2;
		double obs_dist;
		double car_offset=0;
		int area_status=0;
		int area_status_val=0;
		bool detect_val;
		double node_lat, node_long, route_angle;
		double node_offset[4], area_width_l[4],area_width_r[4], area_height[4];
		//odom callback
		double odom_vel_x=0;
		double  robot_angle=0;
		double  global_angle=0;
		double coop_detect_num=0;
		double coop_detect_axis[512];
		bool coop_flag=false;
		bool coop_pub_flag=false;
		std::string coop_detect_id[256];

		//gps callback
		double robot_lat,robot_long;
	public :
		ObsDetection();

};
#endif
