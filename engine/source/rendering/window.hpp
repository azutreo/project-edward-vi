#pragma once

#include "rendering/renderer.hpp"
#include "input/input.hpp"

#include "events/event.hpp"
#include "events/window/event_window_updated.hpp"
#include "events/window/event_window_resized.hpp"

#include <iostream>
#include <thread>

namespace Engine {

	struct WindowProperties {
		std::string title = "";
		unsigned int width = 0;
		unsigned int height = 0;

		bool vSync = false;

		std::shared_ptr<Input> input;

		WindowProperties(
			const std::string& _title = "Project Edward VI",
			unsigned int _width = 1280,
			unsigned int _height = 720)
		: title(_title), width(_width), height(_height) {}
	};

	class Window {

	protected:
		WindowProperties mWindowProperties;
		std::shared_ptr<Renderer> mRenderer = nullptr;
		std::shared_ptr<Input> mInput = nullptr;

		std::chrono::steady_clock::time_point mRunningTime = std::chrono::high_resolution_clock::now();

	public:
		bool running = true;

		WindowUpdatedEvent windowUpdatedEvent;
		WindowResizedEvent windowResizedEvent;
		Event windowClosedEvent;

	public:
		void Update();

		virtual unsigned int GetWidth() const = 0;
		virtual unsigned int GetHeight() const = 0;

		virtual void SetVsync(bool enabled) = 0;
		virtual bool IsVsync() const = 0;

		virtual void* GetNativeWindow() const = 0;
		virtual std::shared_ptr<Renderer> GetRenderer() const = 0;
		virtual std::shared_ptr<Input> GetInput() const = 0;

		static Window* Create(const WindowProperties& properties = WindowProperties());

	private:
		virtual void Initialize() = 0;
		virtual void UpdateRenderer() = 0;
	};

}