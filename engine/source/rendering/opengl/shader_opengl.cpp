#pragma once
#include "engine_precompiled/engine_precompiled.hpp"
#include "rendering/opengl/shader_opengl.hpp"

#include "rendering/opengl/buffer_opengl.hpp"

#include <glad/glad.h>
#include <GLFW/glfw3.h>

#include <glm/gtc/type_ptr.hpp>

namespace Engine {

	static GLenum ShaderTypeFromString(const std::string& type) {
		if(type == "vertex" || type == "vert") {
			return GL_VERTEX_SHADER;
		} else if(type == "fragment" || type == "frag" || type == "pixel") {
			return GL_FRAGMENT_SHADER;
		}
	};

	OpenGlShader::OpenGlShader(const std::string& filepath) {
		std::string content = Shader::GetShaderContent(filepath);
		std::unordered_map<GLenum, std::string> sources = OpenGlShader::GetSeperatedShaders(content);

		InitializeShader(sources);

		auto lastSlash = filepath.find_last_of("/\\");
		lastSlash = lastSlash == std::string::npos ? 0 : lastSlash + 1;
		auto lastDot = filepath.rfind(".");
		auto count = lastDot == std::string::npos ? filepath.size() - lastSlash : lastDot - lastSlash;
		mName = filepath.substr(lastSlash, count);
	};

	OpenGlShader::OpenGlShader(const std::string& name, const std::string& filepath) {
		mName = name;

		std::string content = Shader::GetShaderContent(filepath);
		std::unordered_map<GLenum, std::string> sources = OpenGlShader::GetSeperatedShaders(content);

		InitializeShader(sources);
	};

	OpenGlShader::~OpenGlShader() {
		glDeleteShader(mRendererId);
	};

	std::unordered_map<GLenum, std::string> OpenGlShader::GetSeperatedShaders(const std::string& source) {
		std::unordered_map<GLenum, std::string> sources;

		const char* typeToken = "#type";
		size_t typeTokenLength = strlen(typeToken);
		size_t position = source.find(typeToken, 0);
		while(position != std::string::npos) {
			size_t eol = source.find_first_of("\r\n", position);
			size_t begin = position + typeTokenLength + 1;
			std::string type = source.substr(begin, eol - begin);

			size_t nextLinePosition = source.find_first_not_of("\r\n", eol);
			position = source.find(typeToken, nextLinePosition);
			sources[ShaderTypeFromString(type)] =
				source.substr(nextLinePosition,
							  position - (nextLinePosition == std::string::npos ? source.size() - 1 : nextLinePosition));
		}

		return sources;
	};

	void OpenGlShader::InitializeShader(std::unordered_map<GLenum, std::string> sources) {
		// Get a program object.
		GLuint program = glCreateProgram();

		std::array<GLenum, 2> shadersIds; // sources.size()
		int shadersIdsIndex = 0;
		for(auto& kv : sources) {
			GLenum type = kv.first;
			const std::string& shaderSource = kv.second;

			// Create an empty vertex shader handle
			GLuint shader = glCreateShader(type);

			// Send the vertex shader source code to GL
			// Note that std::string's .c_str is NULL character terminated.
			const GLchar* source = (const GLchar*)shaderSource.c_str();
			glShaderSource(shader, 1, &source, 0);

			// Compile the vertex shader
			glCompileShader(shader);

			GLint isCompiled = 0;
			glGetShaderiv(shader, GL_COMPILE_STATUS, &isCompiled);
			if(isCompiled == GL_FALSE) {
				GLint maxLength = 0;
				glGetShaderiv(shader, GL_INFO_LOG_LENGTH, &maxLength);

				// The maxLength includes the NULL character
				std::vector<GLchar> infoLog(maxLength);
				glGetShaderInfoLog(shader, maxLength, &maxLength, &infoLog[0]);

				// We don't need the shader anymore.
				glDeleteShader(shader);

				// Use the infoLog as you see fit.

				// In this simple program, we'll just leave
				return;
			}
			
			// Attach our shaders to our program
			glAttachShader(program, shader);
			shadersIds[shadersIdsIndex++] = shader;
		}

		// Link our program
		glLinkProgram(program);

		// Note the different functions here: glGetProgram* instead of glGetShader*.
		GLint isLinked = 0;
		glGetProgramiv(program, GL_LINK_STATUS, (int*)&isLinked);
		if(isLinked == GL_FALSE) {
			GLint maxLength = 0;
			glGetProgramiv(program, GL_INFO_LOG_LENGTH, &maxLength);

			// The maxLength includes the NULL character
			std::vector<GLchar> infoLog(maxLength);
			glGetProgramInfoLog(program, maxLength, &maxLength, &infoLog[0]);

			// We don't need the program anymore.
			glDeleteProgram(program);
			// Don't leak shaders either.
			for(auto id : shadersIds) {
				glDeleteShader(id);
			}

			// Use the infoLog as you see fit.
			printf("%s", infoLog.data());

			// In this simple program, we'll just leave
			return;
		}

		// Always detach shaders after a successful link.
		for(auto id : shadersIds) {
			glDetachShader(program, id);
		}

		// Set rendererId to the program
		mRendererId = program;
	};

	void OpenGlShader::Bind() {
		glUseProgram(mRendererId);
	};

	void OpenGlShader::Unbind() {
		glUseProgram(0);
	};

	void OpenGlShader::UploadUniformi(const std::string& name, int value) {
		GLint location = glGetUniformLocation(mRendererId, ("u_" + name).c_str());
		glUniform1i(location, value);
	}

	void OpenGlShader::UploadUniformf(const std::string& name, float value) {
		GLint location = glGetUniformLocation(mRendererId, ("u_" + name).c_str());
		glUniform1i(location, value);
	}

	void OpenGlShader::UploadUniformVec2f(const std::string& name, const glm::vec2& value) {
		GLint location = glGetUniformLocation(mRendererId, ("u_" + name).c_str());
		glUniform2f(location, value.x, value.y);
	};

	void OpenGlShader::UploadUniformVec3f(const std::string& name, const glm::vec3& value) {
		GLint location = glGetUniformLocation(mRendererId, ("u_" + name).c_str());
		glUniform3f(location, value.x, value.y, value.z);
	};

	void OpenGlShader::UploadUniformVec4f(const std::string& name, const glm::vec4& value) {
		GLint location = glGetUniformLocation(mRendererId, ("u_" + name).c_str());
		glUniform4f(location, value.x, value.y, value.z, value.w);
	};

	void OpenGlShader::UploadUniformMat3f(const std::string& name, const glm::mat3& value) {
		GLint location = glGetUniformLocation(mRendererId, ("u_" + name).c_str());
		glUniformMatrix3fv(location, 1, GL_FALSE, glm::value_ptr(value));
	};

	void OpenGlShader::UploadUniformMat4f(const std::string& name, const glm::mat4& value) {
		GLint location = glGetUniformLocation(mRendererId, ("u_" + name).c_str());
		glUniformMatrix4fv(location, 1, GL_FALSE, glm::value_ptr(value));
	};

}