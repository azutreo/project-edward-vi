#pragma once

#include "rendering/shader.hpp"
#include "rendering/buffer.hpp"

#include "objects/camera.hpp"

#include <glm/glm.hpp>

#include <iostream>

namespace Engine {

	class Camera;

	struct SceneData {
		glm::mat4 viewProjectionMatrix;
	};

	class Renderer {

	protected:
		ShaderLibrary* mShaderLibrary;
		SceneData* mSceneData;

	public:
		virtual void SetClearColor(float r, float g, float b, float a) = 0;
		virtual void ClearScreen() = 0;

		virtual void SetViewportSize(uint32_t x, uint32_t y, uint32_t width, uint32_t height) = 0;

		virtual void StartScene(const std::shared_ptr<Engine::Camera>& camera) = 0;
		virtual void EndScene() = 0;

		virtual void Submit(const std::shared_ptr<VertexArray>& vertexArray, const std::shared_ptr<Shader>& shader, glm::mat4 transform = glm::mat4(1.0f)) = 0;

		virtual void DrawIndexed(const std::shared_ptr<VertexArray>& vertexArray) = 0;

		inline ShaderLibrary* GetShaderLibrary() { return mShaderLibrary; }

		static Renderer* Create();
	};

}