#pragma once
#include "precompiled/precompiled.hpp"

#include "mathematics/vectors/vector2.hpp"
#include "application/application.hpp"

double GRAVITY = -9.8;

int main(int argc, char** argv) {
	Engine::Mathematics::Vector2 position(0, 0);
	Engine::Mathematics::Vector2 velocity(10, 100);

	Engine::Application* application = new Engine::Application();

	/*application->Updated.Connect([&](double deltaTime) {
		double yVelocity = velocity.GetY() + (GRAVITY * deltaTime);
		velocity.SetY(yVelocity);

		double xPosition = position.GetX() + (velocity.GetX() * deltaTime);
		double yPosition = position.GetY() + (velocity.GetY() * deltaTime);
		position.SetX(xPosition);
		position.SetY(yPosition);

		printf("p(%i, %i)\n", (int)position.GetX(), (int)position.GetY());

		return false;
	});*/

	application->Run();

	delete application;
	return 0;
}