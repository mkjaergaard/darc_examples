import darc

# Create component_manager
mngr = darc.component_manager()

# Load the Listener component
darc.component_loader.load_component("liblistener_component.so")

# Instantiate the Listener component
c = darc.registry.instantiate_component("listener_component", mngr)

# Run the Listener component
c.run()

# Manually add connections to other peers in the 5000-5009 port range
mngr.connect("zmq+tcp://127.0.0.1:5000")
mngr.connect("zmq+tcp://127.0.0.1:5001")
mngr.connect("zmq+tcp://127.0.0.1:5002")
mngr.connect("zmq+tcp://127.0.0.1:5003")
mngr.connect("zmq+tcp://127.0.0.1:5004")
mngr.connect("zmq+tcp://127.0.0.1:5005")
mngr.connect("zmq+tcp://127.0.0.1:5006")
mngr.connect("zmq+tcp://127.0.0.1:5007")
mngr.connect("zmq+tcp://127.0.0.1:5008")
mngr.accept("zmq+tcp://127.0.0.1:5009")

# Run the component_manager in the python thread
mngr.run_current_thread()

