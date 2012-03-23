#include <darc/darc.h>
#include <darc/parameter/parameter.h>
#include <std_msgs/String.h>

class MyPublisherComponent : public darc::Component
{
private:
  darc::pubsub::Publisher<std_msgs::String> publisher_;
  darc::timer::PeriodicTimer timer_;
  darc::parameter::Parameter<std::string> what_to_say_;

private:
  void timerHandler( )
  {
    boost::shared_ptr<std_msgs::String> msg(new std_msgs::String());
    msg->data = what_to_say_.getValue();

    DARC_INFO("Publishing message");
    publisher_.publish(msg);
  }

public:
  MyPublisherComponent() :
    publisher_(this, "/mytopic"),
    timer_(this, &MyPublisherComponent::timerHandler, boost::posix_time::seconds(1)),
    what_to_say_(this, "what_to_say", "Hello World")
  {
  }

};

DARC_REGISTER_COMPONENT(MyPublisherComponent)
