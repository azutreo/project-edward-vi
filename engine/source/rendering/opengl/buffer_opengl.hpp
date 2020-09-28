#pragma once

#include "rendering/buffer.hpp"

namespace Engine::Renderer {

	class OpenGlVertexBuffer : public Buffer {

		uint32_t mRendererId = 0;
		unsigned int mVertexBuffer = 0;

		BufferLayout mLayout;

	public:

		OpenGlVertexBuffer(float* vertices = 0, uint32_t size = 0);
		virtual ~OpenGlVertexBuffer();

		void Bind() const override;
		void Unbind() const override;

		void SetLayout(const BufferLayout& layout) { mLayout = layout; }
		const BufferLayout& GetLayout() const { return mLayout; }

	};

	class OpenGlIndexBuffer : public Buffer {

		uint32_t mRendererId = 0;
		uint32_t mCount = 0;
		unsigned int mIndexBuffer = 0;

	public:

		OpenGlIndexBuffer(uint32_t* indices = 0, uint32_t count = 0);
		virtual ~OpenGlIndexBuffer();

		void Bind() const override;
		void Unbind() const override;

		inline uint32_t GetCount() const { return mCount; }

	};

}