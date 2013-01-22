#include <iris/static_scope.hpp>
#include <darc/component.hpp>
#include <darc/subscriber.h>

extern const char name[] = "my_subscriber_component";

class my_subscriber_component : public darc::component, public iris::static_scope<iris::Info, name>
{
  darc::subscriber<int> my_sub_;

  void callback()
  {
    slog<iris::Info>("Msg Received");
  }

public:
  my_subscriber_component() :
    my_sub_(this, "my_topic", boost::bind(&my_subscriber_component::callback, this))
  {
    iris::glog<iris::Info>("my_subscriber_component created");
  }

};

DARC_REGISTER_COMPONENT(my_subscriber_component)
