cmake_minimum_required(VERSION 2.8)
project(dynamic_load)

include_directories(include)
include_directories(${darc_INCLUDE_DIRS})
include_directories(${ROS_INCLUDE_DIRS})

set(CMAKE_CXX_FLAGS "-Os")

add_library(timer_component SHARED src/timer_component.cpp)
target_link_libraries(timer_component ${darc_LIBRARIES} ${ROS_LIBRARIES})

add_executable(dynamic_load_node src/dynamic_load_node.cpp)
target_link_libraries(dynamic_load_node ${darc_LIBRARIES} ${ROS_LIBRARIES})
