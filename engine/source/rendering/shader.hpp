#pragma once

#include <glm/glm.hpp>

namespace Engine {

	class Shader {

	protected:
		uint32_t mRendererId = 0;

	public:
		virtual void Bind() = 0;
		virtual void Unbind() = 0;

		virtual void UploadUniformMat4(const std::string& name, const glm::mat4& matrix) = 0;

		static Shader* Create(const std::string& vertexSource, const std::string& fragmentSource);
	};

}