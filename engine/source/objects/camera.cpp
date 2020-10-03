#include "engine_precompiled/engine_precompiled.hpp"
#include "objects/camera.hpp"

#include "rendering/window.hpp"

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>

namespace Engine {

	Camera::Camera(Window* window) {
		mWindow = window;
		mWidth = mWindow->GetWidth();
		mHeight = mWindow->GetHeight();

		CalculateProjectionMatrix();
		CalculateMatrices();

		/*window->windowResizedEvent.Connect([&](unsigned int width, unsigned int height) {
			mWidth = mWindow->GetWidth();
			mHeight = mWindow->GetHeight();

			CalculateProjectionMatrix();
			CalculateMatrices();

			return false;
		});*/
	}

	void Camera::CalculateProjectionMatrix() {
		float width = mWidth / 1000.0f;
		float height = mHeight / 1000.0f;

		mProjectionMatrix = glm::ortho(-width, width, -height, height, -1.0f, 1.0f);
	}

	void Camera::CalculateMatrices() {
		glm::mat4 transform =
			glm::translate(glm::mat4(1.0f), mPosition) *
			glm::rotate(glm::mat4(1.0f), mRotation.z, glm::vec3(0, 0, 1));

		mViewMatrix = glm::inverse(transform);
		mViewProjectionMatrix = mProjectionMatrix * mViewMatrix;
	}

}