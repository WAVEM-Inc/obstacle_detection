cmake_minimum_required(VERSION 3.8)
project(obstacle_detection)

if(CMAKE_COMPILER_IS_GNUCXX OR CMAKE_CXX_COMPILER_ID MATCHES "Clang")
  add_compile_options(-Wall -Wextra -Wpedantic)
endif()

# find dependencies
find_package(ament_cmake REQUIRED)
find_package(sensor_msgs REQUIRED)
find_package(nav_msgs REQUIRED)
find_package(obstacle_msgs REQUIRED)
find_package(rclcpp REQUIRED)
include_directories(
  include
  include/${PROJECT_NAME}
  #${EXTERNAL_INCLUDE_DIRS}
)

set(source_set
  src/main.cpp 
  src/obstacle_detection.cpp
)

set(dependencies 
  rclcpp
  sensor_msgs
  nav_msgs
  obstacle_msgs
)

set(node_name
  obstacle_detection_node
)

add_executable(${node_name}
  ${source_set}
)

ament_target_dependencies(${node_name}
  ${dependencies}
)

install(TARGETS
  ${node_name}
  DESTINATION lib/${PROJECT_NAME}
)

ament_package()
