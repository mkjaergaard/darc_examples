#include <darc/component.h>
#include <darc/pubsub/publisher.h>
#include <darc/timer/periodic_timer.h>
#include <darc/log.h>

#include <std_msgs/String.h>

class MyPublisherComponent : public darc::Component
{
protected:
  darc::pubsub::Publisher<std_msgs::String> pub_;
  darc::timer::PeriodicTimer timer_;

protected:
  void timerHandler( )
  {
    DARC_INFO("Publishing message");
    boost::shared_ptr<std_msgs::String> msg( new std_msgs::String() );
    msg->data = "Hello World";
    pub_.publish(msg);
  }

public:
  MyPublisherComponent( const std::string& instance_name, darc::Node::Ptr node ) :
    darc::Component(instance_name, node),
    pub_(this, "/mytopic"),
    timer_(this, boost::bind(&MyPublisherComponent::timerHandler, this), boost::posix_time::seconds(1))
  {
  }

};

DARC_REGISTER_COMPONENT(MyPublisherComponent)
