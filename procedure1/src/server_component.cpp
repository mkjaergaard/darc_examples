#include <darc/darc.h>
#include <std_msgs/Int32.h>

class MyServerComponent : public darc::Component
{
protected:
  darc::procedure::Server<std_msgs::Int32, std_msgs::Int32, std_msgs::Int32> procedure_server_;

  boost::shared_ptr<std_msgs::Int32> my_answer_;

protected:
  void procedureCall(const darc::procedure::CallID& call_id, const std_msgs::Int32& msg)
  {
    DARC_INFO("Procedure Call %s", call_id.short_string().c_str());
    procedure_server_.feedback(call_id, my_answer_);
    procedure_server_.result(call_id, my_answer_);
  }

public:
  MyServerComponent() :
    procedure_server_(this, "myprocedure", &MyServerComponent::procedureCall),
    my_answer_(new std_msgs::Int32())
  {
    DARC_AUTOTRACE();
  }

};

DARC_REGISTER_COMPONENT(MyServerComponent)
