// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from obstacle_msgs:msg/Status.idl
// generated code does not contain a copyright notice

#ifndef OBSTACLE_MSGS__MSG__DETAIL__STATUS__STRUCT_H_
#define OBSTACLE_MSGS__MSG__DETAIL__STATUS__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


// Constants defined in the message

// Include directives for member types
// Member 'obstacle_id'
#include "rosidl_runtime_c/string.h"

/// Struct defined in msg/Status in the package obstacle_msgs.
typedef struct obstacle_msgs__msg__Status
{
  int8_t obstacle_status;
  bool obstacle_value;
  double obstacle_distance;
  rosidl_runtime_c__String obstacle_id;
} obstacle_msgs__msg__Status;

// Struct for a sequence of obstacle_msgs__msg__Status.
typedef struct obstacle_msgs__msg__Status__Sequence
{
  obstacle_msgs__msg__Status * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} obstacle_msgs__msg__Status__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // OBSTACLE_MSGS__MSG__DETAIL__STATUS__STRUCT_H_
