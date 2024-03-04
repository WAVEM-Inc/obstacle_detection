// generated from rosidl_generator_py/resource/_idl_support.c.em
// with input from obstacle_msgs:msg/Area.idl
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
#include "obstacle_msgs/msg/detail/area__struct.h"
#include "obstacle_msgs/msg/detail/area__functions.h"


ROSIDL_GENERATOR_C_EXPORT
bool obstacle_msgs__msg__area__convert_from_py(PyObject * _pymsg, void * _ros_message)
{
  // check that the passed message is of the expected Python class
  {
    char full_classname_dest[29];
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
    assert(strncmp("obstacle_msgs.msg._area.Area", full_classname_dest, 28) == 0);
  }
  obstacle_msgs__msg__Area * ros_message = _ros_message;
  {  // obstacle_status
    PyObject * field = PyObject_GetAttrString(_pymsg, "obstacle_status");
    if (!field) {
      return false;
    }
    assert(PyLong_Check(field));
    ros_message->obstacle_status = (int8_t)PyLong_AsLong(field);
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

  return true;
}

ROSIDL_GENERATOR_C_EXPORT
PyObject * obstacle_msgs__msg__area__convert_to_py(void * raw_ros_message)
{
  /* NOTE(esteve): Call constructor of Area */
  PyObject * _pymessage = NULL;
  {
    PyObject * pymessage_module = PyImport_ImportModule("obstacle_msgs.msg._area");
    assert(pymessage_module);
    PyObject * pymessage_class = PyObject_GetAttrString(pymessage_module, "Area");
    assert(pymessage_class);
    Py_DECREF(pymessage_module);
    _pymessage = PyObject_CallObject(pymessage_class, NULL);
    Py_DECREF(pymessage_class);
    if (!_pymessage) {
      return NULL;
    }
  }
  obstacle_msgs__msg__Area * ros_message = (obstacle_msgs__msg__Area *)raw_ros_message;
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

  // ownership of _pymessage is transferred to the caller
  return _pymessage;
}
