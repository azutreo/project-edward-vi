#pragma once

namespace Engine {
	class Application;
}

namespace Engine::Input {

	enum class KeyCode;
	enum class MouseCode;

	bool IsButtonPressed(Engine::Application* application, const KeyCode& keyCode);
	bool IsMouseButtonPressed(const MouseCode& mouseCode);

}