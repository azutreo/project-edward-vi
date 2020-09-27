#pragma once
#include "engine_precompiled/engine_precompiled.hpp"

#include "windows/window_opengl.hpp"
#include "GLFW/glfw3.h"

namespace Engine::Windows {

	OpenGlWindow::OpenGlWindow(const WindowProperties& properties) {
		mWindowData.title = properties.title;
		mWindowData.width = properties.width;
		mWindowData.height = properties.height;

		Create();
	};

	OpenGlWindow::~OpenGlWindow() {

		glfwDestroyWindow(mWindow);

	};

	void OpenGlWindow::Create() {
		if(!sgGlfwInitialized) {
			int success = glfwInit();

			if(success) {
				sgGlfwInitialized = true;
			}
		}

		mWindow = glfwCreateWindow((int)mWindowData.width, (int)mWindowData.height, mWindowData.title.c_str(), nullptr, nullptr);
		glfwMakeContextCurrent(mWindow);
		glfwSetWindowUserPointer(mWindow, &mWindowData);
		SetVSync(true);
	}

	void OpenGlWindow::Update() {

		glfwMakeContextCurrent(mWindow);

		glClearColor(0.1, 0.1, 0.1, 1);
		glClear(GL_COLOR_BUFFER_BIT);

		glBegin(GL_QUADS);
		glColor3f(1.0f, 1.0f, 1.0f);
		glVertex2f(-0.5f, -0.5f);
		glVertex2f(0.5f, -0.5f);
		glVertex2f(0.5f, 0.5f);
		glVertex2f(-0.5f, 0.5f);
		glEnd();

		glFlush();

		glfwPollEvents();
		glfwSwapBuffers(mWindow);

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