#pragma once

#include "events/event.hpp"

namespace Engine {

	class MouseScrolledEvent : public Event {
		using Function = std::function<bool(double, double)>;
		std::vector<Function> mConnections;

	public:
		void Fire(double x, double y);

		void Connect(const Function& function);
		void Disconnect(const Function& function);
	};

}