add_library(my_timer_component SHARED src/my_timer_component.cpp)
target_link_libraries(my_timer_component ${darc_LIBRARIES})

add_executable(dynamic_load_node src/dynamic_load_node.cpp)
target_link_libraries(dynamic_load_node ${darc_LIBRARIES})
