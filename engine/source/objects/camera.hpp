#pragma once

#include <glm/glm.hpp>
#include <glm/gtx/quaternion.hpp>

namespace Engine {

	class Window;

	class Camera {
		glm::mat4 mProjectionMatrix;
		glm::mat4 mViewMatrix;
		glm::mat4 mViewProjectionMatrix;

		glm::vec3 mPosition = { 0, 0, 0 };
		glm::vec3 mRotation = { 0, 0, 0 };

		Window* mWindow;

		unsigned int mWidth;
		unsigned int mHeight;

	public:
		float moveSpeed = 2;
		float rotateSpeed = 90;

	public:
		Camera(Window* window);

		inline void SetPosition(const glm::vec3& position) { mPosition = position; CalculateMatrices(); }
		inline void SetRotation(const glm::vec3& rotation) { mRotation = rotation; CalculateMatrices(); }

		inline const glm::vec3& GetPosition() const { return mPosition; }
		inline const glm::vec3& GetRotation() const { return mRotation; }

		inline const glm::mat4& GetProjectionMatrix() const { return mProjectionMatrix; }
		inline const glm::mat4& GetViewMatrix() const { return mViewMatrix; }
		inline const glm::mat4& GetViewProjectionMatrix() const { return mViewProjectionMatrix; }

	private:
		void CalculateMatrices();
		void CalculateProjectionMatrix();
	};

}