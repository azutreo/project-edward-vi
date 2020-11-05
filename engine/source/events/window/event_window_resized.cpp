#include "engine_precompiled/engine_precompiled.hpp"

#include "events/window/event_window_resized.hpp"

namespace Engine {

	void WindowResizedEvent::Fire(unsigned int width, unsigned int height) {
		for(Function function : mConnections) {
			bool handled = function(width, height);
			if(handled) { return; }
		}
	};

	void WindowResizedEvent::Connect(const Function& function) {
		mConnections.push_back(function);
	};

	void WindowResizedEvent::Disconnect(const Function& function) {
		/*std::vector<Function>::iterator toRemove = Connections.begin();
		for(Connections.begin(); toRemove != Connections.end(); ++toRemove) {
			if(*(*toRemove) == function) {
				Connections.erase(toRemove);
				break;
			}
		}*/
	};

};