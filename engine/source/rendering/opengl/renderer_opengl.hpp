#pragma once

#include "rendering/opengl/buffer_opengl.hpp"
#include "rendering/opengl/shader_opengl.hpp"

#include "rendering/shader.hpp"
#include "rendering/buffer.hpp"
#include "rendering/renderer.hpp"

#include "glm/glm.hpp"

namespace Engine {

	struct OpenGlRenderer : public Renderer {
		OpenGlRenderer();

		void SetClearColor(float r, float g, float b, float a) override;
		void ClearScreen() override;

		void StartScene(const Camera& camera) override;
		void EndScene() override;

		void Submit(const std::shared_ptr<VertexArray>& vertexArray, const std::shared_ptr<Shader>& shader, glm::mat4 transform = glm::mat4(1.0f)) override;

		void DrawIndexed(const std::shared_ptr<VertexArray>& vertexArray) override;
	};

}