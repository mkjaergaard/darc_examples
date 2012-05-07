# Node embedded with both components
add_executable(pubsub_node
  src/pubsub_node.cpp
  src/my_publisher_component.cpp
  src/my_subscriber_component.cpp)
target_link_libraries(pubsub_node ${darc_LIBRARIES})

# Node embedded with only subscriber component
add_executable(sub_node
  src/sub_node.cpp
  src/my_subscriber_component.cpp)
target_link_libraries(sub_node ${darc_LIBRARIES})

