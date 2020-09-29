#pragma once

#include "rendering/shader.hpp"

#include <glm/glm.hpp>

namespace Engine::Rendering {

	class OpenGlShader : public Shader {
		uint32_t mRendererId = 0;

	public:
		OpenGlShader(const std::string& vertexSource, const std::string& fragmentSource);
		~OpenGlShader();

		void Bind();
		void Unbind();

		void UploadUniformMat4(const std::string& name, const glm::mat4& matrix);
	};

}