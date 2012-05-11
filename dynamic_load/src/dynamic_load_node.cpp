#include <iostream>
#include <boost/program_options.hpp>
#include <darc/darc.h>
#include <darc/component_loader.h>

namespace po = boost::program_options;

typedef std::vector<std::string> StringVecType;

int main(int argc, const char* argv[])
{
  // Arguments
  po::options_description desc("Allowed options");
  desc.add_options()
    ("help,h", "produce help message")
    ("load,l", po::value< std::vector<std::string> >(), "components to load and start")
    ("connect,c", po::value< std::vector<std::string> >(), "connect url")
    ("accept,a", po::value< std::vector<std::string> >(), "accept url")
    ;

  po::variables_map vm;
  po::store(po::parse_command_line(argc, argv, desc), vm);
  po::notify(vm);

  if (vm.count("help"))
  {
    std::cout << desc << std::endl;
    return 1;
  }

  // Create Node
  darc::NodePtr node = darc::Node::create();

  // Components
  if(vm.count("load"))
  {
    for(StringVecType::const_iterator it = vm["load"].as<StringVecType>().begin();
	it != vm["load"].as<StringVecType>().end();
	it++)
    {
      char buffer[256];
      DARC_INFO("Loading component %s", it->c_str());
      sprintf(buffer, "lib%s.so", it->c_str());
      darc::ComponentLoader::loadComponent(buffer);    
      darc::ComponentPtr c1 = node->instantiateComponent(*it);
      assert(c1.get());
      c1->run();
    }
  }

  // Accepts
  if(vm.count("accept"))
  {
    for(StringVecType::const_iterator it = vm["accept"].as<StringVecType>().begin();
	it != vm["accept"].as<StringVecType>().end();
	it++)
    {
      DARC_INFO("Accepting on %s", it->c_str());
      node->accept(*it);
    }
  }

  // Connects
  if(vm.count("connect"))
  {
    for(StringVecType::const_iterator it = vm["connect"].as<StringVecType>().begin();
	it != vm["connect"].as<StringVecType>().end();
	it++)
    {
      DARC_INFO("Connecting on %s", it->c_str());
      node->connect(*it);
    }
  }

  // Run Node in main thread
  node->runCurrentThread();
  return 0;
}
