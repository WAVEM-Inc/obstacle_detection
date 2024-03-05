#ifndef VEL_BYPASS_LISTENER_HPP__
#define VEL_BYPASS_LISTENER_HPP__

#define DETECT_SIZE 10
#define DETECT_RES 20
#define CAR_WIDTH 1.2
#define SCAN_FILTER_DIST 0.2
#define OBS_MOVE_DIST 3

#include <iostream>
#include <fstream>
#include <fcntl.h>
#include "rclcpp/rclcpp.hpp"
#include "sensor_msgs/msg/laser_scan.hpp"
#include "obstacle_msgs/msg/area.hpp"
#include <unistd.h>
using LidarMSG = sensor_msgs::msg::LaserScan;
using AreaMSG = obstacle_msgs::msg::Area;
class ObsDetection : public rclcpp::Node{
    private :
        rclcpp::Subscription<LidarMSG>::SharedPtr sub_scan_;
        rclcpp::Subscription<AreaMSG>::SharedPtr sub_area_;
        void scan_callback(const std::shared_ptr<LidarMSG> scan);
	void area_callback(const std::shared_ptr<AreaMSG> area);
	float area_x1, area_x2, area_y1, area_y2;
	int area_status;
    public :
        ObsDetection();
	

};
#endif
