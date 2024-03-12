// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from obstacle_msgs:msg/Area.idl
// generated code does not contain a copyright notice

#ifndef OBSTACLE_MSGS__MSG__DETAIL__AREA__TRAITS_HPP_
#define OBSTACLE_MSGS__MSG__DETAIL__AREA__TRAITS_HPP_

#include <stdint.h>

#include <sstream>
#include <string>
#include <type_traits>

#include "obstacle_msgs/msg/detail/area__struct.hpp"
#include "rosidl_runtime_cpp/traits.hpp"

namespace obstacle_msgs
{

namespace msg
{

inline void to_flow_style_yaml(
  const Area & msg,
  std::ostream & out)
{
  out << "{";
  // member: obstacle_area_status
  {
    out << "obstacle_area_status: ";
    rosidl_generator_traits::value_to_yaml(msg.obstacle_area_status, out);
    out << ", ";
  }

  // member: obstacle_distance
  {
    out << "obstacle_distance: ";
    rosidl_generator_traits::value_to_yaml(msg.obstacle_distance, out);
    out << ", ";
  }

  // member: obstacle_direction
  {
    out << "obstacle_direction: ";
    rosidl_generator_traits::value_to_yaml(msg.obstacle_direction, out);
    out << ", ";
  }

  // member: obstacle_length
  {
    out << "obstacle_length: ";
    rosidl_generator_traits::value_to_yaml(msg.obstacle_length, out);
    out << ", ";
  }

  // member: obstacle_lat_1
  {
    out << "obstacle_lat_1: ";
    rosidl_generator_traits::value_to_yaml(msg.obstacle_lat_1, out);
    out << ", ";
  }

  // member: obstacle_long_1
  {
    out << "obstacle_long_1: ";
    rosidl_generator_traits::value_to_yaml(msg.obstacle_long_1, out);
    out << ", ";
  }

  // member: obstacle_lat_2
  {
    out << "obstacle_lat_2: ";
    rosidl_generator_traits::value_to_yaml(msg.obstacle_lat_2, out);
    out << ", ";
  }

  // member: obstacle_long_2
  {
    out << "obstacle_long_2: ";
    rosidl_generator_traits::value_to_yaml(msg.obstacle_long_2, out);
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const Area & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: obstacle_area_status
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "obstacle_area_status: ";
    rosidl_generator_traits::value_to_yaml(msg.obstacle_area_status, out);
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

  // member: obstacle_direction
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "obstacle_direction: ";
    rosidl_generator_traits::value_to_yaml(msg.obstacle_direction, out);
    out << "\n";
  }

  // member: obstacle_length
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "obstacle_length: ";
    rosidl_generator_traits::value_to_yaml(msg.obstacle_length, out);
    out << "\n";
  }

  // member: obstacle_lat_1
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "obstacle_lat_1: ";
    rosidl_generator_traits::value_to_yaml(msg.obstacle_lat_1, out);
    out << "\n";
  }

  // member: obstacle_long_1
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "obstacle_long_1: ";
    rosidl_generator_traits::value_to_yaml(msg.obstacle_long_1, out);
    out << "\n";
  }

  // member: obstacle_lat_2
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "obstacle_lat_2: ";
    rosidl_generator_traits::value_to_yaml(msg.obstacle_lat_2, out);
    out << "\n";
  }

  // member: obstacle_long_2
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "obstacle_long_2: ";
    rosidl_generator_traits::value_to_yaml(msg.obstacle_long_2, out);
    out << "\n";
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const Area & msg, bool use_flow_style = false)
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
  const obstacle_msgs::msg::Area & msg,
  std::ostream & out, size_t indentation = 0)
{
  obstacle_msgs::msg::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use obstacle_msgs::msg::to_yaml() instead")]]
inline std::string to_yaml(const obstacle_msgs::msg::Area & msg)
{
  return obstacle_msgs::msg::to_yaml(msg);
}

template<>
inline const char * data_type<obstacle_msgs::msg::Area>()
{
  return "obstacle_msgs::msg::Area";
}

template<>
inline const char * name<obstacle_msgs::msg::Area>()
{
  return "obstacle_msgs/msg/Area";
}

template<>
struct has_fixed_size<obstacle_msgs::msg::Area>
  : std::integral_constant<bool, true> {};

template<>
struct has_bounded_size<obstacle_msgs::msg::Area>
  : std::integral_constant<bool, true> {};

template<>
struct is_message<obstacle_msgs::msg::Area>
  : std::true_type {};

}  // namespace rosidl_generator_traits

#endif  // OBSTACLE_MSGS__MSG__DETAIL__AREA__TRAITS_HPP_
