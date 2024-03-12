// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from obstacle_msgs:msg/Status.idl
// generated code does not contain a copyright notice

#ifndef OBSTACLE_MSGS__MSG__DETAIL__STATUS__BUILDER_HPP_
#define OBSTACLE_MSGS__MSG__DETAIL__STATUS__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "obstacle_msgs/msg/detail/status__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace obstacle_msgs
{

namespace msg
{

namespace builder
{

class Init_Status_obstacle_distance
{
public:
  explicit Init_Status_obstacle_distance(::obstacle_msgs::msg::Status & msg)
  : msg_(msg)
  {}
  ::obstacle_msgs::msg::Status obstacle_distance(::obstacle_msgs::msg::Status::_obstacle_distance_type arg)
  {
    msg_.obstacle_distance = std::move(arg);
    return std::move(msg_);
  }

private:
  ::obstacle_msgs::msg::Status msg_;
};

class Init_Status_obstacle_value
{
public:
  explicit Init_Status_obstacle_value(::obstacle_msgs::msg::Status & msg)
  : msg_(msg)
  {}
  Init_Status_obstacle_distance obstacle_value(::obstacle_msgs::msg::Status::_obstacle_value_type arg)
  {
    msg_.obstacle_value = std::move(arg);
    return Init_Status_obstacle_distance(msg_);
  }

private:
  ::obstacle_msgs::msg::Status msg_;
};

class Init_Status_obstacle_status
{
public:
  Init_Status_obstacle_status()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_Status_obstacle_value obstacle_status(::obstacle_msgs::msg::Status::_obstacle_status_type arg)
  {
    msg_.obstacle_status = std::move(arg);
    return Init_Status_obstacle_value(msg_);
  }

private:
  ::obstacle_msgs::msg::Status msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::obstacle_msgs::msg::Status>()
{
  return obstacle_msgs::msg::builder::Init_Status_obstacle_status();
}

}  // namespace obstacle_msgs

#endif  // OBSTACLE_MSGS__MSG__DETAIL__STATUS__BUILDER_HPP_
