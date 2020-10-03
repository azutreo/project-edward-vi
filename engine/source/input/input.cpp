#include "engine_precompiled/engine_precompiled.hpp"
#include "Input/Input.hpp"

#include "Input/key_codes.hpp"
#include "Input/mouse_codes.hpp"
#include "rendering/Window.hpp"

#include <GLFW/glfw3.h>

//#define BIND_EVENT(x) std::bind(&x, this)

namespace Engine {

	Input::Input(Window* window) {
		mWindow = window;

		//keyPressedEvent.Connect(BIND_EVENT(Input::OnKeyPressed));
	}

	bool Input::IsKeyPressed(const KeyCode& keyCode) {
		auto window = static_cast<GLFWwindow*>(mWindow->GetNativeWindow());
		auto state = glfwGetKey(window, (int)keyCode);

		return state == GLFW_PRESS || state == GLFW_REPEAT;
	}

	bool Input::IsMouseButtonPressed(const MouseButton& mouseButton) {
		std::cout << "coming soon?" << std::endl;
		return false;
	}

	/*bool Input::OnKeyPressed() {
		return false;
	}*/

}