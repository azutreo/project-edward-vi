#pragma once

#include "rendering/renderer.hpp"

#include <iostream>

namespace Engine::Rendering {

	struct WindowProperties {
		std::string title = "";
		unsigned int width = 0;
		unsigned int height = 0;

		bool vSync = false;

		WindowProperties(
			const std::string& _title = "Project Edward VI",
			unsigned int _width = 1280,
			unsigned int _height = 720) : title(_title), width(_width), height(_height) {}
	};

	class Window {

	protected:
		Renderer* mRenderer;

	public:
		~Window() { delete mRenderer; }

		virtual void Create() = 0;

		virtual void Update() = 0;

		virtual unsigned int GetWidth() const = 0;
		virtual unsigned int GetHeight() const = 0;

		virtual void SetVSync(bool enabled) = 0;
		virtual bool IsVSync() const = 0;

		virtual void* GetNativeWindow() const = 0;
		virtual Renderer* GetRenderer() const = 0;

		virtual void SetWindowClosedCallback(std::function<void()> callback) = 0;
		virtual void SetWindowResizedCallback(std::function<void(int x, int y)> callback) = 0;
		virtual void SetKeyPressedCallback(std::function<void(int key)> callback) = 0;
		virtual void SetKeyReleasedCallback(std::function<void(int key)> callback) = 0;
		virtual void SetKeyRepeatedCallback(std::function<void(int key)> callback) = 0;
		virtual void SetMouseButtonPressedCallback(std::function<void(int button)> callback) = 0;
		virtual void SetMouseButtonReleasedCallback(std::function<void(int button)> callback) = 0;
		virtual void SetMouseMovedCallback(std::function<void(double x, double y)> callback) = 0;
		virtual void SetMouseScrolledCallback(std::function<void(double x, double y)> callback) = 0;
	};

}