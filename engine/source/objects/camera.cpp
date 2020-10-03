#include "engine_precompiled/engine_precompiled.hpp"
#include "objects/camera.hpp"

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>

namespace Engine {

	Camera::Camera(float left, float right, float bottom, float top)
	: mProjectionMatrix(glm::ortho(left, right, bottom, top, -1.0f, 1.0f)) {
		CalculateMatrices();
	}

	void Camera::CalculateMatrices() {
		glm::mat4 transform =
			glm::translate(glm::mat4(1.0f), mPosition) *
			glm::rotate(glm::mat4(1.0f), mRotation.z, glm::vec3(0, 0, 1));

		mViewMatrix = glm::inverse(transform);
		mViewProjectionMatrix = mProjectionMatrix * mViewMatrix;
	}

}