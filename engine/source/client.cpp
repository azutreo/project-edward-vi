#pragma once
#include "engine_precompiled/engine_precompiled.hpp"
#include "client.hpp"

#include "mathematics/vectors/vector2.hpp"
#include "mathematics/vectors/vector3.hpp"
#include "rendering/renderer.hpp"
#include "rendering/window.hpp"
#include "rendering/texture.hpp"
#include "rendering/shader.hpp"

#include "objects/object.hpp"
#include "objects/camera.hpp"

#include "input/input.hpp"
#include "input/key_codes.hpp"

#include "controllers/controller_camera.hpp"

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>

#include <string>
#include <functional>

namespace Engine {

	std::shared_ptr<Object> CreateSquare(std::shared_ptr<Shader> shader) {
		float vertices[(3 + 2) * 4 * 1] = { // square
					   -0.25f, -0.25f,  0.0f,  0.0f,  0.0f, // 0 back bottom left
						0.25f, -0.25f,  0.0f,  1.0f,  0.0f, // 1 back bottom right
						0.25f,  0.25f,  0.0f,  1.0f,  1.0f, // 2 back top right
					   -0.25f,  0.25f,  0.0f,  0.0f,  1.0f, // 3 back top left
		};
		unsigned int indices[6] = { 0, 1, 3, 1, 2, 3 };
		BufferLayout layout = {
			{ Engine::ShaderDataType::FLOAT3, "Position" },
			{ Engine::ShaderDataType::FLOAT2, "TextureCoordinate" },
		};

		return std::make_shared<Object>("Square", vertices, sizeof(vertices), indices, sizeof(indices) / sizeof(uint32_t), shader, &layout, "../content/images/nicholas.jpeg");
	}

	Client::Client() {
		mWindow = Window::Create();

		mRenderer = mWindow->GetRenderer();
		mInput = mWindow->GetInput();

		mCamera = std::make_shared<Engine::Camera>(mWindow->GetWidth(), mWindow->GetHeight());
		mCameraController = std::make_shared<Engine::CameraController>(mCamera, mInput);

		std::shared_ptr<Shader> shader = mRenderer->GetShaderLibrary()->LoadShader("../content/shaders/texture.glsl");
		mSquare = CreateSquare(shader);

		mWindow->windowUpdatedEvent.Connect(std::bind<bool>(&Client::OnUpdate, this, std::placeholders::_1));
		mWindow->windowResizedEvent.Connect(std::bind<bool>(&Client::OnWindowResized, this, std::placeholders::_1, std::placeholders::_2));
	}

	bool Client::OnUpdate(double deltaTime) {
		if(mWindow->minimized) { return false; }

		mRenderer->SetClearColor(0.05f, 0.05f, 0.075f, 1.0f);
		mRenderer->ClearScreen();

		mRenderer->StartScene(mCamera);
		{
			// :TODO: For each object in the scene
			glm::mat4 transform = glm::translate(glm::mat4(1.0f), mSquare->GetPosition());
			mSquare->GetTexture()->Bind();
			mRenderer->Submit(mSquare->GetVertexArray(), mSquare->GetShader(), transform);

		}
		mRenderer->EndScene();

		mCameraController->OnUpdate(deltaTime);

		return false;
	}

	bool Client::OnWindowResized(unsigned int width, unsigned int height) {
		if(width == 0 || height == 0) {
			mWindow->minimized = true;

			return false;
		} else {
			mWindow->minimized = false;
		}

		mWindow->SetWidth(width);
		mWindow->SetHeight(height);
		mRenderer->SetViewportSize(0, 0, width, height);

		return false;
	}

	void Client::Run() {
		while(mWindow->running) {
			mWindow->Update();
		}

		delete mWindow;
	}

}