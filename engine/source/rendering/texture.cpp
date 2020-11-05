#include "engine_precompiled/engine_precompiled.hpp"
#include "rendering/texture.hpp"

#include "rendering/opengl/texture_opengl.hpp"

namespace Engine {

	Texture* Texture::Create(const std::string& path) {
		return new OpenGlTexture2D(path);
	}

}