#include "precompiled/precompiled.hpp"

#include "mathematics/vectors/vector2.hpp"
#include "mathematics/vectors/vector3.hpp"
#include "rendering/window.hpp"

#include "objects/object.hpp"
#include "objects/camera.hpp"

#include "input/input.hpp"
#include "input/key_codes.hpp"

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>

#include <fstream>
#include <string>

Engine::Object getSquare() {
	float vertices[(3 + 4) * 4 * 1] = { // square
				   -0.5f, -0.5f,  0.0f,  0.1f,  0.1f,  0.1f,  1.0f, // 0 back bottom left
					0.5f, -0.5f,  0.0f,  0.3f,  0.3f,  0.3f,  1.0f, // 1 back bottom right
					0.5f,  0.5f,  0.0f,  0.5f,  0.5f,  0.5f,  1.0f, // 2 back top right
				   -0.5f,  0.5f,  0.0f,  0.7f,  0.7f,  0.7f,  1.0f, // 3 back top left

				   /*-0.5f, -0.5f,  0.0f,  0.8f,  0.8f,  0.8f,  1.0f, // 0 front bottom left
					0.5f, -0.5f,  0.0f,  0.8f,  0.8f,  0.8f,  1.0f, // 1 front bottom right
					0.5f,  0.5f,  0.0f,  0.8f,  0.8f,  0.8f,  1.0f, // 2 front top right
				   -0.5f,  0.5f,  0.0f,  0.8f,  0.8f,  0.8f,  1.0f, // 3 front top left*/
	};
	unsigned int indices[6] = { 0, 1, 3, 1, 2, 3 };
	Engine::BufferLayout layout = {
		{ Engine::ShaderDataType::FLOAT3, "Position" },
		{ Engine::ShaderDataType::FLOAT4, "Color" },
	};

	std::ifstream vertexSource("../content/content/shaders/test.vert.glsl");
	std::string vertexSourceContent((std::istreambuf_iterator<char>(vertexSource)),
									(std::istreambuf_iterator<char>()));

	std::ifstream fragmentSource("../content/content/shaders/test.frag.glsl");
	std::string fragmentSourceContent((std::istreambuf_iterator<char>(fragmentSource)),
										(std::istreambuf_iterator<char>()));

	std::shared_ptr<Engine::Shader> shader;
	shader.reset(Engine::Shader::Create(vertexSourceContent, fragmentSourceContent));

	return Engine::Object("Square", vertices, sizeof(vertices), indices, sizeof(indices) / sizeof(uint32_t), shader, &layout);
}

int main(int argc, char** argv) {
	Engine::Window* window = Engine::Window::Create();

	std::shared_ptr<Engine::Renderer> renderer = window->GetRenderer();
	std::shared_ptr<Engine::Input> input = window->GetInput();

	Engine::Camera mCamera(window);

	float squareMoveSpeed = 2.0f;

	Engine::Object square = getSquare();

	window->windowUpdatedEvent.Connect([=, &renderer, &mCamera, &square](double deltaTime) {
		renderer->SetClearColor(0.05f, 0.05f, 0.075f, 1.0f);
		renderer->ClearScreen();

		renderer->StartScene(mCamera);
		{ // :TODO: For each object in the scene
			glm::mat4 transform = glm::translate(glm::mat4(1.0f), square.GetPosition());
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