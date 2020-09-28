#pragma once

#include "rendering/opengl/window_opengl.hpp"
#include "events/event_application_updated.hpp"

#include <thread>

namespace Engine {

	class Application {
		Renderer::OpenGlWindow* mWindow;

		bool mRunning = true;
		std::chrono::steady_clock::time_point mRunningTime = std::chrono::high_resolution_clock::now();

	public:
		Application();
		~Application();

		void Run();

		Events::ApplicationUpdatedEvent Updated;
	};

}