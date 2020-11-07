#include "engine_precompiled/engine_precompiled.hpp"
#include "events/input/event_input_mouse_scrolled.hpp"

namespace Engine {

	void MouseScrolledEvent::Fire(double x, double y) {
		for(Function function : mConnections) {
			bool handled = function(x, y);
			if(handled) { return; }
		}
	};

	void MouseScrolledEvent::Connect(const Function& function) {
		mConnections.push_back(function);
	};

	void MouseScrolledEvent::Disconnect(const Function& function) {
		/*std::vector<Function>::iterator toRemove = Connections.begin();
		for(Connections.begin(); toRemove != Connections.end(); ++toRemove) {
			if(*(*toRemove) == function) {
				Connections.erase(toRemove);
				break;
			}
		}*/
	};

};