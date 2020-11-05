#pragma once

#include "events/event.hpp"

namespace Engine {

	class WindowResizedEvent : public Event {
		using Function = std::function<bool(unsigned int width, unsigned int height)>;
		std::vector<Function> mConnections;

	public:
		virtual void Fire(unsigned int width, unsigned int height);

		virtual void Connect(const Function& function);
		virtual void Disconnect(const Function& function);
	};

}