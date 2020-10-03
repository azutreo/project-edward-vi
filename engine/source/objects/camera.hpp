#pragma once

#include <glm/glm.hpp>
#include <glm/gtx/quaternion.hpp>

#define PI 3.14159f

namespace Engine {

	class Camera {
		glm::mat4 mProjectionMatrix;
		glm::mat4 mViewMatrix;
		glm::mat4 mViewProjectionMatrix;

		glm::vec3 mPosition = { 0, 0, 0 };
		glm::vec3 mRotation = { 0, 0, 0 };

	public:
		float moveSpeed = 2;
		float rotateSpeed = 90;

	public:
		Camera(float left, float right, float bottom, float top);

		inline void SetPosition(const glm::vec3& position) { mPosition = position; CalculateMatrices(); }
		inline void SetRotation(const glm::vec3& rotation) { mRotation = rotation; CalculateMatrices(); }

		inline const glm::vec3& GetPosition() const { return mPosition; }
		inline const glm::vec3& GetRotation() const { return mRotation; }

		inline const glm::mat4& GetProjectionMatrix() const { return mProjectionMatrix; }
		inline const glm::mat4& GetViewMatrix() const { return mViewMatrix; }
		inline const glm::mat4& GetViewProjectionMatrix() const { return mViewProjectionMatrix; }

	private:
		void CalculateMatrices();
	};

}