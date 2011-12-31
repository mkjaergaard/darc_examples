#include <darc/node.h>
#include <darc/component.h>
#include <darc/timer.h>

class MyTimerComponent : public darc::Component
{
protected:
  darc::Timer timer_;

protected:
  void timerHandler( )
  {
    std::cout << name_ << " timer event" << std::endl;
  }

public:
  MyTimerComponent( const std::string& instance_name, darc::Node::Ptr node ) :
    darc::Component(instance_name, node),
    timer_(this, boost::bind(&MyTimerComponent::timerHandler, this), boost::posix_time::seconds(1))
  {
  }

};

DARC_REGISTER_COMPONENT(MyTimerComponent)
