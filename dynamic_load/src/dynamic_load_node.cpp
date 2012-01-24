#include <iostream>
#include <boost/thread.hpp>
#include <darc/darc.h>
#include <darc/component_loader.h>

int main(int argc, const char* argv[])
{
  // Create Node
  darc::Node::Ptr node = darc::Node::create();

  // Load TimerComponent
  darc::ComponentLoader::loadComponent("libtimer_component.so");

  // Create and run Component1
  darc::Component::Ptr c1 = node->instantiateComponent( "MyTimerComponent" );
  c1->run();

  // Run Node in main thread
  node->run();
  return 0;
}
