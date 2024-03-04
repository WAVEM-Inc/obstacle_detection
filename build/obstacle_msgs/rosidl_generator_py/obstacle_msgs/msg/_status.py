# generated from rosidl_generator_py/resource/_idl.py.em
# with input from obstacle_msgs:msg/Status.idl
# generated code does not contain a copyright notice


# Import statements for member types

import builtins  # noqa: E402, I100

import math  # noqa: E402, I100

import rosidl_parser.definition  # noqa: E402, I100


class Metaclass_Status(type):
    """Metaclass of message 'Status'."""

    _CREATE_ROS_MESSAGE = None
    _CONVERT_FROM_PY = None
    _CONVERT_TO_PY = None
    _DESTROY_ROS_MESSAGE = None
    _TYPE_SUPPORT = None

    __constants = {
    }

    @classmethod
    def __import_type_support__(cls):
        try:
            from rosidl_generator_py import import_type_support
            module = import_type_support('obstacle_msgs')
        except ImportError:
            import logging
            import traceback
            logger = logging.getLogger(
                'obstacle_msgs.msg.Status')
            logger.debug(
                'Failed to import needed modules for type support:\n' +
                traceback.format_exc())
        else:
            cls._CREATE_ROS_MESSAGE = module.create_ros_message_msg__msg__status
            cls._CONVERT_FROM_PY = module.convert_from_py_msg__msg__status
            cls._CONVERT_TO_PY = module.convert_to_py_msg__msg__status
            cls._TYPE_SUPPORT = module.type_support_msg__msg__status
            cls._DESTROY_ROS_MESSAGE = module.destroy_ros_message_msg__msg__status

    @classmethod
    def __prepare__(cls, name, bases, **kwargs):
        # list constant names here so that they appear in the help text of
        # the message class under "Data and other attributes defined here:"
        # as well as populate each message instance
        return {
        }


class Status(metaclass=Metaclass_Status):
    """Message class 'Status'."""

    __slots__ = [
        '_obstacle_area_status',
        '_obstacle_distance',
        '_obstacle_direction',
        '_obstacle_length',
    ]

    _fields_and_field_types = {
        'obstacle_area_status': 'int8',
        'obstacle_distance': 'double',
        'obstacle_direction': 'int8',
        'obstacle_length': 'double',
    }

    SLOT_TYPES = (
        rosidl_parser.definition.BasicType('int8'),  # noqa: E501
        rosidl_parser.definition.BasicType('double'),  # noqa: E501
        rosidl_parser.definition.BasicType('int8'),  # noqa: E501
        rosidl_parser.definition.BasicType('double'),  # noqa: E501
    )

    def __init__(self, **kwargs):
        assert all('_' + key in self.__slots__ for key in kwargs.keys()), \
            'Invalid arguments passed to constructor: %s' % \
            ', '.join(sorted(k for k in kwargs.keys() if '_' + k not in self.__slots__))
        self.obstacle_area_status = kwargs.get('obstacle_area_status', int())
        self.obstacle_distance = kwargs.get('obstacle_distance', float())
        self.obstacle_direction = kwargs.get('obstacle_direction', int())
        self.obstacle_length = kwargs.get('obstacle_length', float())

    def __repr__(self):
        typename = self.__class__.__module__.split('.')
        typename.pop()
        typename.append(self.__class__.__name__)
        args = []
        for s, t in zip(self.__slots__, self.SLOT_TYPES):
            field = getattr(self, s)
            fieldstr = repr(field)
            # We use Python array type for fields that can be directly stored
            # in them, and "normal" sequences for everything else.  If it is
            # a type that we store in an array, strip off the 'array' portion.
            if (
                isinstance(t, rosidl_parser.definition.AbstractSequence) and
                isinstance(t.value_type, rosidl_parser.definition.BasicType) and
                t.value_type.typename in ['float', 'double', 'int8', 'uint8', 'int16', 'uint16', 'int32', 'uint32', 'int64', 'uint64']
            ):
                if len(field) == 0:
                    fieldstr = '[]'
                else:
                    assert fieldstr.startswith('array(')
                    prefix = "array('X', "
                    suffix = ')'
                    fieldstr = fieldstr[len(prefix):-len(suffix)]
            args.append(s[1:] + '=' + fieldstr)
        return '%s(%s)' % ('.'.join(typename), ', '.join(args))

    def __eq__(self, other):
        if not isinstance(other, self.__class__):
            return False
        if self.obstacle_area_status != other.obstacle_area_status:
            return False
        if self.obstacle_distance != other.obstacle_distance:
            return False
        if self.obstacle_direction != other.obstacle_direction:
            return False
        if self.obstacle_length != other.obstacle_length:
            return False
        return True

    @classmethod
    def get_fields_and_field_types(cls):
        from copy import copy
        return copy(cls._fields_and_field_types)

    @builtins.property
    def obstacle_area_status(self):
        """Message field 'obstacle_area_status'."""
        return self._obstacle_area_status

    @obstacle_area_status.setter
    def obstacle_area_status(self, value):
        if __debug__:
            assert \
                isinstance(value, int), \
                "The 'obstacle_area_status' field must be of type 'int'"
            assert value >= -128 and value < 128, \
                "The 'obstacle_area_status' field must be an integer in [-128, 127]"
        self._obstacle_area_status = value

    @builtins.property
    def obstacle_distance(self):
        """Message field 'obstacle_distance'."""
        return self._obstacle_distance

    @obstacle_distance.setter
    def obstacle_distance(self, value):
        if __debug__:
            assert \
                isinstance(value, float), \
                "The 'obstacle_distance' field must be of type 'float'"
            assert not (value < -1.7976931348623157e+308 or value > 1.7976931348623157e+308) or math.isinf(value), \
                "The 'obstacle_distance' field must be a double in [-1.7976931348623157e+308, 1.7976931348623157e+308]"
        self._obstacle_distance = value

    @builtins.property
    def obstacle_direction(self):
        """Message field 'obstacle_direction'."""
        return self._obstacle_direction

    @obstacle_direction.setter
    def obstacle_direction(self, value):
        if __debug__:
            assert \
                isinstance(value, int), \
                "The 'obstacle_direction' field must be of type 'int'"
            assert value >= -128 and value < 128, \
                "The 'obstacle_direction' field must be an integer in [-128, 127]"
        self._obstacle_direction = value

    @builtins.property
    def obstacle_length(self):
        """Message field 'obstacle_length'."""
        return self._obstacle_length

    @obstacle_length.setter
    def obstacle_length(self, value):
        if __debug__:
            assert \
                isinstance(value, float), \
                "The 'obstacle_length' field must be of type 'float'"
            assert not (value < -1.7976931348623157e+308 or value > 1.7976931348623157e+308) or math.isinf(value), \
                "The 'obstacle_length' field must be a double in [-1.7976931348623157e+308, 1.7976931348623157e+308]"
        self._obstacle_length = value
