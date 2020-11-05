#pragma once
#include "engine_precompiled/engine_precompiled.hpp"
#include "rendering/opengl/graphics_context_opengl.hpp"

#include "rendering/graphics_context.hpp"

#include "glad/glad.h"
#include "GLFW/glfw3.h"

namespace Engine {

	OpenGlContext::OpenGlContext(GLFWwindow* window) {
		mWindow = window;

		glfwMakeContextCurrent(mWindow);
		int status = gladLoadGLLoader((GLADloadproc)glfwGetProcAddress);

		//printf("Renderer:\n  Type: OpenGL\n  Graphics Card: %s\n  Version: %s\n", glGetString(GL_RENDERER), glGetString(GL_VERSION));
	}

	OpenGlContext::~OpenGlContext() {
		// :TODO:
	}

	void OpenGlContext::SwapBuffers() {
		glfwMakeContextCurrent(mWindow);
		glfwSwapBuffers(mWindow);
	}

}