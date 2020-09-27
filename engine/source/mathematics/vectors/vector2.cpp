#pragma once
#include "engine_precompiled/engine_precompiled.hpp"

#include "mathematics/vectors/vector2.hpp"

namespace Engine::Mathematics {

	Vector2::Vector2(double x, double y) : mX(x), mY(y) {
		mMagnitude = CalculateMagnitude(mX, mY);
	}

	void Vector2::SetX(double x) {
		mX = x;
		mMagnitude = CalculateMagnitude(mX, mY);
	}
	void Vector2::SetY(double y) {
		mY = y;
		mMagnitude = CalculateMagnitude(mX, mY);
	}

	double Vector2::CalculateMagnitude(double x, double y) {
		return std::sqrt(std::pow(x, 2) + std::pow(y, 2));
	}

	Vector2 Vector2::Add(const Vector2& vector) const {
		return Vector2(mX + vector.mX,
			mY + vector.mY);
	}
	Vector2 Vector2::Add(double scalar) const {
		return Vector2(mX + scalar,
			mY + scalar);
	}

	Vector2 Vector2::Subtract(const Vector2& vector) const {
		return Vector2(mX - vector.mX,
			mY - vector.mY);
	}
	Vector2 Vector2::Subtract(double scalar) const {
		return Vector2(mX - scalar,
			mY - scalar);
	}

	Vector2 Vector2::Multiply(const Vector2& vector) const {
		return Vector2(mX * vector.mX,
			mY * vector.mY);
	}
	Vector2 Vector2::Multiply(double scalar) const {
		return Vector2(mX * scalar,
			mY * scalar);
	}

	Vector2 Vector2::Divide(const Vector2& vector) const {
		return Vector2(mX / vector.mX,
			mY / vector.mY);
	}
	Vector2 Vector2::Divide(double scalar) const {
		return Vector2(mX / scalar,
			mY / scalar);
	}

	Vector2 Vector2::Add(const Vector2& vector1, const Vector2& vector2) {
		return vector1.Add(vector2);
	}
	Vector2 Vector2::Add(const Vector2& vector, double scalar) {
		return vector.Add(scalar);
	}

	Vector2 Vector2::Subtract(const Vector2& vector1, const Vector2& vector2) {
		return vector1.Subtract(vector2);
	}
	Vector2 Vector2::Subtract(const Vector2& vector, double scalar) {
		return vector.Subtract(scalar);
	}

	Vector2 Vector2::Multiply(const Vector2& vector1, const Vector2& vector2) {
		return vector1.Multiply(vector2);
	}
	Vector2 Vector2::Multiply(const Vector2& vector, double scalar) {
		return vector.Multiply(scalar);
	}

	Vector2 Vector2::Divide(const Vector2& vector1, const Vector2& vector2) {
		return vector1.Divide(vector2);
	}
	Vector2 Vector2::Divide(const Vector2& vector, double scalar) {
		return vector.Divide(scalar);
	}

	std::ostream& operator<<(std::ostream& ostream, const Vector2& vector) {
		return ostream <<
			"Vector2:" << std::endl <<
			"  X: " << vector.mX << std::endl <<
			"  Y: " << vector.mY << std::endl <<
			"  Magnitude: " << vector.mMagnitude;
	}

}