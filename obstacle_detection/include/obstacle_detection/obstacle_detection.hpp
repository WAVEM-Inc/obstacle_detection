#ifndef OBS_DETECTION_LISTENER_HPP__
#define OBS_DETECTION_LISTENER_HPP__

#define DETECT_SIZE 10
#define DETECT_RES 10
#define CAR_WIDTH 1.2
#define SCAN_FILTER_DIST 0.2
#define OBS_MOVE_DIST 5

#include <iostream>
#include <fstream>
#include <fcntl.h>
#include "rclcpp/rclcpp.hpp"
#include "sensor_msgs/msg/laser_scan.hpp"
#include "sensor_msgs/msg/nav_sat_fix.hpp"
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
class ObsDetection : public rclcpp::Node{
	private :
		rclcpp::CallbackGroup::SharedPtr cb_group_status_;
		rclcpp::Publisher<StatusMSG>::SharedPtr pub_status_;

		rclcpp::Subscription<OdomMSG>::SharedPtr sub_odom_;
		rclcpp::Subscription<GpsMSG>::SharedPtr sub_gps_;
		rclcpp::Subscription<LidarMSG>::SharedPtr sub_scan_;
		rclcpp::Subscription<DriveMSG>::SharedPtr sub_drive_;
		Quaternion qua_;
		void scan_callback(const std::shared_ptr<LidarMSG> scan);
		void gps_callback(const std::shared_ptr<GpsMSG> gps);
		void odom_callback(const std::shared_ptr<OdomMSG> odom);

		void drive_callback(const std::shared_ptr<DriveMSG> drive);
		bool area_check(double point_x, double point_y, double *area);
		double area_x1, area_x2, area_y1, area_y2,area_x3,area_y3,area_x4,area_y4;
		double obs_area[8];
		int obstacle_direction;
		double obstacle_distance, obstacle_length;
		double area_lat_1, area_long_1, area_lat_2,area_long_2;
		double obs_dist;
		int area_status=0;
		bool detect_val;
		double node_lat, node_long, route_angle;
		double node_offset[4], area_width_l[4],area_width_r[4], area_height[4];
		//odom callback
		double odom_vel_x=0;
		double  robot_angle=0;
		double  global_angle=0;

		//gps callback
		double robot_lat,robot_long;
	public :
		ObsDetection();

};
#endif
