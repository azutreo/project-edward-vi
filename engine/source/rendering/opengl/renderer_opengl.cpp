#pragma once
#include "engine_precompiled/engine_precompiled.hpp"
#include "rendering/opengl/renderer_opengl.hpp"

#include "rendering/opengl/buffer_opengl.hpp"
#include "rendering/opengl/shader_opengl.hpp"

#include "objects/camera.hpp"

#include "glm/glm.hpp"

#include <glad/glad.h>
#include <GLFW/glfw3.h>

namespace Engine {

	void OpenGlRenderer::SetClearColor(float red, float green, float blue, float alpha) {
		glClearColor((GLfloat)red, (GLfloat)green, (GLfloat)blue, (GLfloat)alpha);
	}

	void OpenGlRenderer::ClearScreen() {
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	}

	void OpenGlRenderer::StartScene(const Camera& camera) {
		mSceneData = new SceneData();
		mSceneData->viewProjectionMatrix = camera.GetViewProjectionMatrix();
	}

	void OpenGlRenderer::EndScene() {
		delete mSceneData;
		//////////////////////////
		// :TODO: End the queue //
		//////////////////////////
	}

	void OpenGlRenderer::Submit(const std::shared_ptr<VertexArray>& vertexArray, const std::shared_ptr<Shader>& shader, glm::mat4 transform) {
		// :TODO: Add to queue, then draw once everything has been added
		shader->Bind();
		shader->UploadUniformMat4("u_ViewProjection", mSceneData->viewProjectionMatrix);
		shader->UploadUniformMat4("u_Transform", transform);

		vertexArray->Bind();
		DrawIndexed(vertexArray);
	};

	void OpenGlRenderer::DrawIndexed(const std::shared_ptr<VertexArray>& vertexArray) {
		vertexArray->Draw();
	};

}