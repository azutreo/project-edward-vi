#pragma once
#include "engine_precompiled/engine_precompiled.hpp"

#include "mathematics/vectors/vector4.hpp"

namespace Engine::Mathematics {

	template <typename Type>
	Vector4<Type>::Vector4<Type>(Type _x, Type _y, Type _z, Type _a) : x(_x), y(_y), z(_z), a(_a) {
		mMagnitude = CalculateMagnitude(_x, _y, _z, _a);
	}

	template <typename Type>
	Type Vector4<Type>::CalculateMagnitude(Type x, Type y, Type z, Type a) {
		return std::sqrt(std::pow(x, 2) + std::pow(y, 2) + std::pow(z, 2));
	}

	template <typename Type>
	Vector4<Type> Vector4<Type>::Add(const Vector4& vector) const {
		return Vector4(x + vector.x,
			y + vector.y,
			z + vector.z,
			a + vector.a);
	}
	template <typename Type>
	Vector4<Type> Vector4<Type>::Add(Type scalar) const {
		return Vector4(x + scalar,
			y + scalar,
			z + scalar,
			a + scalar);
	}

	template <typename Type>
	Vector4<Type> Vector4<Type>::Subtract(const Vector4& vector) const {
		return Vector4(x - vector.x,
			y - vector.y,
			z - vector.z,
			a - vector.a);
	}
	template <typename Type>
	Vector4<Type> Vector4<Type>::Subtract(Type scalar) const {
		return Vector4(x - scalar,
			y - scalar,
			z - scalar,
			a - scalar);
	}

	template <typename Type>
	Vector4<Type> Vector4<Type>::Multiply(const Vector4& vector) const {
		return Vector4(x * vector.x,
			y * vector.y,
			z * vector.z,
			a * vector.a);
	}
	template <typename Type>
	Vector4<Type> Vector4<Type>::Multiply(Type scalar) const {
		return Vector4(x * scalar,
			y * scalar,
			z * scalar,
			a * scalar);
	}

	template <typename Type>
	Vector4<Type> Vector4<Type>::Divide(const Vector4& vector) const {
		return Vector4(x / vector.x,
			y / vector.y,
			z / vector.z,
			a / vector.z);
	}
	template <typename Type>
	Vector4<Type> Vector4<Type>::Divide(Type scalar) const {
		return Vector4(x / scalar,
			y / scalar,
			z / scalar,
			a / scalar);
	}

	template <typename Type>
	Vector4<Type> Vector4<Type>::Add(const Vector4& vector1, const Vector4& vector2) {
		return vector1.Add(vector2);
	}
	template <typename Type>
	Vector4<Type> Vector4<Type>::Add(const Vector4& vector, Type scalar) {
		return vector.Add(scalar);
	}

	template <typename Type>
	Vector4<Type> Vector4<Type>::Subtract(const Vector4& vector1, const Vector4& vector2) {
		return vector1.Subtract(vector2);
	}
	template <typename Type>
	Vector4<Type> Vector4<Type>::Subtract(const Vector4& vector, Type scalar) {
		return vector.Subtract(scalar);
	}

	template <typename Type>
	Vector4<Type> Vector4<Type>::Multiply(const Vector4& vector1, const Vector4& vector2) {
		return vector1.Multiply(vector2);
	}
	template <typename Type>
	Vector4<Type> Vector4<Type>::Multiply(const Vector4& vector, Type scalar) {
		return vector.Multiply(scalar);
	}

	template <typename Type>
	Vector4<Type> Vector4<Type>::Divide(const Vector4& vector1, const Vector4& vector2) {
		return vector1.Divide(vector2);
	}
	template <typename Type>
	Vector4<Type> Vector4<Type>::Divide(const Vector4& vector, Type scalar) {
		return vector.Divide(scalar);
	}

	template <typename Type>
	std::ostream& operator<<(std::ostream& ostream, const Vector4<Type>& vector) {
		return ostream <<
			"Vector4:" << std::endl <<
			"  X: " << vector.x << std::endl <<
			"  Y: " << vector.y << std::endl <<
			"  Z: " << vector.z << std::endl <<
			"  A: " << vector.a << std::endl <<
			"  Magnitude: " << vector.mMagnitude;
	}

}