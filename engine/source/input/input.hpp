#pragma once

enum KeyCode;
enum MouseCode;

namespace Engine::Input {

	bool IsButtonPressed(const KeyCode& keyCode);
	bool IsMouseButtonPressed(const MouseCode& mouseCode);

}