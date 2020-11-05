#pragma once

#include "rendering/texture.hpp"

namespace Engine {

	class OpenGlTexture2D : public Texture {
		std::string mPath;

	public:
		OpenGlTexture2D(const std::string& path);
		~OpenGlTexture2D();

		void Bind(uint32_t slot = 0) override;
	};

}