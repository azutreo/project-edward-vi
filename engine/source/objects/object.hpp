#pragma once

#include "mathematics/vectors/vector3.hpp"

#include <glm/glm.hpp>

namespace Engine {

	class VertexArray;
	class VertexBuffer;
	class IndexBuffer;
	class Shader;
	class BufferLayout;
	class Texture;

	class Object {
		static unsigned int sCount;
		using Vector3 = Vector3<float>;

		unsigned int mId;
		std::string mName;

		glm::vec3 mPosition = { 0.0f, 0.0f, 0.0f };
		glm::vec3 mRotation = { 0.0f, 0.0f, 0.0f };

		// Mesh mMesh;
		// Material mMaterial;
		std::shared_ptr<Texture> mTexture;

		std::shared_ptr<VertexArray> mVertexArray;
		std::shared_ptr<VertexBuffer> mVertexBuffer;
		std::shared_ptr<IndexBuffer> mIndexBuffer;
		std::shared_ptr<Shader> mShader;

		float* mVertices;
		uint32_t mVerticesSize;
		uint32_t* mIndices;
		uint32_t mIndicesCount;
		BufferLayout* mLayout;

	public:
		Object(std::string name, float* vertices, uint32_t verticesSize, uint32_t* indices, uint32_t indicesCount, const std::shared_ptr<Shader>& shader, BufferLayout* layout, const std::string& texturePath);

		inline const glm::vec3& GetPosition() const { return mPosition; }
		inline const glm::vec3& GetRotation() const { return mRotation; }

		inline void SetPosition(const glm::vec3& position) { mPosition = position; }
		inline void SetRotation(const glm::vec3& rotation) { mRotation = rotation; }

		inline const std::shared_ptr<VertexArray>& GetVertexArray() const { return mVertexArray; }
		inline const std::shared_ptr<Shader>& GetShader() const { return mShader; }
		inline const std::shared_ptr<Texture>& GetTexture() const { return mTexture; }

	private:
		void Initialize();
	};

}