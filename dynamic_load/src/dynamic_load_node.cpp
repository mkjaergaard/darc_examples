#include <iostream>
#include <darc/darc.h>
#include <darc/component_loader.h>

int main(int argc, const char* argv[])
{
  // Create Node
  darc::NodePtr node = darc::Node::create();

  // Load TimerComponent
  darc::ComponentLoader::loadComponent("libmy_timer_component.so");

  // Create and run Component1
  darc::ComponentPtr c1 = node->instantiateComponent("MyTimerComponent");
  c1->run();

  // Run Node in main thread
  node->runCurrentThread();
  return 0;
}
