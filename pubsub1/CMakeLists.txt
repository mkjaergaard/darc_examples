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

#pybindings
find_package(PythonLibs)
find_package(Boost COMPONENTS python thread)

include_directories(${PYTHON_INCLUDE_DIRS} ${Boost_INCLUDE_DIRS})

add_library(publisher_component-pybindings SHARED src/publisher_component_pybindings.cpp)
target_link_libraries(publisher_component-pybindings ${Boost_LIBRARIES} darc)
set_target_properties(publisher_component-pybindings
  PROPERTIES
  OUTPUT_NAME publisher_component
  PREFIX ""
  LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib
  )
