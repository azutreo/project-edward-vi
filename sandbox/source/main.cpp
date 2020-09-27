#pragma once
#include "precompiled/precompiled.hpp"

#include "mathematics/vectors/vector3.hpp"

int main() {
	Engine::Mathematics::Vector3 vector1(1, 2, 3);
	Engine::Mathematics::Vector3 vector2(1, 2, 3);

	vector1 = vector1.Add(vector2);
	std::cout << vector1 << std::endl;

	return 0;
}