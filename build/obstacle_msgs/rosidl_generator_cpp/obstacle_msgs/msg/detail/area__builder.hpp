// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from obstacle_msgs:msg/Area.idl
// generated code does not contain a copyright notice

#ifndef OBSTACLE_MSGS__MSG__DETAIL__AREA__BUILDER_HPP_
#define OBSTACLE_MSGS__MSG__DETAIL__AREA__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "obstacle_msgs/msg/detail/area__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace obstacle_msgs
{

namespace msg
{

namespace builder
{

class Init_Area_obstacle_long_2
{
public:
  explicit Init_Area_obstacle_long_2(::obstacle_msgs::msg::Area & msg)
  : msg_(msg)
  {}
  ::obstacle_msgs::msg::Area obstacle_long_2(::obstacle_msgs::msg::Area::_obstacle_long_2_type arg)
  {
    msg_.obstacle_long_2 = std::move(arg);
    return std::move(msg_);
  }

private:
  ::obstacle_msgs::msg::Area msg_;
};

class Init_Area_obstacle_lat_2
{
public:
  explicit Init_Area_obstacle_lat_2(::obstacle_msgs::msg::Area & msg)
  : msg_(msg)
  {}
  Init_Area_obstacle_long_2 obstacle_lat_2(::obstacle_msgs::msg::Area::_obstacle_lat_2_type arg)
  {
    msg_.obstacle_lat_2 = std::move(arg);
    return Init_Area_obstacle_long_2(msg_);
  }

private:
  ::obstacle_msgs::msg::Area msg_;
};

class Init_Area_obstacle_long_1
{
public:
  explicit Init_Area_obstacle_long_1(::obstacle_msgs::msg::Area & msg)
  : msg_(msg)
  {}
  Init_Area_obstacle_lat_2 obstacle_long_1(::obstacle_msgs::msg::Area::_obstacle_long_1_type arg)
  {
    msg_.obstacle_long_1 = std::move(arg);
    return Init_Area_obstacle_lat_2(msg_);
  }

private:
  ::obstacle_msgs::msg::Area msg_;
};

class Init_Area_obstacle_lat_1
{
public:
  explicit Init_Area_obstacle_lat_1(::obstacle_msgs::msg::Area & msg)
  : msg_(msg)
  {}
  Init_Area_obstacle_long_1 obstacle_lat_1(::obstacle_msgs::msg::Area::_obstacle_lat_1_type arg)
  {
    msg_.obstacle_lat_1 = std::move(arg);
    return Init_Area_obstacle_long_1(msg_);
  }

private:
  ::obstacle_msgs::msg::Area msg_;
};

class Init_Area_obstacle_length
{
public:
  explicit Init_Area_obstacle_length(::obstacle_msgs::msg::Area & msg)
  : msg_(msg)
  {}
  Init_Area_obstacle_lat_1 obstacle_length(::obstacle_msgs::msg::Area::_obstacle_length_type arg)
  {
    msg_.obstacle_length = std::move(arg);
    return Init_Area_obstacle_lat_1(msg_);
  }

private:
  ::obstacle_msgs::msg::Area msg_;
};

class Init_Area_obstacle_direction
{
public:
  explicit Init_Area_obstacle_direction(::obstacle_msgs::msg::Area & msg)
  : msg_(msg)
  {}
  Init_Area_obstacle_length obstacle_direction(::obstacle_msgs::msg::Area::_obstacle_direction_type arg)
  {
    msg_.obstacle_direction = std::move(arg);
    return Init_Area_obstacle_length(msg_);
  }

private:
  ::obstacle_msgs::msg::Area msg_;
};

class Init_Area_obstacle_distance
{
public:
  explicit Init_Area_obstacle_distance(::obstacle_msgs::msg::Area & msg)
  : msg_(msg)
  {}
  Init_Area_obstacle_direction obstacle_distance(::obstacle_msgs::msg::Area::_obstacle_distance_type arg)
  {
    msg_.obstacle_distance = std::move(arg);
    return Init_Area_obstacle_direction(msg_);
  }

private:
  ::obstacle_msgs::msg::Area msg_;
};

class Init_Area_obstacle_area_status
{
public:
  Init_Area_obstacle_area_status()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_Area_obstacle_distance obstacle_area_status(::obstacle_msgs::msg::Area::_obstacle_area_status_type arg)
  {
    msg_.obstacle_area_status = std::move(arg);
    return Init_Area_obstacle_distance(msg_);
  }

private:
  ::obstacle_msgs::msg::Area msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::obstacle_msgs::msg::Area>()
{
  return obstacle_msgs::msg::builder::Init_Area_obstacle_area_status();
}

}  // namespace obstacle_msgs

#endif  // OBSTACLE_MSGS__MSG__DETAIL__AREA__BUILDER_HPP_
