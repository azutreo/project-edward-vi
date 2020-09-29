#pragma once
#include "engine_precompiled/engine_precompiled.hpp"

#include "mathematics/vectors/vector2.hpp"

namespace Engine::Mathematics {

	template <typename Type>
	Vector2<Type>::Vector2(Type _x, Type _y) : x(_x), y(_y) {
		mMagnitude = CalculateMagnitude(x, y);
	}

	template <typename Type>
	Type Vector2<Type>::CalculateMagnitude(Type x, Type y) {
		return std::sqrt(std::pow(x, 2) + std::pow(y, 2));
	}

	template <typename Type>
	Vector2<Type> Vector2<Type>::Add(const Vector2& vector) const {
		return Vector2(x + vector.x,
			y + vector.y);
	}
	template <typename Type>
	Vector2<Type> Vector2<Type>::Add(Type scalar) const {
		return Vector2(x + scalar,
			y + scalar);
	}

	template <typename Type>
	Vector2<Type> Vector2<Type>::Subtract(const Vector2& vector) const {
		return Vector2(x - vector.x,
			y - vector.y);
	}
	template <typename Type>
	Vector2<Type> Vector2<Type>::Subtract(Type scalar) const {
		return Vector2(x - scalar,
			y - scalar);
	}

	template <typename Type>
	Vector2<Type> Vector2<Type>::Multiply(const Vector2& vector) const {
		return Vector2(x * vector.x,
			y * vector.y);
	}
	template <typename Type>
	Vector2<Type> Vector2<Type>::Multiply(Type scalar) const {
		return Vector2(x * scalar,
			y * scalar);
	}

	template <typename Type>
	Vector2<Type> Vector2<Type>::Divide(const Vector2& vector) const {
		return Vector2(x / vector.x,
			y / vector.y);
	}
	template <typename Type>
	Vector2<Type> Vector2<Type>::Divide(Type scalar) const {
		return Vector2(x / scalar,
			y / scalar);
	}

	template <typename Type>
	Vector2<Type> Vector2<Type>::Add(const Vector2& vector1, const Vector2& vector2) {
		return vector1.Add(vector2);
	}
	template <typename Type>
	Vector2<Type> Vector2<Type>::Add(const Vector2& vector, Type scalar) {
		return vector.Add(scalar);
	}

	template <typename Type>
	Vector2<Type> Vector2<Type>::Subtract(const Vector2& vector1, const Vector2& vector2) {
		return vector1.Subtract(vector2);
	}
	template <typename Type>
	Vector2<Type> Vector2<Type>::Subtract(const Vector2& vector, Type scalar) {
		return vector.Subtract(scalar);
	}

	template <typename Type>
	Vector2<Type> Vector2<Type>::Multiply(const Vector2& vector1, const Vector2& vector2) {
		return vector1.Multiply(vector2);
	}
	template <typename Type>
	Vector2<Type> Vector2<Type>::Multiply(const Vector2& vector, Type scalar) {
		return vector.Multiply(scalar);
	}

	template <typename Type>
	Vector2<Type> Vector2<Type>::Divide(const Vector2& vector1, const Vector2& vector2) {
		return vector1.Divide(vector2);
	}
	template <typename Type>
	Vector2<Type> Vector2<Type>::Divide(const Vector2& vector, Type scalar) {
		return vector.Divide(scalar);
	}

	template <typename Type>
	std::ostream& operator<<(std::ostream& ostream, const Vector2<Type>& vector) {
		return ostream <<
			"Vector2:" << std::endl <<
			"  X: " << vector.x << std::endl <<
			"  Y: " << vector.y << std::endl <<
			"  Magnitude: " << vector.mMagnitude;
	}

	template class Vector2<float>;
	template class Vector2<int>;
	template class Vector2<double>;

}