from setuptools import find_packages
from setuptools import setup

setup(
    name='obstacle_msgs',
    version='0.0.0',
    packages=find_packages(
        include=('obstacle_msgs', 'obstacle_msgs.*')),
)
