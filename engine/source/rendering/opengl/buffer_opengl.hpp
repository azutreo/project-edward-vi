#pragma once

#include "rendering/buffer.hpp"

namespace Engine::Rendering {

	///////////////////
	// Vertex Buffer //
	///////////////////

	class OpenGlVertexBuffer : public VertexBuffer {
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

	class OpenGlIndexBuffer : public IndexBuffer {
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

	class OpenGlVertexArray : public VertexArray {
		std::vector<std::shared_ptr<VertexBuffer>> mVertexBuffers;
		std::shared_ptr<IndexBuffer> mIndexBuffer;

	public:
		OpenGlVertexArray();
		virtual ~OpenGlVertexArray() = default;

		void Bind() const override;
		void Unbind() const override;
		void Draw() const;

		void AddVertexBuffer(std::shared_ptr<VertexBuffer>& vertexBuffer);
		void SetIndexBuffer(std::shared_ptr<IndexBuffer>& indexBuffer);

		const std::vector<std::shared_ptr<VertexBuffer>>& GetVertexBuffers() const { return mVertexBuffers; }
		const std::shared_ptr<IndexBuffer>& GetIndexBuffer() const { return mIndexBuffer; }
	};

}