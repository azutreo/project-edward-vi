#pragma once
#include "engine_precompiled/engine_precompiled.hpp"

#include "input/input.hpp"

#include "input/key_codes.hpp"
#include "input/mouse_codes.hpp"

#include "application/application.hpp"

#include <GLFW/glfw3.h>

namespace Engine::Input {

	bool IsButtonPressed(Engine::Application* application, const KeyCode& keyCode) {
		auto window = static_cast<GLFWwindow*>(application->GetWindow()->GetNativeWindow());
		auto state = glfwGetKey(window, (int)keyCode);

		return state == GLFW_PRESS || state == GLFW_REPEAT;
	}

	bool IsMouseButtonPressed(const MouseCode& mouseCode) {
		std::cout << "coming soon?" << std::endl;
		return false;
	}

}