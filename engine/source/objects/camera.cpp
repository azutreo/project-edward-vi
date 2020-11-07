#include "engine_precompiled/engine_precompiled.hpp"
#include "objects/camera.hpp"

#include "rendering/window.hpp"

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>

namespace Engine {

	CameraData::CameraData(unsigned int _width, unsigned int _height, glm::vec3 _position, glm::vec3 _rotation, float zoomLevel)
	: width(_width), height(_height), position(_position), rotation(_rotation), zoom(zoomLevel) {
		CalculateMatrices();
	}

	void CameraData::CalculateProjectionMatrix() {
		float pWidth = width / 1000.0f;
		float pHeight = height / 1000.0f;

		projectionMatrix = glm::ortho(-pWidth * zoom, pWidth * zoom, -pHeight * zoom, pHeight * zoom, -zoom, zoom);
	}

	void CameraData::CalculateMatrices() {
		glm::mat4 transform =
			glm::translate(glm::mat4(1.0f), position) *
			glm::rotate(glm::mat4(1.0f), rotation.z, glm::vec3(0, 0, 1));

		CalculateProjectionMatrix();
		viewMatrix = glm::inverse(transform);
		viewProjectionMatrix = projectionMatrix * viewMatrix;
	}

	Camera::Camera(unsigned int width, unsigned int height)
	: mData(width, height, mPosition, mRotation) {

	}

}