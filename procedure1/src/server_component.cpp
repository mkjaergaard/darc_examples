#include <darc/node.h>
#include <darc/component.h>
#include <darc/procedure/server.h>

#include <std_msgs/Int32.h>

class MyServerComponent : public darc::Component
{
protected:
  darc::procedure::Server<std_msgs::Int32, std_msgs::Int32, std_msgs::Int32> procedure_server_;

protected:
  void procedureCall(const darc::procedure::CallID& call_id, boost::shared_ptr<const std_msgs::Int32> msg)
  {
    DARC_INFO("Procedure Call %s", call_id.short_string().c_str());
    procedure_server_.feedback(call_id, msg);
    procedure_server_.result(call_id, msg);
  }

public:
  MyServerComponent( const std::string& instance_name, darc::Node::Ptr node ) :
    darc::Component(instance_name, node),
    procedure_server_( this, "myprocedure", boost::bind(&MyServerComponent::procedureCall, this, _1, _2) )
  {
    DARC_AUTOTRACE();
  }

};

DARC_REGISTER_COMPONENT(MyServerComponent)
