cmake_minimum_required(VERSION 2.8)
project(pubsub1)

include_directories(include)
include_directories(${darc_INCLUDE_DIRS})
include_directories(${ROS_INCLUDE_DIRS})

set(CMAKE_CXX_FLAGS "-Os")

add_executable(pubsub_node src/pubsub_node.cpp src/publisher_component.cpp src/subscriber_component.cpp)
target_link_libraries(pubsub_node ${darc_LIBRARIES} ${ROS_LIBRARIES})

add_executable(sub_node src/sub_node.cpp src/subscriber_component.cpp)
target_link_libraries(sub_node ${darc_LIBRARIES} ${ROS_LIBRARIES})
