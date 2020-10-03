#pragma once

#include "events/event.hpp"

namespace Engine {

	class Window;

	enum class KeyCode;
	enum class MouseButton;

	class Input {
		Window* mWindow;

	public:
		Event windowClosedEvent;
		Event windowResizedEvent;
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

	/*private:
		//bool OnWindowClosed();
		//bool OnWindowResized();
		bool OnKeyPressed();
		//bool OnKeyReleased();
		//bool OnKeyRepeated();
		//bool OnMouseButtonPressed();
		//bool OnMouseButtonReleased();
		//bool OnMouseMoved();
		//bool OnMouseScrolled();*/
	};

}