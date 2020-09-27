#pragma once

#include "windows/window.hpp"

typedef struct GLFWwindow;

namespace Engine::Windows {

	static bool sgGlfwInitialized = false;

	struct OpenGlWindowData {

		std::string title;
		unsigned int width;
		unsigned int height;

		bool vSync = false;

	};

	class OpenGlWindow : public Window {

		GLFWwindow* mWindow;
		OpenGlWindowData mWindowData;

	public:

		OpenGlWindow(const WindowProperties& properties = WindowProperties());
		~OpenGlWindow();

		void Create() override;

		void Update() override;

		inline unsigned int GetWidth() const override { return mWindowData.width; };
		inline unsigned int GetHeight() const override { return mWindowData.height; };

		inline bool IsVSync() const override { return mWindowData.vSync; };
		void SetVSync(bool enabled) override;

	};

}