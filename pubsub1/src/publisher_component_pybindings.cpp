#include <boost/python.hpp>

#include "publisher_component.cpp"

namespace bp = boost::python;

BOOST_PYTHON_MODULE(publisher_component)
{
  bp::class_<MyPublisherComponent, boost::shared_ptr<MyPublisherComponent>, boost::noncopyable, bp::bases<darc::Component> >("MyPublisherComponent", bp::no_init);
}
