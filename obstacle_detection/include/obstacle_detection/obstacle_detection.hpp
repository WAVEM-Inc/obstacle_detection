#ifndef VEL_BYPASS_LISTENER_HPP__
#define VEL_BYPASS_LISTENER_HPP__

#define DETECT_SIZE 10
#define DETECT_RES 20

#include <iostream>
#include <fstream>
#include <fcntl.h>
#include "rclcpp/rclcpp.hpp"
#include "sensor_msgs/msg/laser_scan.hpp"
#include <unistd.h>
using LidarMSG = sensor_msgs::msg::LaserScan ;
class ObsDetection : public rclcpp::Node{
    private :
        rclcpp::Subscription<LidarMSG>::SharedPtr sub_scan_;
        void scan_callback(const std::shared_ptr<LidarMSG> scan);
    public :
        ObsDetection();
	

};
#endif
