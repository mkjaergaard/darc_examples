#include <darc/darc.h>
#include <std_msgs/String.h>

class MyClientComponent : public darc::Component
{
protected:
  // Argument: std_msgs::String
  // Feedback: std_msgs::String
  // Result:   std_msgs::String
  darc::procedure::Client<std_msgs::String, std_msgs::String, std_msgs::String> procedure_client_;
  darc::timer::PeriodicTimer timer_;

protected:
  void timerHandler()
  {
    std_msgs::String::Ptr argument(new std_msgs::String);
    argument->data = "Some Argument";
    procedure_client_.call(argument);
  }

  void resultHandler(const darc::procedure::CallID& call_id, const std_msgs::String& msg)
  {
    DARC_INFO("Received Result (%s)", call_id.short_string().c_str(), msg.data.c_str());
  }

  void feedbackHandler(const darc::procedure::CallID& call_id, const std_msgs::String& msg)
  {
    DARC_INFO("Received Feedback (%s)", call_id.short_string().c_str(), msg.data.c_str());
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
