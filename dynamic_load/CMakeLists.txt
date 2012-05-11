add_library(MyTimerComponent SHARED src/my_timer_component.cpp)
target_link_libraries(MyTimerComponent ${darc_LIBRARIES})

find_package(Boost COMPONENTS program_options)

add_executable(dyn_node src/dynamic_load_node.cpp)
target_link_libraries(dyn_node ${darc_LIBRARIES} ${Boost_LIBRARIES})
