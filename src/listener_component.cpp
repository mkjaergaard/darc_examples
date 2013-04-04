#include <iris/static_scope.hpp>
#include <darc/component.hpp>
#include <darc/subscriber.h>

class listener_component : public darc::component, public iris::static_scope<iris::Info>
{
  darc::subscriber<std::string> sub_;

  void chatter_callback(const boost::shared_ptr<const std::string> msg)
  {
    slog<iris::Info>("Received",
                     "msg", iris::arg<std::string>(*msg));
  }

public:
  listener_component() :
    sub_(this, "chatter", boost::bind(&listener_component::chatter_callback, this, _1))
  {
  }

};

DARC_REGISTER_COMPONENT(listener_component)
