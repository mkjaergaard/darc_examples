add_library(timer_component SHARED src/timer_component.cpp)
target_link_libraries(timer_component ${darc_LIBRARIES} ${ROS_LIBRARIES})

add_executable(dynamic_load_node src/dynamic_load_node.cpp)
target_link_libraries(dynamic_load_node ${darc_LIBRARIES} ${ROS_LIBRARIES})
