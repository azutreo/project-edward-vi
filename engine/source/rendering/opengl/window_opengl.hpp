#pragma once

#include "rendering/window.hpp"

struct GLFWwindow;

namespace Engine {

	class Input;

	class Renderer;
	class OpenGlContext;

	static bool sgGlfwInitialized = false;

	class OpenGlWindow : public Window {
		GLFWwindow* mWindow;
		std::shared_ptr<OpenGlContext> mContext;

	public:
		OpenGlWindow(const WindowProperties& properties = WindowProperties());
		~OpenGlWindow();

		inline unsigned int GetWidth() const override { return mWindowProperties.width; };
		inline unsigned int GetHeight() const override { return mWindowProperties.height; };
		inline void SetWidth(unsigned int width) override { mWindowProperties.width = width; };
		inline void SetHeight(unsigned int height) override { mWindowProperties.height = height; };

		inline bool IsVsync() const override { return mWindowProperties.vSync; };
		void SetVsync(bool enabled) override;

		inline void* GetNativeWindow() const override { return mWindow; }
		inline std::shared_ptr<Renderer> GetRenderer() const override { return mRenderer; }
		inline std::shared_ptr<Input> GetInput() const override { return mInput; }

	private:
		void Initialize() override;
		void UpdateRenderer() override;
	};

}