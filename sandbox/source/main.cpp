#include "precompiled/precompiled.hpp"

#include "mathematics/vectors/vector2.hpp"
#include "mathematics/vectors/vector3.hpp"
#include "rendering/window.hpp"
#include "rendering/texture.hpp"
#include "rendering/shader.hpp"

#include "objects/object.hpp"
#include "objects/camera.hpp"

#include "input/input.hpp"
#include "input/key_codes.hpp"

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>

#include <string>

Engine::Object CreateSquare(std::shared_ptr<Engine::Shader> shader) {
	float vertices[(3 + 2) * 4 * 1] = { // square
				   -0.25f, -0.25f,  0.0f,  0.0f,  0.0f, // 0 back bottom left
					0.25f, -0.25f,  0.0f,  1.0f,  0.0f, // 1 back bottom right
					0.25f,  0.25f,  0.0f,  1.0f,  1.0f, // 2 back top right
				   -0.25f,  0.25f,  0.0f,  0.0f,  1.0f, // 3 back top left
	};
	unsigned int indices[6] = { 0, 1, 3, 1, 2, 3 };
	Engine::BufferLayout layout = {
		{ Engine::ShaderDataType::FLOAT3, "Position" },
		{ Engine::ShaderDataType::FLOAT2, "TextureCoordinate" },
	};

	return Engine::Object("Square", vertices, sizeof(vertices), indices, sizeof(indices) / sizeof(uint32_t), shader, &layout, "../content/images/nicholas.jpeg");
}

int main(int argc, char** argv) {
	Engine::Window* window = Engine::Window::Create();

	std::shared_ptr<Engine::Renderer> renderer = window->GetRenderer();
	std::shared_ptr<Engine::Input> input = window->GetInput();

	Engine::Camera mCamera(window);

	float squareMoveSpeed = 2.0f;

	std::shared_ptr<Engine::Shader> shader = renderer->GetShaderLibrary()->LoadShader("../content/shaders/texture.glsl");
	Engine::Object square = CreateSquare(shader);
	Engine::Object square2 = CreateSquare(shader);

	window->windowUpdatedEvent.Connect([=, &renderer, &mCamera, &square, &square2](double deltaTime) {
		renderer->SetClearColor(0.05f, 0.05f, 0.075f, 1.0f);
		renderer->ClearScreen();

		renderer->StartScene(mCamera);
		{ // :TODO: For each object in the scene
			glm::mat4 transform2 = glm::translate(glm::mat4(1.0f), square2.GetPosition());
			square2.GetTexture()->Bind();
			renderer->Submit(square2.GetVertexArray(), square2.GetShader(), transform2);

			glm::mat4 transform = glm::translate(glm::mat4(1.0f), square.GetPosition());
			square.GetTexture()->Bind();
			renderer->Submit(square.GetVertexArray(), square.GetShader(), transform);
		}
		renderer->EndScene();

		if(input->IsKeyPressed(Engine::KeyCode::KEY_A)) {
			glm::vec3 position = mCamera.GetPosition();
			position.x -= (deltaTime * mCamera.moveSpeed);
			mCamera.SetPosition(position);
		}
		if(input->IsKeyPressed(Engine::KeyCode::KEY_D)) {
			glm::vec3 position = mCamera.GetPosition();
			position.x += (deltaTime * mCamera.moveSpeed);
			mCamera.SetPosition(position);
		}
		if(input->IsKeyPressed(Engine::KeyCode::KEY_W)) {
			glm::vec3 position = mCamera.GetPosition();
			position.y += (deltaTime * mCamera.moveSpeed);
			mCamera.SetPosition(position);
		}
		if(input->IsKeyPressed(Engine::KeyCode::KEY_S)) {
			glm::vec3 position = mCamera.GetPosition();
			position.y -= (deltaTime * mCamera.moveSpeed);
			mCamera.SetPosition(position);
		}
		if(input->IsKeyPressed(Engine::KeyCode::KEY_Q)) {
			glm::vec3 rotation = mCamera.GetRotation();
			rotation.z += (deltaTime * mCamera.rotateSpeed);
			mCamera.SetRotation(rotation);
		}
		if(input->IsKeyPressed(Engine::KeyCode::KEY_E)) {
			glm::vec3 rotation = mCamera.GetRotation();
			rotation.z -= (deltaTime * mCamera.rotateSpeed);
			mCamera.SetRotation(rotation);
		}

		if(input->IsKeyPressed(Engine::KeyCode::KEY_LEFT)) {
			glm::vec3 position = square.GetPosition();
			position.x -= (deltaTime * squareMoveSpeed);
			square.SetPosition(position);
		}
		if(input->IsKeyPressed(Engine::KeyCode::KEY_RIGHT)) {
			glm::vec3 position = square.GetPosition();
			position.x += (deltaTime * squareMoveSpeed);
			square.SetPosition(position);
		}
		if(input->IsKeyPressed(Engine::KeyCode::KEY_UP)) {
			glm::vec3 position = square.GetPosition();
			position.y += (deltaTime * squareMoveSpeed);
			square.SetPosition(position);
		}
		if(input->IsKeyPressed(Engine::KeyCode::KEY_DOWN)) {
			glm::vec3 position = square.GetPosition();
			position.y -= (deltaTime * squareMoveSpeed);
			square.SetPosition(position);
		}

		return false;
	});

	while(window->running) {
		window->Update();
	}

	delete window;

	return 0;
}