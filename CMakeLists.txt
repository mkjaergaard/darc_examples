cmake_minimum_required(VERSION 2.8)
project(darc_examples)

find_package(catkin)

find_package(catkin REQUIRED COMPONENTS darc_component)
include_directories(${catkin_INCLUDE_DIRS})

add_executable(talker
  src/talker_component.cpp
  ../darc_component/src/autostart_peer.cpp) # todo: link instead
target_link_libraries(talker ${catkin_LIBRARIES})

add_executable(listener
  src/listener_component.cpp
  ../darc_component/src/autostart_peer.cpp) # todo: link instead
target_link_libraries(listener ${catkin_LIBRARIES})