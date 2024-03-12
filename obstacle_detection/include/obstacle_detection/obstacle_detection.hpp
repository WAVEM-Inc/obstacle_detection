#ifndef OBS_DETECTION_LISTENER_HPP__
#define OBS_DETECTION_LISTENER_HPP__

#define DETECT_SIZE 5
#define DETECT_RES 20
#define CAR_WIDTH 1.2
#define SCAN_FILTER_DIST 0.2
#define OBS_MOVE_DIST 3

#include <iostream>
#include <fstream>
#include <fcntl.h>
#include "rclcpp/rclcpp.hpp"
#include "sensor_msgs/msg/laser_scan.hpp"
#include "sensor_msgs/msg/nav_sat_fix.hpp"
#include "obstacle_msgs/msg/area.hpp"
#include "obstacle_msgs/msg/status.hpp"
#include "nav_msgs/msg/odometry.hpp"
#include <unistd.h>
using GpsMSG = sensor_msgs::msg::NavSatFix;
using LidarMSG = sensor_msgs::msg::LaserScan;
using AreaMSG = obstacle_msgs::msg::Area;
using StatusMSG = obstacle_msgs::msg::Status;
using OdomMSG = nav_msgs::msg::Odometry;
class ObsDetection : public rclcpp::Node{
    private :
        rclcpp::CallbackGroup::SharedPtr cb_group_status_;
        rclcpp::Publisher<StatusMSG>::SharedPtr pub_status_;

        rclcpp::Subscription<OdomMSG>::SharedPtr sub_odom_;
        rclcpp::Subscription<GpsMSG>::SharedPtr sub_gps_;
        rclcpp::Subscription<LidarMSG>::SharedPtr sub_scan_;
        rclcpp::Subscription<AreaMSG>::SharedPtr sub_area_;
        void scan_callback(const std::shared_ptr<LidarMSG> scan);
        void gps_callback(const std::shared_ptr<GpsMSG> gps);
	void area_callback(const std::shared_ptr<AreaMSG> area);
	void odom_callback(const std::shared_ptr<OdomMSG> odom);
	float area_x1, area_x2, area_y1, area_y2;
	int obstacle_direction;
	float obstacle_distance, obstacle_length;
	float area_lat_1, area_long_1, area_lat_2,area_long_2;
	float obs_dist;
	int area_status;
	bool detect_val;
	float odom_vel_x=0;

	//gps callback
	float robot_lat,robot_long;
    public :
        ObsDetection();
	

};
#endif
