#pragma once

#include "rendering/window.hpp"

#include "rendering/shader.hpp"
#include "rendering/buffer.hpp"

#include "rendering/opengl/graphics_context_opengl.hpp"
#include "rendering/opengl/shader_opengl.hpp"
#include "rendering/opengl/buffer_opengl.hpp"
#include "rendering/opengl/renderer_opengl.hpp"

#include "objects/camera.hpp"

struct GLFWwindow;

namespace Engine::Rendering {

	static bool sgGlfwInitialized = false;

	struct OpenGlWindowData {
		std::string title = "";
		unsigned int width = 0;
		unsigned int height = 0;

		bool vSync = false;

		std::function<void()> windowClosedCallback;
		std::function<void(int x, int y)> windowResizedCallback;
		std::function<void(int key)> keyPressedCallback;
		std::function<void(int key)> keyReleasedCallback;
		std::function<void(int key)> keyRepeatedCallback;
		std::function<void(int button)> mouseButtonPressedCallback;
		std::function<void(int button)> mouseButtonReleasedCallback;
		std::function<void(double x, double y)> mouseMovedCallback;
		std::function<void(double x, double y)> mouseScrolledCallback;
	};

	class OpenGlWindow : public Window {
		OpenGlWindowData mWindowData;

		GLFWwindow* mWindow;
		OpenGlContext* mContext;

	public:
		OpenGlWindow(const WindowProperties& properties = WindowProperties());
		~OpenGlWindow();

		void Create() override;

		void Update() override;

		inline unsigned int GetWidth() const override { return mWindowData.width; };
		inline unsigned int GetHeight() const override { return mWindowData.height; };

		inline bool IsVSync() const override { return mWindowData.vSync; };
		void SetVSync(bool enabled) override;

		inline void* GetNativeWindow() const override { return mWindow; }
		inline Renderer* GetRenderer() const override { return mRenderer; }

		inline void SetWindowClosedCallback(std::function<void()> callback) { mWindowData.windowClosedCallback = callback; };
		inline void SetWindowResizedCallback(std::function<void(int x, int y)> callback) { mWindowData.windowResizedCallback = callback; };
		inline void SetKeyPressedCallback(std::function<void(int key)> callback) { mWindowData.keyPressedCallback = callback; };
		inline void SetKeyReleasedCallback(std::function<void(int key)> callback) { mWindowData.keyReleasedCallback = callback; };
		inline void SetKeyRepeatedCallback(std::function<void(int key)> callback) { mWindowData.keyRepeatedCallback = callback; };
		inline void SetMouseButtonPressedCallback(std::function<void(int button)> callback) { mWindowData.mouseButtonPressedCallback = callback; };
		inline void SetMouseButtonReleasedCallback(std::function<void(int button)> callback) { mWindowData.mouseButtonReleasedCallback = callback; };
		inline void SetMouseMovedCallback(std::function<void(double x, double y)> callback) { mWindowData.mouseMovedCallback = callback; };
		inline void SetMouseScrolledCallback(std::function<void(double x, double y)> callback) { mWindowData.mouseScrolledCallback = callback; };
	};

}