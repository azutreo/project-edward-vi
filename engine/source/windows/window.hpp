#pragma once

#include <iostream>

namespace Engine::Windows {

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

	struct Window {

		virtual ~Window() = default;

		virtual void Create() = 0;

		virtual void Update() = 0;

		virtual unsigned int GetWidth() const = 0;
		virtual unsigned int GetHeight() const = 0;

		virtual void SetVSync(bool enabled) = 0;
		virtual bool IsVSync() const = 0;

	};

}