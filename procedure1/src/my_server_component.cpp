#include <darc/darc.h>
#include <std_msgs/String.h>

class MyServerComponent : public darc::Component
{
protected:
  // Argument: std_msgs::String
  // Feedback: std_msgs::String
  // Result:   std_msgs::String
  darc::procedure::Server<std_msgs::String, std_msgs::String, std_msgs::String> procedure_server_;

protected:
  void procedureCall(const darc::procedure::CallID& call_id, const std_msgs::String& msg)
  {
    DARC_INFO("Procedure Call %s", call_id.short_string().c_str());

    // Send a feedback message
    std_msgs::String::Ptr feedback(new std_msgs::String());
    feedback->data = "Some Feedback";
    procedure_server_.feedback(call_id, feedback);

    // Send a result message
    std_msgs::String::Ptr result(new std_msgs::String());
    result->data = "Some Result";
    procedure_server_.result(call_id, result);
  }

public:
  MyServerComponent() :
    procedure_server_(this, "/myprocedure", &MyServerComponent::procedureCall)
  {
  }

};

DARC_REGISTER_COMPONENT(MyServerComponent)
