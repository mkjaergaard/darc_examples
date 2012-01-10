cmake_minimum_required(VERSION 2.8)
project(darc_examples)

find_package(darc)
find_package(ROS REQUIRED COMPONENTS cpp_common rostime roscpp_traits roscpp_serialization std_msgs)

include_directories(include)
include_directories(${darc_INCLUDE_DIRS})
include_directories(${ROS_INCLUDE_DIRS})

set(CMAKE_CXX_FLAGS "-Wall -g")
#set(CMAKE_CXX_FLAGS "-Os")

add_subdirectory(pubsub1)
add_subdirectory(procedure1)
add_subdirectory(dynamic_load)
