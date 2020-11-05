#pragma once

#include <cstdint>
#include <string>

namespace Engine {

	class Texture {

	protected:
		std::string mPath;

		uint32_t mRendererId = 0;
		uint32_t mWidth = 0;
		uint32_t mHeight = 0;

	public:
		inline uint32_t GetWidth() { return mWidth; }
		inline uint32_t GetHeight() { return mHeight; }

		virtual void Bind(uint32_t slot = 0) = 0;

		static Texture* Create(const std::string& path);
	};

}