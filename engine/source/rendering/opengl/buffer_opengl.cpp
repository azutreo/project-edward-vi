#pragma once
#include "engine_precompiled/engine_precompiled.hpp"
#include "rendering/opengl/buffer_opengl.hpp"

#include "rendering/buffer.hpp"

#include <glad/glad.h>
#include <GLFW/glfw3.h>

namespace Engine::Renderer {

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

}