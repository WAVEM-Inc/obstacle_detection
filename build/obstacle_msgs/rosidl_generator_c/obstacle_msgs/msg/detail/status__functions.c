// generated from rosidl_generator_c/resource/idl__functions.c.em
// with input from obstacle_msgs:msg/Status.idl
// generated code does not contain a copyright notice
#include "obstacle_msgs/msg/detail/status__functions.h"

#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#include "rcutils/allocator.h"


// Include directives for member types
// Member `obstacle_id`
#include "rosidl_runtime_c/string_functions.h"

bool
obstacle_msgs__msg__Status__init(obstacle_msgs__msg__Status * msg)
{
  if (!msg) {
    return false;
  }
  // obstacle_status
  // obstacle_value
  // obstacle_distance
  // obstacle_id
  if (!rosidl_runtime_c__String__init(&msg->obstacle_id)) {
    obstacle_msgs__msg__Status__fini(msg);
    return false;
  }
  return true;
}

void
obstacle_msgs__msg__Status__fini(obstacle_msgs__msg__Status * msg)
{
  if (!msg) {
    return;
  }
  // obstacle_status
  // obstacle_value
  // obstacle_distance
  // obstacle_id
  rosidl_runtime_c__String__fini(&msg->obstacle_id);
}

bool
obstacle_msgs__msg__Status__are_equal(const obstacle_msgs__msg__Status * lhs, const obstacle_msgs__msg__Status * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // obstacle_status
  if (lhs->obstacle_status != rhs->obstacle_status) {
    return false;
  }
  // obstacle_value
  if (lhs->obstacle_value != rhs->obstacle_value) {
    return false;
  }
  // obstacle_distance
  if (lhs->obstacle_distance != rhs->obstacle_distance) {
    return false;
  }
  // obstacle_id
  if (!rosidl_runtime_c__String__are_equal(
      &(lhs->obstacle_id), &(rhs->obstacle_id)))
  {
    return false;
  }
  return true;
}

bool
obstacle_msgs__msg__Status__copy(
  const obstacle_msgs__msg__Status * input,
  obstacle_msgs__msg__Status * output)
{
  if (!input || !output) {
    return false;
  }
  // obstacle_status
  output->obstacle_status = input->obstacle_status;
  // obstacle_value
  output->obstacle_value = input->obstacle_value;
  // obstacle_distance
  output->obstacle_distance = input->obstacle_distance;
  // obstacle_id
  if (!rosidl_runtime_c__String__copy(
      &(input->obstacle_id), &(output->obstacle_id)))
  {
    return false;
  }
  return true;
}

obstacle_msgs__msg__Status *
obstacle_msgs__msg__Status__create()
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  obstacle_msgs__msg__Status * msg = (obstacle_msgs__msg__Status *)allocator.allocate(sizeof(obstacle_msgs__msg__Status), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(obstacle_msgs__msg__Status));
  bool success = obstacle_msgs__msg__Status__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
obstacle_msgs__msg__Status__destroy(obstacle_msgs__msg__Status * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    obstacle_msgs__msg__Status__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
obstacle_msgs__msg__Status__Sequence__init(obstacle_msgs__msg__Status__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  obstacle_msgs__msg__Status * data = NULL;

  if (size) {
    data = (obstacle_msgs__msg__Status *)allocator.zero_allocate(size, sizeof(obstacle_msgs__msg__Status), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = obstacle_msgs__msg__Status__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        obstacle_msgs__msg__Status__fini(&data[i - 1]);
      }
      allocator.deallocate(data, allocator.state);
      return false;
    }
  }
  array->data = data;
  array->size = size;
  array->capacity = size;
  return true;
}

void
obstacle_msgs__msg__Status__Sequence__fini(obstacle_msgs__msg__Status__Sequence * array)
{
  if (!array) {
    return;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();

  if (array->data) {
    // ensure that data and capacity values are consistent
    assert(array->capacity > 0);
    // finalize all array elements
    for (size_t i = 0; i < array->capacity; ++i) {
      obstacle_msgs__msg__Status__fini(&array->data[i]);
    }
    allocator.deallocate(array->data, allocator.state);
    array->data = NULL;
    array->size = 0;
    array->capacity = 0;
  } else {
    // ensure that data, size, and capacity values are consistent
    assert(0 == array->size);
    assert(0 == array->capacity);
  }
}

obstacle_msgs__msg__Status__Sequence *
obstacle_msgs__msg__Status__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  obstacle_msgs__msg__Status__Sequence * array = (obstacle_msgs__msg__Status__Sequence *)allocator.allocate(sizeof(obstacle_msgs__msg__Status__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = obstacle_msgs__msg__Status__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
obstacle_msgs__msg__Status__Sequence__destroy(obstacle_msgs__msg__Status__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    obstacle_msgs__msg__Status__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
obstacle_msgs__msg__Status__Sequence__are_equal(const obstacle_msgs__msg__Status__Sequence * lhs, const obstacle_msgs__msg__Status__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!obstacle_msgs__msg__Status__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
obstacle_msgs__msg__Status__Sequence__copy(
  const obstacle_msgs__msg__Status__Sequence * input,
  obstacle_msgs__msg__Status__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(obstacle_msgs__msg__Status);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    obstacle_msgs__msg__Status * data =
      (obstacle_msgs__msg__Status *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!obstacle_msgs__msg__Status__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          obstacle_msgs__msg__Status__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!obstacle_msgs__msg__Status__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}
