# Node embedded with both components
add_executable(pubsub_node src/pubsub_node.cpp src/publisher_component.cpp src/subscriber_component.cpp)
target_link_libraries(pubsub_node ${darc_LIBRARIES} ${ROS_LIBRARIES})

# Node embedded with only subscriber component
add_executable(sub_node src/sub_node.cpp src/subscriber_component.cpp)
target_link_libraries(sub_node ${darc_LIBRARIES} ${ROS_LIBRARIES})

# PyBindings for the components
darc_pybindings(MyPublisherComponent src/publisher_component.cpp)
darc_pybindings(MySubscriberComponent src/subscriber_component.cpp)
