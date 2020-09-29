#pragma once
#include "engine_precompiled/engine_precompiled.hpp"

#include "mathematics/vectors/vector3.hpp"

namespace Engine::Mathematics {

	template <typename Type>
	Vector3<Type>::Vector3<Type>(Type _x, Type _y, Type _z) : x(_x), y(_y), z(_z) {
		mMagnitude = CalculateMagnitude(_x, _y, _z);
	}

	template <typename Type>
	Type Vector3<Type>::CalculateMagnitude(Type x, Type y, Type z) {
		return std::sqrt(std::pow(x, 2) + std::pow(y, 2) + std::pow(z, 2));
	}

	template <typename Type>
	Vector3<Type> Vector3<Type>::Add(const Vector3& vector) const {
		return Vector3(x + vector.x,
			y + vector.y,
			z + vector.z);
	}
	template <typename Type>
	Vector3<Type> Vector3<Type>::Add(Type scalar) const {
		return Vector3(x + scalar,
			y + scalar,
			z + scalar);
	}

	template <typename Type>
	Vector3<Type> Vector3<Type>::Subtract(const Vector3& vector) const {
		return Vector3(x - vector.x,
			y - vector.y,
			z - vector.z);
	}
	template <typename Type>
	Vector3<Type> Vector3<Type>::Subtract(Type scalar) const {
		return Vector3(x - scalar,
			y - scalar,
			z - scalar);
	}

	template <typename Type>
	Vector3<Type> Vector3<Type>::Multiply(const Vector3& vector) const {
		return Vector3(x * vector.x,
			y * vector.y,
			z * vector.z);
	}
	template <typename Type>
	Vector3<Type> Vector3<Type>::Multiply(Type scalar) const {
		return Vector3(x * scalar,
			y * scalar,
			z * scalar);
	}

	template <typename Type>
	Vector3<Type> Vector3<Type>::Divide(const Vector3& vector) const {
		return Vector3(x / vector.x,
			y / vector.y,
			z / vector.z);
	}
	template <typename Type>
	Vector3<Type> Vector3<Type>::Divide(Type scalar) const {
		return Vector3(x / scalar,
			y / scalar,
			z / scalar);
	}

	template <typename Type>
	Vector3<Type> Vector3<Type>::Add(const Vector3& vector1, const Vector3& vector2) {
		return vector1.Add(vector2);
	}
	template <typename Type>
	Vector3<Type> Vector3<Type>::Add(const Vector3& vector, Type scalar) {
		return vector.Add(scalar);
	}

	template <typename Type>
	Vector3<Type> Vector3<Type>::Subtract(const Vector3& vector1, const Vector3& vector2) {
		return vector1.Subtract(vector2);
	}
	template <typename Type>
	Vector3<Type> Vector3<Type>::Subtract(const Vector3& vector, Type scalar) {
		return vector.Subtract(scalar);
	}

	template <typename Type>
	Vector3<Type> Vector3<Type>::Multiply(const Vector3& vector1, const Vector3& vector2) {
		return vector1.Multiply(vector2);
	}
	template <typename Type>
	Vector3<Type> Vector3<Type>::Multiply(const Vector3& vector, Type scalar) {
		return vector.Multiply(scalar);
	}

	template <typename Type>
	Vector3<Type> Vector3<Type>::Divide(const Vector3& vector1, const Vector3& vector2) {
		return vector1.Divide(vector2);
	}
	template <typename Type>
	Vector3<Type> Vector3<Type>::Divide(const Vector3& vector, Type scalar) {
		return vector.Divide(scalar);
	}

	template <typename Type>
	std::ostream& operator<<(std::ostream& ostream, const Vector3<Type>& vector) {
		return ostream <<
			"Vector3:" << std::endl <<
			"  X: " << vector.x << std::endl <<
			"  Y: " << vector.y << std::endl <<
			"  Z: " << vector.z << std::endl <<
			"  Magnitude: " << vector.mMagnitude;
	}

}