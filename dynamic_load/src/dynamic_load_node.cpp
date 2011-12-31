#include <iostream>
#include <darc/node.h>
#include <darc/component_register.h>
#include <darc/component_loader.h>

int main(int argc, const char* argv[])
{
  // Create Node
  darc::Node::Ptr node = darc::Node::create();

  // Load TimerComponent
  darc::ComponentLoader::loadComponent("libtimer_component.so");

  // Create and run Component1
  darc::Component::Ptr c1 = darc::ComponentRegister::instantiateComponent( "MyTimerComponent", node );
  boost::thread t1( boost::bind(&darc::Component::run, c1) );

  // Run Node in main thread
  node->run();
  return 0;
}

