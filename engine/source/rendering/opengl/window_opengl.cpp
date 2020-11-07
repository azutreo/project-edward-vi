#pragma once
#include "engine_precompiled/engine_precompiled.hpp"
#include "rendering/opengl/window_opengl.hpp"

#include "rendering/opengl/graphics_context_opengl.hpp"

#include "input/input.hpp"

#include <glad/glad.h>
#include <GLFW/glfw3.h>

namespace Engine {

	OpenGlWindow::OpenGlWindow(const WindowProperties& properties) {
		mWindowProperties.title = properties.title;
		mWindowProperties.width = properties.width;
		mWindowProperties.height = properties.height;
		mWindowProperties.vSync = properties.vSync;

		Initialize();
	};

	OpenGlWindow::~OpenGlWindow() {
		glfwDestroyWindow(mWindow);
	};

	void OpenGlWindow::Initialize() {
		if(!sgGlfwInitialized) {
			int success = glfwInit();

			if(success) {
				sgGlfwInitialized = true;
			}
		}

		mWindow = glfwCreateWindow((int)mWindowProperties.width, (int)mWindowProperties.height, mWindowProperties.title.c_str(), nullptr, nullptr);

		mContext.reset(new OpenGlContext(mWindow));
		mRenderer.reset(Renderer::Create());
		mInput.reset(new Input(this));

		mWindowProperties.input = mInput;

		glfwSetWindowUserPointer(mWindow, &mWindowProperties);
		SetVsync(mWindowProperties.vSync);

		glfwSetWindowCloseCallback(mWindow, [](GLFWwindow* window) {
			WindowProperties& properties = *(WindowProperties*)glfwGetWindowUserPointer(window);

			properties.input->GetWindow()->windowClosedEvent.Fire();
		});

		glfwSetWindowSizeCallback(mWindow, [](GLFWwindow* window, int width, int height) {
			WindowProperties& properties = *(WindowProperties*)glfwGetWindowUserPointer(window);

			properties.width = width;
			properties.height = height;
			properties.input->GetWindow()->windowResizedEvent.Fire(width, height);
		});

		glfwSetKeyCallback(mWindow, [](GLFWwindow* window, int key, int scanCode, int action, int mods) {
			WindowProperties& properties = *(WindowProperties*)glfwGetWindowUserPointer(window);

			switch(action) {
				case GLFW_PRESS:
					properties.input->keyPressedEvent.Fire();//(key);
					break;
				case GLFW_RELEASE:
					properties.input->keyReleasedEvent.Fire();//(key);
					break;
				case GLFW_REPEAT:
					properties.input->keyRepeatedEvent.Fire();//(key);
					break;
			};
		});

		glfwSetMouseButtonCallback(mWindow, [](GLFWwindow* window, int button, int action, int mods) {
			WindowProperties& properties = *(WindowProperties*)glfwGetWindowUserPointer(window);

			switch(action) {
				case GLFW_PRESS:
					properties.input->mouseButtonPressedEvent.Fire();//(button);
					break;
				case GLFW_RELEASE:
					properties.input->mouseButtonReleasedEvent.Fire();//(button);
					break;
			}
		});

		glfwSetCursorPosCallback(mWindow, [](GLFWwindow* window, double x, double y) {
			WindowProperties& properties = *(WindowProperties*)glfwGetWindowUserPointer(window);

			properties.input->mouseMovedEvent.Fire();//(x, y);
		});

		glfwSetScrollCallback(mWindow, [](GLFWwindow* window, double x, double y) {
			WindowProperties& properties = *(WindowProperties*)glfwGetWindowUserPointer(window);

			properties.input->mouseScrolledEvent.Fire(x, y);
		});

		mWindowProperties.input->GetWindow()->windowClosedEvent.Connect([&]() {
			running = false;

			return false;
		});
	}

	void OpenGlWindow::UpdateRenderer() {
		glfwMakeContextCurrent(mWindow);

		glfwPollEvents();
		mContext->SwapBuffers();
	};


	void OpenGlWindow::SetVsync(bool enabled) {
		if(enabled) {
			glfwSwapInterval(1);
		} else {
			glfwSwapInterval(0);
		}

		mWindowProperties.vSync = enabled;
	};

}