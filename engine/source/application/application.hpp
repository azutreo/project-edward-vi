#pragma once

#include <thread>

#include "windows/window_opengl.hpp"
#include "events/event_application_updated.hpp"

namespace Engine {

	class Application {
		Windows::OpenGlWindow* mWindow;

		bool mRunning = true;
		std::chrono::steady_clock::time_point mRunningTime = std::chrono::high_resolution_clock::now();

	public:

		Application();
		~Application();

		void Run();

		Events::ApplicationUpdatedEvent Updated;

	};

}