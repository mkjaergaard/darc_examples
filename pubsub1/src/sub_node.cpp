#include <iostream>
#include <boost/thread.hpp>
#include <darc/node.h>
#include <darc/registry.h>

int main(int argc, const char* argv[])
{
  // Create Node
  darc::Node::Ptr node = darc::Node::create();

  // Create and run Component1
  darc::Component::Ptr c1 = darc::Registry::instantiateComponent( "MySubscriberComponent", node );
  boost::thread t1( boost::bind(&darc::Component::run, c1) );

  // You can also manually construct a component and call the run() method if you want.
  // But using the register allows for other cool stuff. E.g. starting remotely.

  // Set up node connections
  node->setNodeID(125);
  node->accept("udp://127.0.0.1:5125");
  node->connect(120, "udp://127.0.0.1:5120");

  // Run Node in main thread
  node->run();
  return 0;
}

