#pragma once

namespace Engine {

	enum class ShaderDataType {
		NONE = 0,
		INT,
		BOOL,
		INT2,
		INT3,
		INT4,
		FLOAT,
		FLOAT2,
		FLOAT3,
		FLOAT4,
		MATRIX3,
		MATRIX4,
	};

	extern uint32_t ShaderDataTypeSize(ShaderDataType type);

	struct BufferElement {
		std::string name;
		ShaderDataType type;
		uint32_t size;
		uint32_t offset = 0;
		bool normalized = false;

		BufferElement(ShaderDataType _type, const std::string& _name, const bool _normalized = false)
		: name(_name), type(_type), normalized(_normalized), size(ShaderDataTypeSize(type)) {}

		uint32_t GetElementCount() const;
	};

	class BufferLayout {
		std::vector<BufferElement> mElements;
		uint32_t mStride = 0;

	public:
		BufferLayout(const std::initializer_list<BufferElement>& elements = {})
		: mElements(elements) {
			CalculateOffsetsAndStride();
		}

		inline const std::vector<BufferElement>& GetElements() const { return mElements; }
		inline uint32_t GetStride() const { return mStride; }

		std::vector<BufferElement>::iterator begin() { return mElements.begin(); }
		std::vector<BufferElement>::iterator end() { return mElements.end(); }
		std::vector<BufferElement>::const_iterator begin() const { return mElements.begin(); }
		std::vector<BufferElement>::const_iterator end() const  { return mElements.end(); }

	private:
		void CalculateOffsetsAndStride();
	};

	class Buffer {

	protected:
		uint32_t mRendererId = 0;

	public:
		virtual void Bind() const = 0;
		virtual void Unbind() const = 0;
	};

	class VertexBuffer : public Buffer {
		unsigned int mVertexBuffer = 0;

		BufferLayout mLayout;

	public:
		virtual void Bind() const = 0;
		virtual void Unbind() const = 0;

		virtual void SetLayout(const BufferLayout& layout) = 0;
		virtual const BufferLayout& GetLayout() const = 0;

		static VertexBuffer* Create(float* vertices = 0, uint32_t size = 0);
	};

	class IndexBuffer : public Buffer {
		uint32_t mCount = 0;
		unsigned int mIndexBuffer = 0;

	public:
		virtual void Bind() const = 0;
		virtual void Unbind() const = 0;

		virtual inline uint32_t GetCount() const = 0;

		static IndexBuffer* Create(uint32_t* indices = 0, uint32_t count = 0);
	};

	class VertexArray : public Buffer {
		std::vector<std::shared_ptr<VertexBuffer>> mVertexBuffers;
		std::shared_ptr<IndexBuffer> mIndexBuffer;

	public:
		virtual ~VertexArray() = default;

		virtual void Bind() const = 0;
		virtual void Unbind() const = 0;
		virtual void Draw() const = 0;

		virtual void AddVertexBuffer(std::shared_ptr<VertexBuffer>& vertexBuffer) = 0;
		virtual void SetIndexBuffer(std::shared_ptr<IndexBuffer>& indexBuffer) = 0;

		virtual const std::vector<std::shared_ptr<VertexBuffer>>& GetVertexBuffers() const = 0;
		virtual const std::shared_ptr<IndexBuffer>& GetIndexBuffer() const = 0;

		static VertexArray* Create();
	};

}