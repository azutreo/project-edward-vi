#pragma once

#include "rendering/opengl/window_opengl.hpp"
#include "events/event_application_updated.hpp"

#include <thread>

namespace Engine {

	class Application {
		Rendering::Window* mWindow;

		bool mRunning = true;
		std::chrono::steady_clock::time_point mRunningTime = std::chrono::high_resolution_clock::now();

	public:
		Application();
		~Application();

		void Run();

		inline Rendering::Window* GetWindow() const { return mWindow; }

		Events::ApplicationUpdatedEvent Updated;
	};

}