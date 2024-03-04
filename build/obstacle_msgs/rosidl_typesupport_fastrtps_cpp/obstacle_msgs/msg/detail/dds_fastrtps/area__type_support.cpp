// generated from rosidl_typesupport_fastrtps_cpp/resource/idl__type_support.cpp.em
// with input from obstacle_msgs:msg/Area.idl
// generated code does not contain a copyright notice
#include "obstacle_msgs/msg/detail/area__rosidl_typesupport_fastrtps_cpp.hpp"
#include "obstacle_msgs/msg/detail/area__struct.hpp"

#include <limits>
#include <stdexcept>
#include <string>
#include "rosidl_typesupport_cpp/message_type_support.hpp"
#include "rosidl_typesupport_fastrtps_cpp/identifier.hpp"
#include "rosidl_typesupport_fastrtps_cpp/message_type_support.h"
#include "rosidl_typesupport_fastrtps_cpp/message_type_support_decl.hpp"
#include "rosidl_typesupport_fastrtps_cpp/wstring_conversion.hpp"
#include "fastcdr/Cdr.h"


// forward declaration of message dependencies and their conversion functions

namespace obstacle_msgs
{

namespace msg
{

namespace typesupport_fastrtps_cpp
{

bool
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_obstacle_msgs
cdr_serialize(
  const obstacle_msgs::msg::Area & ros_message,
  eprosima::fastcdr::Cdr & cdr)
{
  // Member: obstacle_status
  cdr << ros_message.obstacle_status;
  // Member: obstacle_value
  cdr << (ros_message.obstacle_value ? true : false);
  // Member: obstacle_distance
  cdr << ros_message.obstacle_distance;
  return true;
}

bool
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_obstacle_msgs
cdr_deserialize(
  eprosima::fastcdr::Cdr & cdr,
  obstacle_msgs::msg::Area & ros_message)
{
  // Member: obstacle_status
  cdr >> ros_message.obstacle_status;

  // Member: obstacle_value
  {
    uint8_t tmp;
    cdr >> tmp;
    ros_message.obstacle_value = tmp ? true : false;
  }

  // Member: obstacle_distance
  cdr >> ros_message.obstacle_distance;

  return true;
}

size_t
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_obstacle_msgs
get_serialized_size(
  const obstacle_msgs::msg::Area & ros_message,
  size_t current_alignment)
{
  size_t initial_alignment = current_alignment;

  const size_t padding = 4;
  const size_t wchar_size = 4;
  (void)padding;
  (void)wchar_size;

  // Member: obstacle_status
  {
    size_t item_size = sizeof(ros_message.obstacle_status);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // Member: obstacle_value
  {
    size_t item_size = sizeof(ros_message.obstacle_value);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // Member: obstacle_distance
  {
    size_t item_size = sizeof(ros_message.obstacle_distance);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  return current_alignment - initial_alignment;
}

size_t
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_obstacle_msgs
max_serialized_size_Area(
  bool & full_bounded,
  bool & is_plain,
  size_t current_alignment)
{
  size_t initial_alignment = current_alignment;

  const size_t padding = 4;
  const size_t wchar_size = 4;
  size_t last_member_size = 0;
  (void)last_member_size;
  (void)padding;
  (void)wchar_size;

  full_bounded = true;
  is_plain = true;


  // Member: obstacle_status
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint8_t);
    current_alignment += array_size * sizeof(uint8_t);
  }

  // Member: obstacle_value
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint8_t);
    current_alignment += array_size * sizeof(uint8_t);
  }

  // Member: obstacle_distance
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint64_t);
    current_alignment += array_size * sizeof(uint64_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint64_t));
  }

  size_t ret_val = current_alignment - initial_alignment;
  if (is_plain) {
    // All members are plain, and type is not empty.
    // We still need to check that the in-memory alignment
    // is the same as the CDR mandated alignment.
    using DataType = obstacle_msgs::msg::Area;
    is_plain =
      (
      offsetof(DataType, obstacle_distance) +
      last_member_size
      ) == ret_val;
  }

  return ret_val;
}

static bool _Area__cdr_serialize(
  const void * untyped_ros_message,
  eprosima::fastcdr::Cdr & cdr)
{
  auto typed_message =
    static_cast<const obstacle_msgs::msg::Area *>(
    untyped_ros_message);
  return cdr_serialize(*typed_message, cdr);
}

static bool _Area__cdr_deserialize(
  eprosima::fastcdr::Cdr & cdr,
  void * untyped_ros_message)
{
  auto typed_message =
    static_cast<obstacle_msgs::msg::Area *>(
    untyped_ros_message);
  return cdr_deserialize(cdr, *typed_message);
}

static uint32_t _Area__get_serialized_size(
  const void * untyped_ros_message)
{
  auto typed_message =
    static_cast<const obstacle_msgs::msg::Area *>(
    untyped_ros_message);
  return static_cast<uint32_t>(get_serialized_size(*typed_message, 0));
}

static size_t _Area__max_serialized_size(char & bounds_info)
{
  bool full_bounded;
  bool is_plain;
  size_t ret_val;

  ret_val = max_serialized_size_Area(full_bounded, is_plain, 0);

  bounds_info =
    is_plain ? ROSIDL_TYPESUPPORT_FASTRTPS_PLAIN_TYPE :
    full_bounded ? ROSIDL_TYPESUPPORT_FASTRTPS_BOUNDED_TYPE : ROSIDL_TYPESUPPORT_FASTRTPS_UNBOUNDED_TYPE;
  return ret_val;
}

static message_type_support_callbacks_t _Area__callbacks = {
  "obstacle_msgs::msg",
  "Area",
  _Area__cdr_serialize,
  _Area__cdr_deserialize,
  _Area__get_serialized_size,
  _Area__max_serialized_size
};

static rosidl_message_type_support_t _Area__handle = {
  rosidl_typesupport_fastrtps_cpp::typesupport_identifier,
  &_Area__callbacks,
  get_message_typesupport_handle_function,
};

}  // namespace typesupport_fastrtps_cpp

}  // namespace msg

}  // namespace obstacle_msgs

namespace rosidl_typesupport_fastrtps_cpp
{

template<>
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_EXPORT_obstacle_msgs
const rosidl_message_type_support_t *
get_message_type_support_handle<obstacle_msgs::msg::Area>()
{
  return &obstacle_msgs::msg::typesupport_fastrtps_cpp::_Area__handle;
}

}  // namespace rosidl_typesupport_fastrtps_cpp

#ifdef __cplusplus
extern "C"
{
#endif

const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_cpp, obstacle_msgs, msg, Area)() {
  return &obstacle_msgs::msg::typesupport_fastrtps_cpp::_Area__handle;
}

#ifdef __cplusplus
}
#endif
