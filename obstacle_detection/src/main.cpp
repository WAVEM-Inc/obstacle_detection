#include"obstacle_detection.hpp"
int main(int argc, char ** argv){
    rclcpp::init(argc, argv);
    rclcpp::spin(std::make_shared<ObsDetection>());
    rclcpp::shutdown();
    return 0;
}
