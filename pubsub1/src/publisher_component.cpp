#include <darc/darc.h>
#include <std_msgs/String.h>

class MyPublisherComponent : public darc::Component
{
private:
  darc::pubsub::Publisher<std_msgs::String> publisher_;
  darc::timer::PeriodicTimer timer_;

private:
  void timerHandler( )
  {
    boost::shared_ptr<std_msgs::String> msg(new std_msgs::String());
    msg->data = "Hello World";

    DARC_INFO("Publishing message");
    publisher_.publish(msg);
  }

public:
  MyPublisherComponent() :
    publisher_(this, "/mytopic"),
    timer_(this, &MyPublisherComponent::timerHandler, boost::posix_time::seconds(1))
  {
  }

};

DARC_REGISTER_COMPONENT(MyPublisherComponent)
