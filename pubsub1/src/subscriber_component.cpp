#include <darc/darc.h>
#include <std_msgs/String.h>

class MySubscriberComponent : public darc::Component
{
protected:
  darc::pubsub::Subscriber<std_msgs::String> subscriber_;

protected:
  void subHandler(const std_msgs::String& msg)
  {
    DARC_INFO("Received Message: %s", msg.data.c_str());
  }

public:
  MySubscriberComponent() :
    subscriber_(this, "/mytopic", &MySubscriberComponent::subHandler)
  {
  }

};

DARC_REGISTER_COMPONENT(MySubscriberComponent)
