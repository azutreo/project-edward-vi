#pragma once
#include "engine_precompiled/engine_precompiled.hpp"
#include "rendering/opengl/buffer_opengl.hpp"

#include "rendering/buffer.hpp"

#include <glad/glad.h>
#include <GLFW/glfw3.h>

namespace Engine {

	static GLenum ShaderDataTypeToOpenGlBaseType(const ShaderDataType type) {
		switch(type) {
			case ShaderDataType::INT: return GL_INT;
			case ShaderDataType::BOOL: return GL_BOOL;
			case ShaderDataType::FLOAT: return GL_FLOAT;
			case ShaderDataType::INT2: return GL_INT;
			case ShaderDataType::INT3: return GL_INT;
			case ShaderDataType::INT4: return GL_INT;
			case ShaderDataType::FLOAT2: return GL_FLOAT;
			case ShaderDataType::FLOAT3: return GL_FLOAT;
			case ShaderDataType::FLOAT4: return GL_FLOAT;
			case ShaderDataType::MATRIX3: return GL_INT;
			case ShaderDataType::MATRIX4: return GL_INT;
		}

		return 0;
	}

	///////////////////
	// Vertex Buffer //
	///////////////////

	OpenGlVertexBuffer::OpenGlVertexBuffer(float* verticies, uint32_t size) {
		glCreateBuffers(1, &mRendererId);
		glBindBuffer(GL_ARRAY_BUFFER, mRendererId);
		glBufferData(GL_ARRAY_BUFFER, size, verticies, GL_STATIC_DRAW);
	}

	OpenGlVertexBuffer::~OpenGlVertexBuffer() {
		glDeleteBuffers(1, &mRendererId);
	}

	void OpenGlVertexBuffer::Bind() const {
		glBindBuffer(GL_ARRAY_BUFFER, mRendererId);
	}

	void OpenGlVertexBuffer::Unbind() const {
		glBindBuffer(GL_ARRAY_BUFFER, 0);
	}

	//////////////////
	// Index Buffer //
	//////////////////

	OpenGlIndexBuffer::OpenGlIndexBuffer(uint32_t* indices, uint32_t count)
	: mCount(count) {
		glCreateBuffers(1, &mRendererId);
		glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, mRendererId);
		glBufferData(GL_ELEMENT_ARRAY_BUFFER, count * sizeof(uint32_t), indices, GL_STATIC_DRAW);
	}

	OpenGlIndexBuffer::~OpenGlIndexBuffer() {
		glDeleteBuffers(1, &mRendererId);
	}

	void OpenGlIndexBuffer::Bind() const {
		glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, mRendererId);
	}

	void OpenGlIndexBuffer::Unbind() const {
		glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);
	}

	//////////////////
	// Vertex Array //
	//////////////////

	OpenGlVertexArray::OpenGlVertexArray() {
		glCreateVertexArrays(1, &mRendererId);
	}

	void OpenGlVertexArray::Bind() const {
		glBindVertexArray(mRendererId);
	}

	void OpenGlVertexArray::Unbind() const {
		glBindVertexArray(0);
	}

	void OpenGlVertexArray::Draw() const {
		glDrawElements(GL_TRIANGLES, mIndexBuffer->GetCount(), GL_UNSIGNED_INT, nullptr);
	}

	void OpenGlVertexArray::AddVertexBuffer(std::shared_ptr<VertexBuffer>& vertexBuffer) {
		glBindVertexArray(mRendererId);
		vertexBuffer->Bind();

		uint32_t index = 0;
		const auto& layout = vertexBuffer->GetLayout();
		for(const auto& element : layout) {
			glEnableVertexAttribArray(index);

			glVertexAttribPointer(index,
				element.GetElementCount(),
				ShaderDataTypeToOpenGlBaseType(element.type),
				element.normalized ? GL_TRUE : GL_FALSE,
				layout.GetStride(),
				(const void*)element.offset);

			index++;
		};

		mVertexBuffers.push_back(vertexBuffer);
	};

	void OpenGlVertexArray::SetIndexBuffer(std::shared_ptr<IndexBuffer>& indexBuffer) {
		glBindVertexArray(mRendererId);
		indexBuffer->Bind();

		mIndexBuffer = indexBuffer;
	};

}