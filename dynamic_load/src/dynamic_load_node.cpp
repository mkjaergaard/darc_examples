#include <iostream>
#include <boost/thread.hpp>
#include <darc/node.h>
#include <darc/registry.h>
#include <darc/component_loader.h>

int main(int argc, const char* argv[])
{
  // Create Node
  darc::Node::Ptr node = darc::Node::create();

  // Load TimerComponent
  darc::ComponentLoader::loadComponent("libtimer_component.so");

  // Create and run Component1
  darc::Component::Ptr c1 = darc::Registry::instantiateComponent( "MyTimerComponent", node );
  boost::thread t1( boost::bind(&darc::Component::run, c1) );

  // Run Node in main thread
  node->run();
  return 0;
}

