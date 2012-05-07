# Node embedded with both client and server component
add_executable(client_and_server_node
  src/client_and_server_node.cpp
  src/my_client_component.cpp
  src/my_server_component.cpp)
target_link_libraries(client_and_server_node ${darc_LIBRARIES})

# Node embedded with only client component
add_executable(client_node
  src/client_node.cpp
  src/my_client_component.cpp)
target_link_libraries(client_node ${darc_LIBRARIES})

# Node embedded with only server component
add_executable(server_node
  src/server_node.cpp
  src/my_server_component.cpp)
target_link_libraries(server_node ${darc_LIBRARIES})
