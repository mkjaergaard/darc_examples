#include <darc/component.h>
#include <darc/pubsub/subscriber.h>
#include <darc/log.h>

#include <std_msgs/String.h>

class MySubscriberComponent : public darc::Component
{
protected:
  darc::pubsub::Subscriber<std_msgs::String> sub_;

protected:
  void subHandler( const boost::shared_ptr<const std_msgs::String> msg )
  {
    DARC_INFO("%s", msg->data.c_str());
  }

public:
  MySubscriberComponent( const std::string& instance_name, darc::Node::Ptr node ) :
    darc::Component(instance_name, node),
    sub_(this, "mytopic", boost::bind(&MySubscriberComponent::subHandler, this, _1) )
  {
  }

};

DARC_REGISTER_COMPONENT(MySubscriberComponent)
