// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from obstacle_msgs:msg/Area.idl
// generated code does not contain a copyright notice

#ifndef OBSTACLE_MSGS__MSG__DETAIL__AREA__STRUCT_HPP_
#define OBSTACLE_MSGS__MSG__DETAIL__AREA__STRUCT_HPP_

#include <algorithm>
#include <array>
#include <memory>
#include <string>
#include <vector>

#include "rosidl_runtime_cpp/bounded_vector.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


#ifndef _WIN32
# define DEPRECATED__obstacle_msgs__msg__Area __attribute__((deprecated))
#else
# define DEPRECATED__obstacle_msgs__msg__Area __declspec(deprecated)
#endif

namespace obstacle_msgs
{

namespace msg
{

// message struct
template<class ContainerAllocator>
struct Area_
{
  using Type = Area_<ContainerAllocator>;

  explicit Area_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->obstacle_area_status = 0;
      this->obstacle_distance = 0.0;
      this->obstacle_direction = 0;
      this->obstacle_length = 0.0;
      this->obstacle_lat_1 = 0.0;
      this->obstacle_long_1 = 0.0;
      this->obstacle_lat_2 = 0.0;
      this->obstacle_long_2 = 0.0;
    }
  }

  explicit Area_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    (void)_alloc;
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->obstacle_area_status = 0;
      this->obstacle_distance = 0.0;
      this->obstacle_direction = 0;
      this->obstacle_length = 0.0;
      this->obstacle_lat_1 = 0.0;
      this->obstacle_long_1 = 0.0;
      this->obstacle_lat_2 = 0.0;
      this->obstacle_long_2 = 0.0;
    }
  }

  // field types and members
  using _obstacle_area_status_type =
    int8_t;
  _obstacle_area_status_type obstacle_area_status;
  using _obstacle_distance_type =
    double;
  _obstacle_distance_type obstacle_distance;
  using _obstacle_direction_type =
    int8_t;
  _obstacle_direction_type obstacle_direction;
  using _obstacle_length_type =
    double;
  _obstacle_length_type obstacle_length;
  using _obstacle_lat_1_type =
    double;
  _obstacle_lat_1_type obstacle_lat_1;
  using _obstacle_long_1_type =
    double;
  _obstacle_long_1_type obstacle_long_1;
  using _obstacle_lat_2_type =
    double;
  _obstacle_lat_2_type obstacle_lat_2;
  using _obstacle_long_2_type =
    double;
  _obstacle_long_2_type obstacle_long_2;

  // setters for named parameter idiom
  Type & set__obstacle_area_status(
    const int8_t & _arg)
  {
    this->obstacle_area_status = _arg;
    return *this;
  }
  Type & set__obstacle_distance(
    const double & _arg)
  {
    this->obstacle_distance = _arg;
    return *this;
  }
  Type & set__obstacle_direction(
    const int8_t & _arg)
  {
    this->obstacle_direction = _arg;
    return *this;
  }
  Type & set__obstacle_length(
    const double & _arg)
  {
    this->obstacle_length = _arg;
    return *this;
  }
  Type & set__obstacle_lat_1(
    const double & _arg)
  {
    this->obstacle_lat_1 = _arg;
    return *this;
  }
  Type & set__obstacle_long_1(
    const double & _arg)
  {
    this->obstacle_long_1 = _arg;
    return *this;
  }
  Type & set__obstacle_lat_2(
    const double & _arg)
  {
    this->obstacle_lat_2 = _arg;
    return *this;
  }
  Type & set__obstacle_long_2(
    const double & _arg)
  {
    this->obstacle_long_2 = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    obstacle_msgs::msg::Area_<ContainerAllocator> *;
  using ConstRawPtr =
    const obstacle_msgs::msg::Area_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<obstacle_msgs::msg::Area_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<obstacle_msgs::msg::Area_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      obstacle_msgs::msg::Area_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<obstacle_msgs::msg::Area_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      obstacle_msgs::msg::Area_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<obstacle_msgs::msg::Area_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<obstacle_msgs::msg::Area_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<obstacle_msgs::msg::Area_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__obstacle_msgs__msg__Area
    std::shared_ptr<obstacle_msgs::msg::Area_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__obstacle_msgs__msg__Area
    std::shared_ptr<obstacle_msgs::msg::Area_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const Area_ & other) const
  {
    if (this->obstacle_area_status != other.obstacle_area_status) {
      return false;
    }
    if (this->obstacle_distance != other.obstacle_distance) {
      return false;
    }
    if (this->obstacle_direction != other.obstacle_direction) {
      return false;
    }
    if (this->obstacle_length != other.obstacle_length) {
      return false;
    }
    if (this->obstacle_lat_1 != other.obstacle_lat_1) {
      return false;
    }
    if (this->obstacle_long_1 != other.obstacle_long_1) {
      return false;
    }
    if (this->obstacle_lat_2 != other.obstacle_lat_2) {
      return false;
    }
    if (this->obstacle_long_2 != other.obstacle_long_2) {
      return false;
    }
    return true;
  }
  bool operator!=(const Area_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct Area_

// alias to use template instance with default allocator
using Area =
  obstacle_msgs::msg::Area_<std::allocator<void>>;

// constant definitions

}  // namespace msg

}  // namespace obstacle_msgs

#endif  // OBSTACLE_MSGS__MSG__DETAIL__AREA__STRUCT_HPP_
