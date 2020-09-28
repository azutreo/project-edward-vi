#pragma once

#include "rendering/buffer.hpp"

namespace Engine::Renderer {

	///////////////////
	// Vertex Buffer //
	///////////////////

	class OpenGlVertexBuffer : public Buffer {
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

	//////////////////
	// Index Buffer //
	//////////////////

	class OpenGlIndexBuffer : public Buffer {
		uint32_t mCount = 0;
		unsigned int mIndexBuffer = 0;

	public:
		OpenGlIndexBuffer(uint32_t* indices = 0, uint32_t count = 0);
		virtual ~OpenGlIndexBuffer();

		void Bind() const override;
		void Unbind() const override;

		inline uint32_t GetCount() const { return mCount; }
	};

	//////////////////
	// Vertex Array //
	//////////////////

	class OpenGlVertexArray : public Buffer {
		std::vector<std::shared_ptr<OpenGlVertexBuffer>> mVertexBuffers;
		std::shared_ptr<OpenGlIndexBuffer> mIndexBuffer;

	public:
		OpenGlVertexArray();
		virtual ~OpenGlVertexArray() = default;

		void Bind() const override;
		void Unbind() const override;
		void Draw() const;

		void AddVertexBuffer(std::shared_ptr<OpenGlVertexBuffer>& vertexBuffer);
		void SetIndexBuffer(std::shared_ptr<OpenGlIndexBuffer>& indexBuffer);

		const std::vector<std::shared_ptr<OpenGlVertexBuffer>>& GetVertexBuffers() const { return mVertexBuffers; }
		const std::shared_ptr<OpenGlIndexBuffer>& GetIndexBuffer() const { return mIndexBuffer; }
	};

}