#include <darc/node.h>
#include <darc/component.h>
#include <darc/pubsub/publisher.h>
#include <darc/timer/periodic_timer.h>

#include <std_msgs/String.h>

class MyPublisherComponent : public darc::Component
{
protected:
  darc::pubsub::Publisher<std_msgs::String> pub_;
  darc::timer::PeriodicTimer timer_;

protected:
  void timerHandler( )
  {
    boost::shared_ptr<std_msgs::String> msg( new std_msgs::String() );
    msg->data = "Hello";
    pub_.publish(msg);
    std::cout << name_ << " publishing message" << std::endl;
  }

public:
  MyPublisherComponent( const std::string& instance_name, darc::Node::Ptr node ) : 
    darc::Component(instance_name, node),
    pub_(this, "mytopic"),
    timer_(this, boost::bind(&MyPublisherComponent::timerHandler, this), boost::posix_time::seconds(1))
  {
  }

};

DARC_REGISTER_COMPONENT(MyPublisherComponent)
