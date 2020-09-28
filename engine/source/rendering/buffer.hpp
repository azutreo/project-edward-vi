#pragma once

namespace Engine::Renderer {

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

	static uint32_t ShaderDataTypeSize(ShaderDataType type) {
		switch(type) {
			case ShaderDataType::INT: return 4;
			case ShaderDataType::BOOL: return 1;
			case ShaderDataType::FLOAT: return 4;
			case ShaderDataType::INT2: return 4 * 2;
			case ShaderDataType::INT3: return 4 * 3;
			case ShaderDataType::INT4: return 4 * 4;
			case ShaderDataType::FLOAT2: return 4 * 2;
			case ShaderDataType::FLOAT3: return 4 * 3;
			case ShaderDataType::FLOAT4: return 4 * 4;
			case ShaderDataType::MATRIX3: return 4 * 3 * 3;
			case ShaderDataType::MATRIX4: return 4 * 4 * 4;
		}

		return 0;
	}

	struct BufferElement {

		std::string name;
		ShaderDataType type;
		uint32_t size;
		uint32_t offset = 0;
		bool normalized = false;

		BufferElement(ShaderDataType _type, const std::string& _name, const bool _normalized = false)
		: name(_name), type(_type), normalized(_normalized), size(ShaderDataTypeSize(type)) {}

		uint32_t GetElementCount() const {
			switch(type) {
				case ShaderDataType::INT: return 1;
				case ShaderDataType::BOOL: return 1;
				case ShaderDataType::FLOAT: return 1;
				case ShaderDataType::INT2: return 2;
				case ShaderDataType::INT3: return 3;
				case ShaderDataType::INT4: return 4;
				case ShaderDataType::FLOAT2: return 2;
				case ShaderDataType::FLOAT3: return 3;
				case ShaderDataType::FLOAT4: return 4;
				case ShaderDataType::MATRIX3: return 3;
				case ShaderDataType::MATRIX4: return 4;
			}

			return 0;
		}

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

	private:

		void CalculateOffsetsAndStride() {
			uint32_t offset = 0;
			mStride = 0;
			for(auto& element : mElements) {
				element.offset = offset;

				offset += element.size;
				mStride += element.size;
			}
		}

	};

	struct Buffer {

		virtual ~Buffer() = default;

		virtual void Bind() const = 0;
		virtual void Unbind() const = 0;

	};

}