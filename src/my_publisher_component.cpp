#include <iris/static_scope.hpp>
#include <darc/component.hpp>
#include <darc/periodic_timer.hpp>
#include <darc/publisher.h>

extern const char name[] = "my_publisher_component";

class my_publisher_component : public darc::component, public iris::static_scope<iris::Info, name>
{
  darc::periodic_timer timer_;
  darc::publisher<int> my_pub_;

  void timer_callback()
  {
    slog<iris::Info>("Publishing");
    boost::shared_ptr<int> msg = boost::make_shared<int>(5);
    my_pub_.publish(msg);
  }

public:
  my_publisher_component() :
    timer_(this, &my_publisher_component::timer_callback, boost::posix_time::seconds(1)),
    my_pub_(this, "my_topic")
  {
    iris::glog<iris::Info>("my_publisher_component created");
  }

};

DARC_REGISTER_COMPONENT(my_publisher_component)
