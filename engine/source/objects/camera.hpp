#pragma once

#include <glm/glm.hpp>
#include <glm/gtx/quaternion.hpp>

namespace Engine {

	struct CameraData {
		glm::mat4 projectionMatrix;
		glm::mat4 viewMatrix;
		glm::mat4 viewProjectionMatrix;

		unsigned int width;
		unsigned int height;

		CameraData(unsigned int _width = 0, unsigned int _height = 0, glm::vec3 position = { 0, 0, 0 }, glm::vec3 rotation = { 0, 0, 0 });

		void CalculateMatrices(glm::vec3 position, glm::vec3 rotation);
		void CalculateProjectionMatrix();
	};

	class Camera {
		glm::vec3 mPosition = { 0, 0, 0 };
		glm::vec3 mRotation = { 0, 0, 0 };

		unsigned int mWindowWidth = 0;
		unsigned int mWindowHeight = 0;

		CameraData data;

	public:
		float moveSpeed = 2;
		float rotateSpeed = 90;

	public:
		Camera(unsigned int width, unsigned int height);

		inline void SetPosition(const glm::vec3& position) { mPosition = position; data.CalculateMatrices(mPosition, mRotation); }
		inline void SetRotation(const glm::vec3& rotation) { mRotation = rotation; data.CalculateMatrices(mPosition, mRotation); }

		inline const glm::vec3& GetPosition() const { return mPosition; }
		inline const glm::vec3& GetRotation() const { return mRotation; }

		inline const glm::mat4& GetProjectionMatrix() const { return data.projectionMatrix; }
		inline const glm::mat4& GetViewMatrix() const { return data.viewMatrix; }
		inline const glm::mat4& GetViewProjectionMatrix() const { return data.viewProjectionMatrix; }
	};

}