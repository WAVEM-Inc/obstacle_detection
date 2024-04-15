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

#include "rosidl_runtime_c/string.h"
#include "rosidl_runtime_c/string_functions.h"


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
  {  // obstacle_status
    PyObject * field = PyObject_GetAttrString(_pymsg, "obstacle_status");
    if (!field) {
      return false;
    }
    assert(PyLong_Check(field));
    ros_message->obstacle_status = (int8_t)PyLong_AsLong(field);
    Py_DECREF(field);
  }
  {  // obstacle_type
    PyObject * field = PyObject_GetAttrString(_pymsg, "obstacle_type");
    if (!field) {
      return false;
    }
    assert(PyLong_Check(field));
    ros_message->obstacle_type = (int8_t)PyLong_AsLong(field);
    Py_DECREF(field);
  }
  {  // obstacle_value
    PyObject * field = PyObject_GetAttrString(_pymsg, "obstacle_value");
    if (!field) {
      return false;
    }
    assert(PyBool_Check(field));
    ros_message->obstacle_value = (Py_True == field);
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
  {  // obstacle_id
    PyObject * field = PyObject_GetAttrString(_pymsg, "obstacle_id");
    if (!field) {
      return false;
    }
    assert(PyUnicode_Check(field));
    PyObject * encoded_field = PyUnicode_AsUTF8String(field);
    if (!encoded_field) {
      Py_DECREF(field);
      return false;
    }
    rosidl_runtime_c__String__assign(&ros_message->obstacle_id, PyBytes_AS_STRING(encoded_field));
    Py_DECREF(encoded_field);
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
  {  // obstacle_status
    PyObject * field = NULL;
    field = PyLong_FromLong(ros_message->obstacle_status);
    {
      int rc = PyObject_SetAttrString(_pymessage, "obstacle_status", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // obstacle_type
    PyObject * field = NULL;
    field = PyLong_FromLong(ros_message->obstacle_type);
    {
      int rc = PyObject_SetAttrString(_pymessage, "obstacle_type", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // obstacle_value
    PyObject * field = NULL;
    field = PyBool_FromLong(ros_message->obstacle_value ? 1 : 0);
    {
      int rc = PyObject_SetAttrString(_pymessage, "obstacle_value", field);
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
  {  // obstacle_id
    PyObject * field = NULL;
    field = PyUnicode_DecodeUTF8(
      ros_message->obstacle_id.data,
      strlen(ros_message->obstacle_id.data),
      "replace");
    if (!field) {
      return NULL;
    }
    {
      int rc = PyObject_SetAttrString(_pymessage, "obstacle_id", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }

  // ownership of _pymessage is transferred to the caller
  return _pymessage;
}
