#include "engine_precompiled/engine_precompiled.hpp"
#include "rendering/window.hpp"

#include "rendering/opengl/window_opengl.hpp"

namespace Engine {

	void Window::Update() {
		auto end = std::chrono::high_resolution_clock::now();
		auto duration = std::chrono::duration_cast<std::chrono::microseconds>(end - mRunningTime);
		double deltaTime = duration.count() * 1e-6;

		UpdateRenderer();
		UpdatedEvent.Fire(deltaTime);

		mRunningTime = end;
	}

	Window* Window::Create(const WindowProperties& properties) {
		return new OpenGlWindow(properties);
	}

}