#pragma once

#include "rendering/shader.hpp"

#include <glad/glad.h>
#include <GLFW/glfw3.h>

#include <glm/glm.hpp>

#include <fstream>

namespace Engine {

	struct OpenGlShader : public Shader {
		OpenGlShader(const std::string& filepath);
		OpenGlShader(const std::string& name, const std::string& filepath);
		~OpenGlShader();

		void Bind();
		void Unbind();

		void UploadUniformi(const std::string& name, int value) override;
		void UploadUniformf(const std::string& name, float value) override;

		void UploadUniformVec2f(const std::string& name, const glm::vec2& value) override;
		void UploadUniformVec3f(const std::string& name, const glm::vec3& value) override;
		void UploadUniformVec4f(const std::string& name, const glm::vec4& value) override;

		void UploadUniformMat3f(const std::string& name, const glm::mat3& value) override;
		void UploadUniformMat4f(const std::string& name, const glm::mat4& value) override;

	private:
		std::unordered_map<GLenum, std::string> GetSeperatedShaders(const std::string& source);
		void InitializeShader(std::unordered_map<GLenum, std::string> sources);
	};

}