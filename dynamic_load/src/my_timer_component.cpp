#include <darc/darc.h>

class MyTimerComponent : public darc::Component
{
protected:
  darc::timer::PeriodicTimer timer_;

protected:
  void timerHandler()
  {
    DARC_INFO("Timer Event");
  }

public:
  MyTimerComponent() :
    timer_(this, &MyTimerComponent::timerHandler, boost::posix_time::seconds(1))
  {
  }

};

DARC_REGISTER_COMPONENT(MyTimerComponent)
