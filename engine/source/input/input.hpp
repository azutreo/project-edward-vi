#pragma once

#include "events/event.hpp"
#include "events/input/event_input_mouse_scrolled.hpp"

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
		MouseScrolledEvent mouseScrolledEvent;

	public:
		Input(Window* window);

		bool IsKeyPressed(const KeyCode& keyCode);
		bool IsMouseButtonPressed(const MouseButton& mouseCode);

		inline Window* GetWindow() const { return mWindow; }
	};

}