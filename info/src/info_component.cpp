#include <darc/component.h>
#include <darc/system_state_interface.h>
#include <darc/timer/deadline_timer.h>
#include <darc/log.h>

class MyInfoComponent : public darc::Component
{
protected:
  darc::timer::DeadlineTimer timer_;
  darc::SystemStateInterface system_if_;

protected:
  void timerHandler()
  {
    DARC_INFO("BANG!");
    darc::SystemStateInterface::NodeListType list;
    system_if_.getRemoteNodeList(list);
    for(darc::SystemStateInterface::NodeListType::iterator it = list.begin();
	it != list.end();
	it++)
    {
      std::cout << it->short_string() << std::endl;
    }
    std::cout << "Thats it!" << std::endl;
  }

public:
  MyInfoComponent() :
    timer_(this, &MyInfoComponent::timerHandler),
    system_if_(this)
  {
  }

  void onStart()
  {
    timer_.startTimer(boost::posix_time::seconds(1));
  }

};

DARC_REGISTER_COMPONENT(MyInfoComponent)
