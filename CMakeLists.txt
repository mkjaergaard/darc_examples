cmake_minimum_required(VERSION 2.8)
project(darc_examples)

SET(CMAKE_BUILD_TYPE Debug)

find_package(darc)
find_package(ROS REQUIRED COMPONENTS std_msgs)

include_directories(include)
include_directories(${darc_INCLUDE_DIRS})
include_directories(${ROS_INCLUDE_DIRS})

add_subdirectory(pubsub1)
add_subdirectory(procedure1)
#add_subdirectory(dynamic_load)
