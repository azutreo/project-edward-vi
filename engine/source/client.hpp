#pragma once

#include "rendering/window.hpp"
#include "rendering/renderer.hpp"
#include "objects/camera.hpp"
#include "objects/object.hpp"
#include "controllers/controller_camera.hpp"

namespace Engine {

	class Client {
		Window* mWindow;
		std::shared_ptr<Renderer> mRenderer;
		std::shared_ptr<Input> mInput;
		std::shared_ptr<Camera> mCamera;
		std::shared_ptr<CameraController> mCameraController;

		std::shared_ptr<Object> mSquare;

	public:
		Client();

		void Run();

		inline Window* GetWindow() { return mWindow; }
		inline std::shared_ptr<Renderer> GetRenderer() { return mRenderer; }
		inline std::shared_ptr<Input> GetInput() { return mInput; }

	private:
		bool OnUpdate(double deltaTime);
		bool OnWindowResized(unsigned int width, unsigned int height);
	};

}