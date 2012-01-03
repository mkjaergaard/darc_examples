#include <darc/node.h>
#include <darc/component.h>
#include <darc/procedure/server.h>

#include <std_msgs/Int32.h>

class MyServerComponent : public darc::Component
{
protected:
  darc::procedure::Server<std_msgs::Int32, std_msgs::Int32, std_msgs::Int32> procedure_server_;

protected:
  void procedureCall( boost::shared_ptr<std_msgs::Int32> msg )
  {
    std::cout << "Procedure Call" << std::endl;
    // send return value
  }

public:
  MyServerComponent( const std::string& instance_name, darc::Node::Ptr node ) : 
    darc::Component(instance_name, node),
    procedure_server_( this, "myprocedure", boost::bind(&MyServerComponent::procedureCall, this, _1) )
  {
  }

};

DARC_REGISTER_COMPONENT(MyServerComponent)
