#pragma once
#include "engine_precompiled/engine_precompiled.hpp"

#include "events/event_application_updated.hpp"

namespace Engine::Events {

	void ApplicationUpdatedEvent::Fire(double deltaTime) {
		for(Function function : mConnections) {
			bool handled = function(deltaTime);
			if(handled) { return; }
		}
	};

	void ApplicationUpdatedEvent::Connect(const Function& function) {
		mConnections.push_back(function);
	};

	void ApplicationUpdatedEvent::Disconnect(const Function& function) {
		/*std::vector<Function>::iterator toRemove = Connections.begin();
		for(Connections.begin(); toRemove != Connections.end(); ++toRemove) {
			if(*(*toRemove) == function) {
				Connections.erase(toRemove);
				break;
			}
		}*/
	};

};