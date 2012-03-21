#include <iostream>
#include <boost/thread.hpp>
#include <darc/node.h>
#include <darc/registry.h>

int main(int argc, const char* argv[])
{
  // Create Node
  darc::Node::Ptr node = darc::Node::create();

  // Create and run Component1
  darc::Component::Ptr c1 = darc::Registry::instantiateComponent( "MyServerComponent", node );
  c1->run();

  // Set up node connections
  node->accept("udp://127.0.0.1:5130-5135");
  node->connect("udp://127.0.0.1:5130-5135");

  // Run Node in main thread
  node->run();
  return 0;
}
