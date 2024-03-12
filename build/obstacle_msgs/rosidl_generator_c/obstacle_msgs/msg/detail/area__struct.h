// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from obstacle_msgs:msg/Area.idl
// generated code does not contain a copyright notice

#ifndef OBSTACLE_MSGS__MSG__DETAIL__AREA__STRUCT_H_
#define OBSTACLE_MSGS__MSG__DETAIL__AREA__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


// Constants defined in the message

/// Struct defined in msg/Area in the package obstacle_msgs.
typedef struct obstacle_msgs__msg__Area
{
  int8_t obstacle_area_status;
  double obstacle_distance;
  int8_t obstacle_direction;
  double obstacle_length;
  double obstacle_lat_1;
  double obstacle_long_1;
  double obstacle_lat_2;
  double obstacle_long_2;
} obstacle_msgs__msg__Area;

// Struct for a sequence of obstacle_msgs__msg__Area.
typedef struct obstacle_msgs__msg__Area__Sequence
{
  obstacle_msgs__msg__Area * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} obstacle_msgs__msg__Area__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // OBSTACLE_MSGS__MSG__DETAIL__AREA__STRUCT_H_
