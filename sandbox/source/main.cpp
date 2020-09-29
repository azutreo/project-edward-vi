#pragma once
#include "precompiled/precompiled.hpp"

#include "mathematics/vectors/vector2.hpp"
#include "application/application.hpp"

#include "objects/camera.hpp"

#include "input/input.hpp"
#include "input/key_codes.hpp"

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>

#include <thread>

int main(int argc, char** argv) {
	Engine::Mathematics::Vector2<float> position(0.1f, 0.0f);
	Engine::Mathematics::Vector2<float> velocity(10.0f, 100.0f);

	Engine::Application* application = new Engine::Application();
	Engine::Rendering::Renderer* mRenderer = application->GetWindow()->GetRenderer();

	std::shared_ptr<Engine::Rendering::Shader> shader;
	std::shared_ptr<Engine::Rendering::VertexArray> squareVA;
	std::shared_ptr<Engine::Rendering::VertexBuffer> squareVB;
	std::shared_ptr<Engine::Rendering::IndexBuffer> squareIB;

	Engine::OrthographicCamera mCamera = { -1.6f, 1.6f, -0.9f, 0.9f };

	float vertices[(3 + 4) * 4] = { // square
			-0.5f, -0.5f,  0.0f,  0.8f,  0.0f,  0.0f,  1.0f, // 0 bottom left
			 0.5f, -0.5f,  0.0f,  0.0f,  0.0f,  0.8f,  1.0f, // 1 bottom right
			 0.5f,  0.5f,  0.0f,  0.0f,  0.0f,  0.8f,  1.0f, // 2 top right
			-0.5f,  0.5f,  0.0f,  0.8f,  0.0f,  0.0f,  1.0f, // 3 top left
	};
	unsigned int indices[6] = { 0, 1, 3, 1, 2, 3 };
	Engine::Rendering::BufferLayout layout = {
		{ Engine::Rendering::ShaderDataType::FLOAT3, "Position" },
		{ Engine::Rendering::ShaderDataType::FLOAT4, "Color" },
	};

	squareVA.reset(Engine::Rendering::VertexArray::Create());
	squareVA->Unbind();

	squareVB.reset(Engine::Rendering::VertexBuffer::Create(vertices, sizeof(vertices)));
	squareVB->SetLayout(layout);
	squareVA->AddVertexBuffer(squareVB);

	squareIB.reset(Engine::Rendering::IndexBuffer::Create(indices, sizeof(indices) / sizeof(uint32_t)));
	squareVA->AddVertexBuffer(squareVB);
	squareVA->SetIndexBuffer(squareIB);

	std::string vertexSource = R"(
			#version 330 core
		
			layout(location = 0) in vec3 a_Position;
			layout(location = 1) in vec4 a_Color;

			out vec3 v_Position;
			out vec4 v_Color;

			uniform mat4 u_ViewProjection;
			uniform mat4 u_Transform;

			void main() {
				v_Position = a_Position;
				v_Color = a_Color;
				gl_Position = u_ViewProjection * u_Transform * vec4(a_Position, 1.0);
			}
		)";

	std::string fragmentSource = R"(
			#version 330 core
		
			layout(location = 0) out vec4 color;

			in vec3 v_Position;
			in vec4 v_Color;

			uniform mat4 u_ViewProjection;

			void main() {
				color = v_Color;
			}
		)";

	shader.reset(Engine::Rendering::Shader::Create(vertexSource, fragmentSource));

	float squareMoveSpeed = 1.0f;
	glm::vec3 squarePosition = { 0.0f, 0.0f, 0.0f };

	application->Updated.Connect([&](double deltaTime) {
		mRenderer->SetClearColor(0.05f, 0.05f, 0.075f, 1.0f);
		mRenderer->ClearScreen();

		mRenderer->StartScene(mCamera);
		{ // :TODO: For each object in the scene
			glm::mat4 transform = glm::translate(glm::mat4(1.0f), squarePosition);
			mRenderer->Submit(squareVA, shader, transform);
		}
		mRenderer->EndScene();

		if(Engine::Input::IsButtonPressed(application, Engine::Input::KeyCode::KEY_A)) {
			glm::vec3 position = mCamera.GetPosition();
			mCamera.SetPosition({ position.x - (deltaTime * mCamera.MoveSpeed), position.y, position.z });
		}
		if(Engine::Input::IsButtonPressed(application, Engine::Input::KeyCode::KEY_D)) {
			glm::vec3 position = mCamera.GetPosition();
			mCamera.SetPosition({ position.x + (deltaTime * mCamera.MoveSpeed), position.y, position.z });
		}
		if(Engine::Input::IsButtonPressed(application, Engine::Input::KeyCode::KEY_W)) {
			glm::vec3 position = mCamera.GetPosition();
			mCamera.SetPosition({ position.x, position.y + (deltaTime * mCamera.MoveSpeed), position.z });
		}
		if(Engine::Input::IsButtonPressed(application, Engine::Input::KeyCode::KEY_S)) {
			glm::vec3 position = mCamera.GetPosition();
			mCamera.SetPosition({ position.x, position.y - (deltaTime * mCamera.MoveSpeed), position.z });
		}
		if(Engine::Input::IsButtonPressed(application, Engine::Input::KeyCode::KEY_Q)) {
			glm::vec3 rotation = mCamera.GetRotation();
			mCamera.SetRotation({ rotation.x, rotation.x, rotation.z - (deltaTime * mCamera.RotateSpeed) });
		}
		if(Engine::Input::IsButtonPressed(application, Engine::Input::KeyCode::KEY_E)) {
			glm::vec3 rotation = mCamera.GetRotation();
			mCamera.SetRotation({ rotation.x, rotation.x, rotation.z + (deltaTime * mCamera.RotateSpeed) });
		}

		if(Engine::Input::IsButtonPressed(application, Engine::Input::KeyCode::KEY_LEFT)) {
			squarePosition = { squarePosition.x - (deltaTime * mCamera.MoveSpeed), squarePosition.y, squarePosition.z };
		}
		if(Engine::Input::IsButtonPressed(application, Engine::Input::KeyCode::KEY_RIGHT)) {
			squarePosition = { squarePosition.x + (deltaTime * mCamera.MoveSpeed), squarePosition.y, squarePosition.z };
		}
		if(Engine::Input::IsButtonPressed(application, Engine::Input::KeyCode::KEY_UP)) {
			squarePosition = { squarePosition.x, squarePosition.y + (deltaTime * mCamera.MoveSpeed), squarePosition.z };
		}
		if(Engine::Input::IsButtonPressed(application, Engine::Input::KeyCode::KEY_DOWN)) {
			squarePosition = { squarePosition.x, squarePosition.y - (deltaTime * mCamera.MoveSpeed), squarePosition.z };
		}

		//glm::vec3 cameraPosition = mCamera.GetPosition();
		//printf("Camera Position: (%f, %f, %f) Square Position: (%f, %f, %f)\n", cameraPosition.x, cameraPosition.y, cameraPosition.z, squarePosition.x, squarePosition.y, squarePosition.z);

		return false;
	});

	application->Run();
	delete application;

	return 0;
}