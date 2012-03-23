#include <iostream>
#include <darc/darc.h>

int main(int argc, const char* argv[])
{
  // Create Node
  darc::NodePtr node = darc::Node::create();

  // Create and run Components
  darc::ComponentPtr c1 = node->instantiateComponent("MyServerComponent");
  c1->run();

  darc::ComponentPtr c2 = node->instantiateComponent("MyClientComponent");
  c2->run();

  // Set up node connections
  node->accept("udp://127.0.0.1:5120");
  node->connect("udp://127.0.0.1:5125");

  // Run Node in main thread
  node->runCurrentThread();
  return 0;
}

