#include <iostream>
#include <boost/thread.hpp>
#include <darc/node.h>
#include <darc/registry.h>

int main(int argc, const char* argv[])
{
  // Create Node
  darc::Node::Ptr node = darc::Node::create();

  // Create and run Component1
  darc::Component::Ptr c1 = darc::Registry::instantiateComponent( "MyPublisherComponent", node );
  boost::thread t1( boost::bind(&darc::Component::run, c1) );

  // Create and run Component2
  darc::Component::Ptr c2 = darc::Registry::instantiateComponent( "MySubscriberComponent", node );
  boost::thread t2( boost::bind(&darc::Component::run, c2) );

  // You can also manually construct a component and call the run() method if you want.
  // But using the register allows for other cool stuff. E.g. starting remotely.

  // Set up node connections
  node->setNodeID(120);
  node->accept("udp://127.0.0.1:5120");
  node->connect(125, "udp://127.0.0.1:5125");

  // Run Node in main thread
  node->run();
  return 0;
}

