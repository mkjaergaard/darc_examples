#include <iostream>
#include <darc/node.h>
#include <darc/component_register.h>

int main(int argc, const char* argv[])
{
  // Create Node
  darc::Node::Ptr node = darc::Node::create();

  // Create and run Component1
  darc::Component::Ptr c1 = darc::ComponentRegister::instantiateComponent( "MyClientComponent", node );
  boost::thread t1( boost::bind(&darc::Component::run, c1) );

  // Set up node connections
  node->setNodeID(135);
  node->accept("udp://127.0.0.1:5135");
  node->connect(120, "udp://127.0.0.1:5130");

  // Run Node in main thread
  node->run();
  return 0;
}
