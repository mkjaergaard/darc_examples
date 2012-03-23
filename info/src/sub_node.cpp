#include <iostream>
#include <darc/darc.h>

int main(int argc, const char* argv[])
{
  // Create Node
  darc::Node::Ptr node = darc::Node::create();

  // Set up node connections manually
  node->accept("udp://127.0.0.1:5120-5125");
  node->connect("udp://127.0.0.1:5120-5125");

  // Instantiate SubscriberComponent
  darc::Component::Ptr c1 = node->instantiateComponent( "MySubscriberComponent" );

  // Run Component (This is non-blocking)
  c1->run();

  // Run Node in main thread
  node->run(); // This is blocking
  return 0;
}
