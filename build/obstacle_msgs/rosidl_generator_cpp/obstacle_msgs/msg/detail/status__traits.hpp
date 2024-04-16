// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from obstacle_msgs:msg/Status.idl
// generated code does not contain a copyright notice

#ifndef OBSTACLE_MSGS__MSG__DETAIL__STATUS__TRAITS_HPP_
#define OBSTACLE_MSGS__MSG__DETAIL__STATUS__TRAITS_HPP_

#include <stdint.h>

#include <sstream>
#include <string>
#include <type_traits>

#include "obstacle_msgs/msg/detail/status__struct.hpp"
#include "rosidl_runtime_cpp/traits.hpp"

namespace obstacle_msgs
{

namespace msg
{

inline void to_flow_style_yaml(
  const Status & msg,
  std::ostream & out)
{
  out << "{";
  // member: obstacle_status
  {
    out << "obstacle_status: ";
    rosidl_generator_traits::value_to_yaml(msg.obstacle_status, out);
    out << ", ";
  }

  // member: obstacle_value
  {
    out << "obstacle_value: ";
    rosidl_generator_traits::value_to_yaml(msg.obstacle_value, out);
    out << ", ";
  }

  // member: obstacle_distance
  {
    out << "obstacle_distance: ";
    rosidl_generator_traits::value_to_yaml(msg.obstacle_distance, out);
    out << ", ";
  }

  // member: obstacle_id
  {
    out << "obstacle_id: ";
    rosidl_generator_traits::value_to_yaml(msg.obstacle_id, out);
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const Status & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: obstacle_status
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "obstacle_status: ";
    rosidl_generator_traits::value_to_yaml(msg.obstacle_status, out);
    out << "\n";
  }

  // member: obstacle_value
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "obstacle_value: ";
    rosidl_generator_traits::value_to_yaml(msg.obstacle_value, out);
    out << "\n";
  }

  // member: obstacle_distance
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "obstacle_distance: ";
    rosidl_generator_traits::value_to_yaml(msg.obstacle_distance, out);
    out << "\n";
  }

  // member: obstacle_id
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "obstacle_id: ";
    rosidl_generator_traits::value_to_yaml(msg.obstacle_id, out);
    out << "\n";
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const Status & msg, bool use_flow_style = false)
{
  std::ostringstream out;
  if (use_flow_style) {
    to_flow_style_yaml(msg, out);
  } else {
    to_block_style_yaml(msg, out);
  }
  return out.str();
}

}  // namespace msg

}  // namespace obstacle_msgs

namespace rosidl_generator_traits
{

[[deprecated("use obstacle_msgs::msg::to_block_style_yaml() instead")]]
inline void to_yaml(
  const obstacle_msgs::msg::Status & msg,
  std::ostream & out, size_t indentation = 0)
{
  obstacle_msgs::msg::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use obstacle_msgs::msg::to_yaml() instead")]]
inline std::string to_yaml(const obstacle_msgs::msg::Status & msg)
{
  return obstacle_msgs::msg::to_yaml(msg);
}

template<>
inline const char * data_type<obstacle_msgs::msg::Status>()
{
  return "obstacle_msgs::msg::Status";
}

template<>
inline const char * name<obstacle_msgs::msg::Status>()
{
  return "obstacle_msgs/msg/Status";
}

template<>
struct has_fixed_size<obstacle_msgs::msg::Status>
  : std::integral_constant<bool, false> {};

template<>
struct has_bounded_size<obstacle_msgs::msg::Status>
  : std::integral_constant<bool, false> {};

template<>
struct is_message<obstacle_msgs::msg::Status>
  : std::true_type {};

}  // namespace rosidl_generator_traits

#endif  // OBSTACLE_MSGS__MSG__DETAIL__STATUS__TRAITS_HPP_
