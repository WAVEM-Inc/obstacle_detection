// generated from rosidl_generator_py/resource/_idl_support.c.em
// with input from obstacle_msgs:msg/Status.idl
// generated code does not contain a copyright notice
#define NPY_NO_DEPRECATED_API NPY_1_7_API_VERSION
#include <Python.h>
#include <stdbool.h>
#ifndef _WIN32
# pragma GCC diagnostic push
# pragma GCC diagnostic ignored "-Wunused-function"
#endif
#include "numpy/ndarrayobject.h"
#ifndef _WIN32
# pragma GCC diagnostic pop
#endif
#include "rosidl_runtime_c/visibility_control.h"
#include "obstacle_msgs/msg/detail/status__struct.h"
#include "obstacle_msgs/msg/detail/status__functions.h"


ROSIDL_GENERATOR_C_EXPORT
bool obstacle_msgs__msg__status__convert_from_py(PyObject * _pymsg, void * _ros_message)
{
  // check that the passed message is of the expected Python class
  {
    char full_classname_dest[33];
    {
      char * class_name = NULL;
      char * module_name = NULL;
      {
        PyObject * class_attr = PyObject_GetAttrString(_pymsg, "__class__");
        if (class_attr) {
          PyObject * name_attr = PyObject_GetAttrString(class_attr, "__name__");
          if (name_attr) {
            class_name = (char *)PyUnicode_1BYTE_DATA(name_attr);
            Py_DECREF(name_attr);
          }
          PyObject * module_attr = PyObject_GetAttrString(class_attr, "__module__");
          if (module_attr) {
            module_name = (char *)PyUnicode_1BYTE_DATA(module_attr);
            Py_DECREF(module_attr);
          }
          Py_DECREF(class_attr);
        }
      }
      if (!class_name || !module_name) {
        return false;
      }
      snprintf(full_classname_dest, sizeof(full_classname_dest), "%s.%s", module_name, class_name);
    }
    assert(strncmp("obstacle_msgs.msg._status.Status", full_classname_dest, 32) == 0);
  }
  obstacle_msgs__msg__Status * ros_message = _ros_message;
  {  // obstacle_area_status
    PyObject * field = PyObject_GetAttrString(_pymsg, "obstacle_area_status");
    if (!field) {
      return false;
    }
    assert(PyLong_Check(field));
    ros_message->obstacle_area_status = (int8_t)PyLong_AsLong(field);
    Py_DECREF(field);
  }
  {  // obstacle_distance
    PyObject * field = PyObject_GetAttrString(_pymsg, "obstacle_distance");
    if (!field) {
      return false;
    }
    assert(PyFloat_Check(field));
    ros_message->obstacle_distance = PyFloat_AS_DOUBLE(field);
    Py_DECREF(field);
  }
  {  // obstacle_direction
    PyObject * field = PyObject_GetAttrString(_pymsg, "obstacle_direction");
    if (!field) {
      return false;
    }
    assert(PyLong_Check(field));
    ros_message->obstacle_direction = (int8_t)PyLong_AsLong(field);
    Py_DECREF(field);
  }
  {  // obstacle_length
    PyObject * field = PyObject_GetAttrString(_pymsg, "obstacle_length");
    if (!field) {
      return false;
    }
    assert(PyFloat_Check(field));
    ros_message->obstacle_length = PyFloat_AS_DOUBLE(field);
    Py_DECREF(field);
  }

  return true;
}

ROSIDL_GENERATOR_C_EXPORT
PyObject * obstacle_msgs__msg__status__convert_to_py(void * raw_ros_message)
{
  /* NOTE(esteve): Call constructor of Status */
  PyObject * _pymessage = NULL;
  {
    PyObject * pymessage_module = PyImport_ImportModule("obstacle_msgs.msg._status");
    assert(pymessage_module);
    PyObject * pymessage_class = PyObject_GetAttrString(pymessage_module, "Status");
    assert(pymessage_class);
    Py_DECREF(pymessage_module);
    _pymessage = PyObject_CallObject(pymessage_class, NULL);
    Py_DECREF(pymessage_class);
    if (!_pymessage) {
      return NULL;
    }
  }
  obstacle_msgs__msg__Status * ros_message = (obstacle_msgs__msg__Status *)raw_ros_message;
  {  // obstacle_area_status
    PyObject * field = NULL;
    field = PyLong_FromLong(ros_message->obstacle_area_status);
    {
      int rc = PyObject_SetAttrString(_pymessage, "obstacle_area_status", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // obstacle_distance
    PyObject * field = NULL;
    field = PyFloat_FromDouble(ros_message->obstacle_distance);
    {
      int rc = PyObject_SetAttrString(_pymessage, "obstacle_distance", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // obstacle_direction
    PyObject * field = NULL;
    field = PyLong_FromLong(ros_message->obstacle_direction);
    {
      int rc = PyObject_SetAttrString(_pymessage, "obstacle_direction", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // obstacle_length
    PyObject * field = NULL;
    field = PyFloat_FromDouble(ros_message->obstacle_length);
    {
      int rc = PyObject_SetAttrString(_pymessage, "obstacle_length", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }

  // ownership of _pymessage is transferred to the caller
  return _pymessage;
}
