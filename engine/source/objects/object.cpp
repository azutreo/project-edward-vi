#include "engine_precompiled/engine_precompiled.hpp"
#include "objects/object.hpp"

#include "rendering/buffer.hpp"
#include "rendering/shader.hpp"
#include "rendering/texture.hpp"

namespace Engine {

	unsigned int Object::sCount = 0;

	Object::Object(std::string name, float* vertices, uint32_t verticesSize, uint32_t* indices, uint32_t indicesCount, const std::shared_ptr<Shader>& shader, BufferLayout* layout, const std::string& texturePath)
	: mName(name), mVertices(vertices), mVerticesSize(verticesSize), mIndices(indices), mIndicesCount(indicesCount), mShader(shader) {
		mId = sCount++;
		mLayout = layout;

		mTexture.reset(Texture::Create(texturePath));
		mShader->Bind();
		mShader->UploadUniformi("Texture", 0);

		Initialize();
	}

	void Object::Initialize() {
		mVertexArray.reset(VertexArray::Create());
		mVertexArray->Unbind();

		mVertexBuffer.reset(VertexBuffer::Create(mVertices, mVerticesSize));
		mVertexBuffer->SetLayout(*mLayout);
		mVertexArray->AddVertexBuffer(mVertexBuffer);

		mIndexBuffer.reset(IndexBuffer::Create(mIndices, mIndicesCount));
		mVertexArray->AddVertexBuffer(mVertexBuffer);
		mVertexArray->SetIndexBuffer(mIndexBuffer);
	}

}