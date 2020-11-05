#pragma once

#include <glm/glm.hpp>

namespace Engine {

	class Shader {

	protected:
		std::string mName;
		uint32_t mRendererId = 0;

	public:
		virtual void Bind() = 0;
		virtual void Unbind() = 0;

		virtual void UploadUniformi(const std::string& name, int value) = 0;
		virtual void UploadUniformf(const std::string& name, float value) = 0;

		virtual void UploadUniformVec2f(const std::string& name, const glm::vec2& value) = 0;
		virtual void UploadUniformVec3f(const std::string& name, const glm::vec3& value) = 0;
		virtual void UploadUniformVec4f(const std::string& name, const glm::vec4& value) = 0;

		virtual void UploadUniformMat3f(const std::string& name, const glm::mat3& value) = 0;
		virtual void UploadUniformMat4f(const std::string& name, const glm::mat4& value) = 0;

		virtual const std::string& GetName() { return mName; }

		static std::shared_ptr<Shader> Create(const std::string& filepath);
		static std::shared_ptr<Shader> Create(const std::string& name, const std::string& filepath);

		static std::string GetShaderContent(const std::string& filepath);
	};

	class ShaderLibrary {
		std::unordered_map<std::string, std::shared_ptr<Shader>> mShaders;

	public:
		void AddShader(const std::shared_ptr<Shader>& shader);
		std::shared_ptr<Shader> LoadShader(const std::string& filepath);
		std::shared_ptr<Shader> LoadShader(const std::string& name, const std::string& filepath);

		std::shared_ptr<Shader> GetShader(const std::string& name);
	};

}