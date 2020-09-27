#pragma once
#include "engine_precompiled/engine_precompiled.hpp"

#include "mathematics/vectors/vector3.hpp"

namespace Engine::Mathematics {

	Vector3::Vector3(double x, double y, double z) : mX(x), mY(y), mZ(z) {
		mMagnitude = CalculateMagnitude(mX, mY, mZ);
	}

	void Vector3::SetX(double x) {
		mX = x;
		mMagnitude = CalculateMagnitude(mX, mY, mZ);
	}
	void Vector3::SetY(double y) {
		mY = y;
		mMagnitude = CalculateMagnitude(mX, mY, mZ);
	}
	void Vector3::SetZ(double z) {
		mZ = z;
		mMagnitude = CalculateMagnitude(mX, mY, mZ);
	}

	double Vector3::CalculateMagnitude(double x, double y, double z) {
		return std::sqrt(std::pow(x, 2) + std::pow(y, 2) + std::pow(z, 2));
	}

	Vector3 Vector3::Add(const Vector3& vector) const {
		return Vector3(mX + vector.mX,
			mY + vector.mY,
			mZ + vector.mZ);
	}
	Vector3 Vector3::Add(double scalar) const {
		return Vector3(mX + scalar,
			mY + scalar,
			mZ + scalar);
	}

	Vector3 Vector3::Subtract(const Vector3& vector) const {
		return Vector3(mX - vector.mX,
			mY - vector.mY,
			mZ - vector.mZ);
	}
	Vector3 Vector3::Subtract(double scalar) const {
		return Vector3(mX - scalar,
			mY - scalar,
			mZ - scalar);
	}

	Vector3 Vector3::Multiply(const Vector3& vector) const {
		return Vector3(mX * vector.mX,
			mY * vector.mY,
			mZ * vector.mZ);
	}
	Vector3 Vector3::Multiply(double scalar) const {
		return Vector3(mX * scalar,
			mY * scalar,
			mZ * scalar);
	}

	Vector3 Vector3::Divide(const Vector3& vector) const {
		return Vector3(mX / vector.mX,
			mY / vector.mY,
			mZ / vector.mZ);
	}
	Vector3 Vector3::Divide(double scalar) const {
		return Vector3(mX / scalar,
			mY / scalar,
			mZ / scalar);
	}

	Vector3 Vector3::Add(const Vector3& vector1, const Vector3& vector2) {
		return vector1.Add(vector2);
	}
	Vector3 Vector3::Add(const Vector3& vector, double scalar) {
		return vector.Add(scalar);
	}

	Vector3 Vector3::Subtract(const Vector3& vector1, const Vector3& vector2) {
		return vector1.Subtract(vector2);
	}
	Vector3 Vector3::Subtract(const Vector3& vector, double scalar) {
		return vector.Subtract(scalar);
	}

	Vector3 Vector3::Multiply(const Vector3& vector1, const Vector3& vector2) {
		return vector1.Multiply(vector2);
	}
	Vector3 Vector3::Multiply(const Vector3& vector, double scalar) {
		return vector.Multiply(scalar);
	}

	Vector3 Vector3::Divide(const Vector3& vector1, const Vector3& vector2) {
		return vector1.Divide(vector2);
	}
	Vector3 Vector3::Divide(const Vector3& vector, double scalar) {
		return vector.Divide(scalar);
	}

	std::ostream& operator<<(std::ostream& ostream, const Vector3& vector) {
		return ostream <<
			"Vector3:" << std::endl <<
			"  X: " << vector.mX << std::endl <<
			"  Y: " << vector.mY << std::endl <<
			"  Z: " << vector.mZ << std::endl <<
			"  Magnitude: " << vector.mMagnitude;
	}

}