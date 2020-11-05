#pragma once
#include "engine_precompiled/engine_precompiled.hpp"
#include "rendering/shader.hpp"

#include "rendering/opengl/shader_opengl.hpp"

#include <iostream>
#include <fstream>

namespace Engine {

	std::shared_ptr<Shader> Shader::Create(const std::string& filepath) {
		return std::make_shared<OpenGlShader>(filepath);
	}

	std::shared_ptr<Shader> Shader::Create(const std::string& name, const std::string& filepath) {
		return std::make_shared<OpenGlShader>(name, filepath);
	}

	std::string Shader::GetShaderContent(const std::string& filepath) {
		std::string result;
		std::ifstream in(filepath, std::ios::in | std::ios::binary);
		if(in) {
			in.seekg(0, std::ios::end);
			result.resize(in.tellg());
			in.seekg(0, std::ios::beg);
			in.read(&result[0], result.size());
			in.close();
		} else {
			return "";
		}

		/*std::ifstream source(filepath);
		std::string content((std::istreambuf_iterator<char>(source)),
							(std::istreambuf_iterator<char>()));*/

		return result;
	};

	void ShaderLibrary::AddShader(const std::shared_ptr<Shader>& shader) {
		auto& name = shader->GetName();
		if(mShaders.find(name) != mShaders.end()) { return; }

		mShaders[name] = shader;
	};

	std::shared_ptr<Shader> ShaderLibrary::LoadShader(const std::string& filepath) {
		auto shader = Shader::Create(filepath);
		AddShader(shader);

		return shader;
	};

	std::shared_ptr<Shader> ShaderLibrary::LoadShader(const std::string& name, const std::string& filepath) {
		auto shader = Shader::Create(name, filepath);
		AddShader(shader);

		return shader;
	};

	std::shared_ptr<Shader> ShaderLibrary::GetShader(const std::string& name) {
		return mShaders[name];
	};

}