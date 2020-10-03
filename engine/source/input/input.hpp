#pragma once

#include "events/event.hpp"

namespace Engine {

	class Window;

	enum class KeyCode;
	enum class MouseButton;

	class Input {
		Window* mWindow;

	public:
		Event keyPressedEvent;
		Event keyReleasedEvent;
		Event keyRepeatedEvent;
		Event mouseButtonPressedEvent;
		Event mouseButtonReleasedEvent;
		Event mouseMovedEvent;
		Event mouseScrolledEvent;

	public:
		Input(Window* window);

		bool IsKeyPressed(const KeyCode& keyCode);
		bool IsMouseButtonPressed(const MouseButton& mouseCode);

		inline Window* GetWindow() const { return mWindow; }
	};

}