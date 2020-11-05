#pragma once
#include "engine_precompiled/engine_precompiled.hpp"
#include "rendering/buffer.hpp"

#include "rendering/opengl/buffer_opengl.hpp"

namespace Engine {

	VertexBuffer* VertexBuffer::Create(float* vertices, uint32_t size) {
		// :TODO: Switch for DirectX and whatnot
		return new OpenGlVertexBuffer(vertices, size);
	}

	IndexBuffer* IndexBuffer::Create(uint32_t* indices, uint32_t count) {
		// :TODO: Switch for DirectX and whatnot
		return new OpenGlIndexBuffer(indices, count);
	}

	VertexArray* VertexArray::Create() {
		// :TODO: Switch for DirectX and whatnot
		return new OpenGlVertexArray();
	}

	void BufferLayout::CalculateOffsetsAndStride() {
		uint32_t offset = 0;
		mStride = 0;
		for(auto& element : mElements) {
			element.offset = offset;

			offset += element.size;
			mStride += element.size;
		}
	}

	uint32_t BufferElement::GetElementCount() const {
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

	extern uint32_t ShaderDataTypeSize(ShaderDataType type) {
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

}