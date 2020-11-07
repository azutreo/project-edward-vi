#include "engine_precompiled/engine_precompiled.hpp"
#include "controllers/controller_camera.hpp"

#include "objects/camera.hpp"
#include "rendering/window.hpp"

#include <functional>

namespace Engine {

	CameraController::CameraController(std::shared_ptr<Engine::Camera> camera, std::shared_ptr<Engine::Input> input) {
		mCamera = camera;
		mInput = input;

		mInput->mouseScrolledEvent.Connect(std::bind<bool>(&CameraController::OnMouseScrolled, this, std::placeholders::_1, std::placeholders::_2));
		mInput->GetWindow()->windowResizedEvent.Connect(std::bind<bool>(&CameraController::OnWindowResized, this, std::placeholders::_1, std::placeholders::_2));
	}

	bool CameraController::OnUpdate(float deltaTime) {
		if(mInput->IsKeyPressed(Engine::KeyCode::KEY_A)) {
			glm::vec3 position = mCamera->GetPosition();
			position.x -= (deltaTime * mCamera->moveSpeed * mCamera->GetZoomLevel());
			mCamera->SetPosition(position);
		}
		if(mInput->IsKeyPressed(Engine::KeyCode::KEY_D)) {
			glm::vec3 position = mCamera->GetPosition();
			position.x += (deltaTime * mCamera->moveSpeed * mCamera->GetZoomLevel());
			mCamera->SetPosition(position);
		}
		if(mInput->IsKeyPressed(Engine::KeyCode::KEY_W)) {
			glm::vec3 position = mCamera->GetPosition();
			position.y += (deltaTime * mCamera->moveSpeed * mCamera->GetZoomLevel());
			mCamera->SetPosition(position);
		}
		if(mInput->IsKeyPressed(Engine::KeyCode::KEY_S)) {
			glm::vec3 position = mCamera->GetPosition();
			position.y -= (deltaTime * mCamera->moveSpeed * mCamera->GetZoomLevel());
			mCamera->SetPosition(position);
		}

		return false;
	}

	bool CameraController::OnMouseScrolled(double x, double y) {
		float newZoomLevel = mCamera->GetZoomLevel() - (y * 0.1);
		if(newZoomLevel < 0.5) {
			newZoomLevel = 0.5;
		}

		mCamera->SetZoomLevel(newZoomLevel);

		return false;
	}

	bool CameraController::OnWindowResized(unsigned int width, unsigned int height) {
		mCamera->SetWindowSize(width, height);

		return false;
	}

}