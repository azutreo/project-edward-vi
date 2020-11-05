#pragma once

#include "objects/camera.hpp"

#include "input/input.hpp"
#include "input/key_codes.hpp"

namespace Engine {

	class CameraController {
		std::shared_ptr<Engine::Camera> mCamera;
		std::shared_ptr<Engine::Input> mInput;

	public:
		CameraController(std::shared_ptr<Engine::Camera>, std::shared_ptr<Engine::Input> input);

		void OnUpdate(float deltaTime);
	};

}