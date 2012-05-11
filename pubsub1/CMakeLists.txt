add_library(MyPublisherComponent SHARED src/my_publisher_component.cpp)
target_link_libraries(MyPublisherComponent ${darc_LIBRARIES})

add_library(MySubscriberComponent SHARED src/my_subscriber_component.cpp)
target_link_libraries(MySubscriberComponent ${darc_LIBRARIES})
