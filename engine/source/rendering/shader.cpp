#pragma once
#include "engine_precompiled/engine_precompiled.hpp"
#include "rendering/shader.hpp"

#include "rendering/opengl/shader_opengl.hpp"

#include <iostream>

namespace Engine {

	Shader* Shader::Create(const std::string& vertexSource, const std::string& fragmentSource) {
		return new OpenGlShader(vertexSource, fragmentSource);
	}

}