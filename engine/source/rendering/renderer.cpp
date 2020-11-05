#include "engine_precompiled/engine_precompiled.hpp"
#include "rendering/renderer.hpp"

#include "rendering/opengl/renderer_opengl.hpp"

namespace Engine {

	Renderer* Renderer::Create() {
		return new OpenGlRenderer();
	}

}