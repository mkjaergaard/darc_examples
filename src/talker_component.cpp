#include <iris/static_scope.hpp>
#include <darc/component.hpp>
#include <darc/periodic_timer.hpp>
#include <darc/publisher.h>

class talker_component : public darc::component, public iris::static_scope<iris::Info>
{
  int count_;
  darc::periodic_timer timer_;
  darc::publisher<std::string> chatter_pub_;

  void timer_callback()
  {
    boost::shared_ptr<std::string> msg = boost::make_shared<std::string>();

    *msg = std::string("Hello World ").append(boost::to_string(++count_));

    slog<iris::Info>("Publishing",
                     "Msg", iris::arg<std::string>(*msg));

    chatter_pub_.publish(msg);
  }

public:
  talker_component() :
    count_(0),
    timer_(this, &talker_component::timer_callback, boost::posix_time::seconds(1)),
    chatter_pub_(this, "chatter")
  {
  }

};

DARC_REGISTER_COMPONENT(talker_component)
