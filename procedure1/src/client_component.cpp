#include <darc/darc.h>
#include <std_msgs/Int32.h>

class MyClientComponent : public darc::Component
{
protected:
  darc::procedure::Client<std_msgs::Int32, std_msgs::Int32, std_msgs::Int32> procedure_client_;
  darc::timer::PeriodicTimer timer_;

protected:
  void timerHandler()
  {
    std_msgs::Int32::Ptr msg( new std_msgs::Int32 );
    msg->data = 10;
    procedure_client_.call(msg);
  }

  void resultHandler(const darc::procedure::CallID& call_id, const std_msgs::Int32& msg)
  {
    DARC_INFO("Result %s", call_id.short_string().c_str());
  }

  void feedbackHandler(const darc::procedure::CallID& call_id, const std_msgs::Int32& msg)
  {
    DARC_INFO("Feedback %s", call_id.short_string().c_str());
  }

public:
  MyClientComponent() :
    procedure_client_(this, "/myprocedure", &MyClientComponent::resultHandler),
    timer_(this, &MyClientComponent::timerHandler, boost::posix_time::seconds(1))
  {
    procedure_client_.registerFeedbackHandler(this, &MyClientComponent::feedbackHandler);
  }

};

DARC_REGISTER_COMPONENT(MyClientComponent)
