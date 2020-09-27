#pragma once
#include "engine_precompiled/engine_precompiled.hpp"
#include "rendering/opengl/window_opengl.hpp"

#include "rendering/opengl/graphics_context_opengl.hpp"
#include "rendering/opengl/shader_opengl.hpp"
#include "rendering/opengl/buffer_opengl.hpp"

#include <glad/glad.h>
#include <GLFW/glfw3.h>

namespace Engine::Renderer {

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

		glGenVertexArrays(1, &mVertexArray);
		glBindVertexArray(mVertexArray);

		float vertices[3 * 3] = {
			-0.5f, -0.5f, -0.5f,
			0.5f, -0.5f, 0.0f,
			0.0f, 0.5f, 0.0f
		};

		mVertexBuffer.reset(new OpenGlVertexBuffer(vertices, sizeof(vertices)));

		glEnableVertexAttribArray(0);
		glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), nullptr);

		unsigned int indices[3] = { 0, 1, 2 };

		mIndexBuffer.reset(new OpenGlIndexBuffer(indices, sizeof(indices) / sizeof(uint32_t)));

		std::string vertexSource = R"(
			#version 330 core
		
			layout(location = 0) in vec3 a_Position;

			out vec3 v_Position;

			void main() {
				v_Position = a_Position;
				gl_Position = vec4(a_Position, 1.0);
			}
		)";

		std::string fragmentSource = R"(
			#version 330 core
		
			layout(location = 0) out vec4 color;
			in vec3 v_Position;

			void main() {
				color = vec4(v_Position * 0.5 + 0.5, 1.0);
			}
		)";

		mShader.reset(new OpenGlShader(vertexSource, fragmentSource));
	}

	void OpenGlWindow::Update() {
		glfwMakeContextCurrent(mWindow);

		mShader->Bind();
		glfwPollEvents();
		mContext->SwapBuffers();

		glClearColor((GLfloat)0.05f, (GLfloat)0.05f, (GLfloat)0.075f, (GLfloat)1);
		glClear(GL_COLOR_BUFFER_BIT);

		glBindVertexArray(mVertexArray);
		glDrawElements(GL_TRIANGLES, mIndexBuffer->GetCount(), GL_UNSIGNED_INT, nullptr);
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