# generated from rosidl_generator_py/resource/_idl.py.em
# with input from obstacle_msgs:msg/Area.idl
# generated code does not contain a copyright notice


# Import statements for member types

import builtins  # noqa: E402, I100

import math  # noqa: E402, I100

import rosidl_parser.definition  # noqa: E402, I100


class Metaclass_Area(type):
    """Metaclass of message 'Area'."""

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
                'obstacle_msgs.msg.Area')
            logger.debug(
                'Failed to import needed modules for type support:\n' +
                traceback.format_exc())
        else:
            cls._CREATE_ROS_MESSAGE = module.create_ros_message_msg__msg__area
            cls._CONVERT_FROM_PY = module.convert_from_py_msg__msg__area
            cls._CONVERT_TO_PY = module.convert_to_py_msg__msg__area
            cls._TYPE_SUPPORT = module.type_support_msg__msg__area
            cls._DESTROY_ROS_MESSAGE = module.destroy_ros_message_msg__msg__area

    @classmethod
    def __prepare__(cls, name, bases, **kwargs):
        # list constant names here so that they appear in the help text of
        # the message class under "Data and other attributes defined here:"
        # as well as populate each message instance
        return {
        }


class Area(metaclass=Metaclass_Area):
    """Message class 'Area'."""

    __slots__ = [
        '_obstacle_status',
        '_obstacle_value',
        '_obstacle_distance',
    ]

    _fields_and_field_types = {
        'obstacle_status': 'int8',
        'obstacle_value': 'boolean',
        'obstacle_distance': 'double',
    }

    SLOT_TYPES = (
        rosidl_parser.definition.BasicType('int8'),  # noqa: E501
        rosidl_parser.definition.BasicType('boolean'),  # noqa: E501
        rosidl_parser.definition.BasicType('double'),  # noqa: E501
    )

    def __init__(self, **kwargs):
        assert all('_' + key in self.__slots__ for key in kwargs.keys()), \
            'Invalid arguments passed to constructor: %s' % \
            ', '.join(sorted(k for k in kwargs.keys() if '_' + k not in self.__slots__))
        self.obstacle_status = kwargs.get('obstacle_status', int())
        self.obstacle_value = kwargs.get('obstacle_value', bool())
        self.obstacle_distance = kwargs.get('obstacle_distance', float())

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
        if self.obstacle_status != other.obstacle_status:
            return False
        if self.obstacle_value != other.obstacle_value:
            return False
        if self.obstacle_distance != other.obstacle_distance:
            return False
        return True

    @classmethod
    def get_fields_and_field_types(cls):
        from copy import copy
        return copy(cls._fields_and_field_types)

    @builtins.property
    def obstacle_status(self):
        """Message field 'obstacle_status'."""
        return self._obstacle_status

    @obstacle_status.setter
    def obstacle_status(self, value):
        if __debug__:
            assert \
                isinstance(value, int), \
                "The 'obstacle_status' field must be of type 'int'"
            assert value >= -128 and value < 128, \
                "The 'obstacle_status' field must be an integer in [-128, 127]"
        self._obstacle_status = value

    @builtins.property
    def obstacle_value(self):
        """Message field 'obstacle_value'."""
        return self._obstacle_value

    @obstacle_value.setter
    def obstacle_value(self, value):
        if __debug__:
            assert \
                isinstance(value, bool), \
                "The 'obstacle_value' field must be of type 'bool'"
        self._obstacle_value = value

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
