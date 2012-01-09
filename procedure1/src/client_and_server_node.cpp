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
  boost::thread t1( boost::bind(&darc::Component::run, c1) );

  // Create and run Component2
  darc::Component::Ptr c2 = darc::Registry::instantiateComponent( "MyClientComponent", node );
  boost::thread t2( boost::bind(&darc::Component::run, c2) );

  // Set up node connections
  node->setNodeID(130);
  node->accept("udp://127.0.0.1:5130");
  node->connect(135, "udp://127.0.0.1:5135");

  // Run Node in main thread
  node->run();
  return 0;
}

