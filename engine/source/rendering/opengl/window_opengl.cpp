#pragma once
#include "engine_precompiled/engine_precompiled.hpp"
#include "rendering/opengl/window_opengl.hpp"

#include "rendering/opengl/graphics_context_opengl.hpp"
#include "rendering/opengl/shader_opengl.hpp"
#include "rendering/opengl/buffer_opengl.hpp"
#include "rendering/opengl/renderer_opengl.hpp"

#include "objects/camera.hpp"

#include <glad/glad.h>
#include <GLFW/glfw3.h>

namespace Engine::Rendering {

	OpenGlWindow::OpenGlWindow(const WindowProperties& properties) {
		mWindowData.title = properties.title;
		mWindowData.width = properties.width;
		mWindowData.height = properties.height;

		Create();
	};

	OpenGlWindow::~OpenGlWindow() {
		glfwDestroyWindow(mWindow);
		delete mContext;
	};

	void OpenGlWindow::Create() {
		if(!sgGlfwInitialized) {
			int success = glfwInit();

			if(success) {
				sgGlfwInitialized = true;
			}
		}

		mWindow = glfwCreateWindow((int)mWindowData.width, (int)mWindowData.height, mWindowData.title.c_str(), nullptr, nullptr);

		mContext = new OpenGlContext(mWindow);
		mRenderer = Renderer::Create();

		glfwSetWindowUserPointer(mWindow, &mWindowData);
		SetVSync(true);

		glfwSetWindowCloseCallback(mWindow, [](GLFWwindow* window) {
			OpenGlWindowData& windowData = *(OpenGlWindowData*)glfwGetWindowUserPointer(window);

			windowData.windowClosedCallback();
		});

		glfwSetWindowSizeCallback(mWindow, [](GLFWwindow* window, int width, int height) {
			OpenGlWindowData& windowData = *(OpenGlWindowData*)glfwGetWindowUserPointer(window);

			windowData.width = width;
			windowData.height = height;
			windowData.windowResizedCallback(width, height);
		});

		glfwSetKeyCallback(mWindow, [](GLFWwindow* window, int key, int scanCode, int action, int mods) {
			OpenGlWindowData& windowData = *(OpenGlWindowData*)glfwGetWindowUserPointer(window);

			switch(action) {
				case GLFW_PRESS:
					windowData.keyPressedCallback(key);
					break;
				case GLFW_RELEASE:
					windowData.keyReleasedCallback(key);
					break;
				case GLFW_REPEAT:
					windowData.keyRepeatedCallback(key);
					break;
			};
		});

		glfwSetMouseButtonCallback(mWindow, [](GLFWwindow* window, int button, int action, int mods) {
			OpenGlWindowData& windowData = *(OpenGlWindowData*)glfwGetWindowUserPointer(window);

			switch(action) {
				case GLFW_PRESS:
					windowData.mouseButtonPressedCallback(button);
					break;
				case GLFW_RELEASE:
					windowData.mouseButtonReleasedCallback(button);
					break;
			}
		});

		glfwSetCursorPosCallback(mWindow, [](GLFWwindow* window, double x, double y) {
			OpenGlWindowData& windowData = *(OpenGlWindowData*)glfwGetWindowUserPointer(window);

			windowData.mouseMovedCallback(x, y);
		});

		glfwSetScrollCallback(mWindow, [](GLFWwindow* window, double x, double y) {
			OpenGlWindowData& windowData = *(OpenGlWindowData*)glfwGetWindowUserPointer(window);

			windowData.mouseScrolledCallback(x, y);
		});
	}

	void OpenGlWindow::Update() {
		glfwMakeContextCurrent(mWindow);

		glfwPollEvents();
		mContext->SwapBuffers();
	};


	void OpenGlWindow::SetVSync(bool enabled) {
		if(enabled) {
			glfwSwapInterval(1);
		} else {
			glfwSwapInterval(0);
		}

		mWindowData.vSync = enabled;
	};

}