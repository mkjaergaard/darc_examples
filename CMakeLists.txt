cmake_minimum_required(VERSION 2.8)
project(darc)

find_package(catkin)

# todo: package for examples and documentation

# The real stuff is in:
#  darc_common
#  darc_ns
#  darc_pubsub
#  darc_procedures
#  darc_component

find_package(catkin REQUIRED COMPONENTS darc_component)
include_directories(${catkin_INCLUDE_DIRS})

add_executable(my_publisher_component
  src/my_publisher_component.cpp
  ../darc_component/src/autostart_peer.cpp)
target_link_libraries(my_publisher_component ${catkin_LIBRARIES})

add_executable(my_subscriber_component
  src/my_subscriber_component.cpp
  ../darc_component/src/autostart_peer.cpp)
target_link_libraries(my_subscriber_component ${catkin_LIBRARIES})