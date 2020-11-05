#include "engine_precompiled/engine_precompiled.hpp"
#include "events/event.hpp"

namespace Engine {

	Event::Event(std::string name) :
		mName(name) {}

	void Event::Fire() { // If there are arguments, put them in the ()
		for(Function function : mConnections) {
			bool handled = function();
			if(handled) { return; }
		}
	};

	void Event::Connect(const Function& function) {
		mConnections.push_back(function);
	};

	void Event::Disconnect(const Function& function) {
		/*std::vector<Function>::iterator toRemove = Connections.begin();
		for(Connections.begin(); toRemove != Connections.end(); ++toRemove) {
			if(*(*toRemove) == function) {
				Connections.erase(toRemove);
				break;
			}
		}*/
	};

	std::ostream& operator<<(std::ostream& ostream, const Event& event) {
		return ostream <<
			"Event:" << std::endl <<
			"  Name: " << event.mName;;
	}

};