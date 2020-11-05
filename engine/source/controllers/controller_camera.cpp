#include "engine_precompiled/engine_precompiled.hpp"
#include "controllers/controller_camera.hpp"

#include "objects/camera.hpp"

namespace Engine {

	CameraController::CameraController(std::shared_ptr<Engine::Camera> camera, std::shared_ptr<Engine::Input> input) {
		mCamera = camera;
		mInput = input;
	}

	void CameraController::OnUpdate(float deltaTime) {
		if(mInput->IsKeyPressed(Engine::KeyCode::KEY_A)) {
			glm::vec3 position = mCamera->GetPosition();
			position.x -= (deltaTime * mCamera->moveSpeed);
			mCamera->SetPosition(position);
		}
		if(mInput->IsKeyPressed(Engine::KeyCode::KEY_D)) {
			glm::vec3 position = mCamera->GetPosition();
			position.x += (deltaTime * mCamera->moveSpeed);
			mCamera->SetPosition(position);
		}
		if(mInput->IsKeyPressed(Engine::KeyCode::KEY_W)) {
			glm::vec3 position = mCamera->GetPosition();
			position.y += (deltaTime * mCamera->moveSpeed);
			mCamera->SetPosition(position);
		}
		if(mInput->IsKeyPressed(Engine::KeyCode::KEY_S)) {
			glm::vec3 position = mCamera->GetPosition();
			position.y -= (deltaTime * mCamera->moveSpeed);
			mCamera->SetPosition(position);
		}
	}

}