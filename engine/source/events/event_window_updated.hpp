#pragma once

#include "events/event.hpp"

namespace Engine {

	class WindowUpdatedEvent : public Event {
		using Function = std::function<bool(double)>;
		std::vector<Function> mConnections;

	public:
		void Fire(double deltaTime);

		void Connect(const Function& function);
		void Disconnect(const Function& function);
	};

}