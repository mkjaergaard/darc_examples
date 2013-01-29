cmake_minimum_required(VERSION 2.8)
project(darc_examples)

find_package(catkin)

find_package(catkin REQUIRED COMPONENTS darc_component)
include_directories(${catkin_INCLUDE_DIRS})

add_library(talker_component SHARED
  src/talker_component.cpp)
target_link_libraries(talker_component ${catkin_LIBRARIES})

add_library(listener_component SHARED
  src/listener_component.cpp)
target_link_libraries(listener_component ${catkin_LIBRARIES})