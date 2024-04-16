// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from obstacle_msgs:msg/Status.idl
// generated code does not contain a copyright notice

#ifndef OBSTACLE_MSGS__MSG__DETAIL__STATUS__STRUCT_HPP_
#define OBSTACLE_MSGS__MSG__DETAIL__STATUS__STRUCT_HPP_

#include <algorithm>
#include <array>
#include <memory>
#include <string>
#include <vector>

#include "rosidl_runtime_cpp/bounded_vector.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


#ifndef _WIN32
# define DEPRECATED__obstacle_msgs__msg__Status __attribute__((deprecated))
#else
# define DEPRECATED__obstacle_msgs__msg__Status __declspec(deprecated)
#endif

namespace obstacle_msgs
{

namespace msg
{

// message struct
template<class ContainerAllocator>
struct Status_
{
  using Type = Status_<ContainerAllocator>;

  explicit Status_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->obstacle_status = 0;
      this->obstacle_value = false;
      this->obstacle_distance = 0.0;
      this->obstacle_id = "";
    }
  }

  explicit Status_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : obstacle_id(_alloc)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->obstacle_status = 0;
      this->obstacle_value = false;
      this->obstacle_distance = 0.0;
      this->obstacle_id = "";
    }
  }

  // field types and members
  using _obstacle_status_type =
    int8_t;
  _obstacle_status_type obstacle_status;
  using _obstacle_value_type =
    bool;
  _obstacle_value_type obstacle_value;
  using _obstacle_distance_type =
    double;
  _obstacle_distance_type obstacle_distance;
  using _obstacle_id_type =
    std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>>;
  _obstacle_id_type obstacle_id;

  // setters for named parameter idiom
  Type & set__obstacle_status(
    const int8_t & _arg)
  {
    this->obstacle_status = _arg;
    return *this;
  }
  Type & set__obstacle_value(
    const bool & _arg)
  {
    this->obstacle_value = _arg;
    return *this;
  }
  Type & set__obstacle_distance(
    const double & _arg)
  {
    this->obstacle_distance = _arg;
    return *this;
  }
  Type & set__obstacle_id(
    const std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>> & _arg)
  {
    this->obstacle_id = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    obstacle_msgs::msg::Status_<ContainerAllocator> *;
  using ConstRawPtr =
    const obstacle_msgs::msg::Status_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<obstacle_msgs::msg::Status_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<obstacle_msgs::msg::Status_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      obstacle_msgs::msg::Status_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<obstacle_msgs::msg::Status_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      obstacle_msgs::msg::Status_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<obstacle_msgs::msg::Status_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<obstacle_msgs::msg::Status_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<obstacle_msgs::msg::Status_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__obstacle_msgs__msg__Status
    std::shared_ptr<obstacle_msgs::msg::Status_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__obstacle_msgs__msg__Status
    std::shared_ptr<obstacle_msgs::msg::Status_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const Status_ & other) const
  {
    if (this->obstacle_status != other.obstacle_status) {
      return false;
    }
    if (this->obstacle_value != other.obstacle_value) {
      return false;
    }
    if (this->obstacle_distance != other.obstacle_distance) {
      return false;
    }
    if (this->obstacle_id != other.obstacle_id) {
      return false;
    }
    return true;
  }
  bool operator!=(const Status_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct Status_

// alias to use template instance with default allocator
using Status =
  obstacle_msgs::msg::Status_<std::allocator<void>>;

// constant definitions

}  // namespace msg

}  // namespace obstacle_msgs

#endif  // OBSTACLE_MSGS__MSG__DETAIL__STATUS__STRUCT_HPP_
