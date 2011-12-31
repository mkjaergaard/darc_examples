#include <iostream>
#include <darc/node.h>
#include <darc/component_register.h>

int main(int argc, const char* argv[])
{
  // Create Node
  darc::Node::Ptr node = darc::Node::create();

  // Create and run Component1
  darc::Component::Ptr c1 = darc::ComponentRegister::instantiateComponent( "MyServerComponent", node );
  boost::thread t1( boost::bind(&darc::Component::run, c1) );

  // Create and run Component2
  darc::Component::Ptr c2 = darc::ComponentRegister::instantiateComponent( "MyClientComponent", node );
  boost::thread t2( boost::bind(&darc::Component::run, c2) );

  // Set up node connections
  node->setNodeID(130);
  node->accept("udp://127.0.0.1:5130");
  node->connect(135, "udp://127.0.0.1:5135");

  // Run Node in main thread
  node->run();
  return 0;
}

