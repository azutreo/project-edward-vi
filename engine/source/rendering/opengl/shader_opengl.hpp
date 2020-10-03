#pragma once

#include "rendering/shader.hpp"

#include <glm/glm.hpp>

namespace Engine {

	struct OpenGlShader : public Shader {
		OpenGlShader(const std::string& vertexSource, const std::string& fragmentSource);
		~OpenGlShader();

		void Bind();
		void Unbind();

		void UploadUniformMat4(const std::string& name, const glm::mat4& matrix);
	};

}