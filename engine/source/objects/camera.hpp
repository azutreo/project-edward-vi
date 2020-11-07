#pragma once

#include <glm/glm.hpp>
#include <glm/gtx/quaternion.hpp>

namespace Engine {

	struct CameraData {
		glm::mat4 projectionMatrix;
		glm::mat4 viewMatrix;
		glm::mat4 viewProjectionMatrix;

		glm::vec3 position = { 0, 0, 0 };
		glm::vec3 rotation = { 0, 0, 0 };
		unsigned int width;
		unsigned int height;
		float zoom;

		CameraData(unsigned int _width = 0, unsigned int _height = 0, glm::vec3 _position = { 0, 0, 0 }, glm::vec3 _rotation = { 0, 0, 0 }, float zoomLevel = 1);

		void CalculateMatrices();
		void CalculateProjectionMatrix();

		inline void SetWindowSize(unsigned int _width, unsigned int _height) { width = _width; height = _height; }
	};

	class Camera {
		glm::vec3 mPosition = { 0, 0, 0 };
		glm::vec3 mRotation = { 0, 0, 0 };

		CameraData mData;

	public:
		float moveSpeed = 2;
		float rotateSpeed = 90;

	public:
		Camera(unsigned int width, unsigned int height);

		inline void SetPosition(const glm::vec3& position) { mPosition = position; mData.position = position; mData.CalculateMatrices(); }
		inline void SetRotation(const glm::vec3& rotation) { mRotation = rotation; mData.rotation = rotation; mData.CalculateMatrices(); }

		inline void SetZoomLevel(float zoomLevel) { mData.zoom = zoomLevel; mData.CalculateMatrices(); }
		inline void SetWindowSize(unsigned int width, unsigned int height) { mData.width = width; mData.height = height; mData.CalculateMatrices(); }

		inline const glm::vec3& GetPosition() const { return mPosition; }
		inline const glm::vec3& GetRotation() const { return mRotation; }
		inline float GetZoomLevel() const { return mData.zoom; }

		inline const glm::mat4& GetProjectionMatrix() const { return mData.projectionMatrix; }
		inline const glm::mat4& GetViewMatrix() const { return mData.viewMatrix; }
		inline const glm::mat4& GetViewProjectionMatrix() const { return mData.viewProjectionMatrix; }
	};

}