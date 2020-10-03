#pragma once

#include "events/event.hpp"

namespace Engine {

	class WindowUpdatedEvent : public Event {
		using Function = std::function<bool(double)>;
		std::vector<Function> mConnections;

	public:
		virtual void Fire(double deltaTime);

		virtual void Connect(const Function& function);
		virtual void Disconnect(const Function& function);
	};

}