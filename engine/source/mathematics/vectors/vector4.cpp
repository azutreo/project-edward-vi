#pragma once
#include "engine_precompiled/engine_precompiled.hpp"

#include "mathematics/vectors/vector4.hpp"

namespace Engine::Mathematics {

	Vector4::Vector4(double x, double y, double z, double a) : mX(x), mY(y), mZ(z), mA(a) {
		mMagnitude = CalculateMagnitude(mX, mY, mZ, mA);
	}

	void Vector4::SetX(double x) {
		mX = x;
		mMagnitude = CalculateMagnitude(mX, mY, mZ, mA);
	}
	void Vector4::SetY(double y) {
		mY = y;
		mMagnitude = CalculateMagnitude(mX, mY, mZ, mA);
	}
	void Vector4::SetZ(double z) {
		mZ = z;
		mMagnitude = CalculateMagnitude(mX, mY, mZ, mA);
	}

	double Vector4::CalculateMagnitude(double x, double y, double z, double a) {
		return std::sqrt(std::pow(x, 2) + std::pow(y, 2) + std::pow(z, 2));
	}

	Vector4 Vector4::Add(const Vector4& vector) const {
		return Vector4(mX + vector.mX,
			mY + vector.mY,
			mZ + vector.mZ,
			mA + vector.mA);
	}
	Vector4 Vector4::Add(double scalar) const {
		return Vector4(mX + scalar,
			mY + scalar,
			mZ + scalar,
			mA + scalar);
	}

	Vector4 Vector4::Subtract(const Vector4& vector) const {
		return Vector4(mX - vector.mX,
			mY - vector.mY,
			mZ - vector.mZ,
			mA - vector.mA);
	}
	Vector4 Vector4::Subtract(double scalar) const {
		return Vector4(mX - scalar,
			mY - scalar,
			mZ - scalar,
			mA - scalar);
	}

	Vector4 Vector4::Multiply(const Vector4& vector) const {
		return Vector4(mX * vector.mX,
			mY * vector.mY,
			mZ * vector.mZ,
			mA * vector.mA);
	}
	Vector4 Vector4::Multiply(double scalar) const {
		return Vector4(mX * scalar,
			mY * scalar,
			mZ * scalar,
			mA * scalar);
	}

	Vector4 Vector4::Divide(const Vector4& vector) const {
		return Vector4(mX / vector.mX,
			mY / vector.mY,
			mZ / vector.mZ,
			mA / vector.mZ);
	}
	Vector4 Vector4::Divide(double scalar) const {
		return Vector4(mX / scalar,
			mY / scalar,
			mZ / scalar,
			mA / scalar);
	}

	Vector4 Vector4::Add(const Vector4& vector1, const Vector4& vector2) {
		return vector1.Add(vector2);
	}
	Vector4 Vector4::Add(const Vector4& vector, double scalar) {
		return vector.Add(scalar);
	}

	Vector4 Vector4::Subtract(const Vector4& vector1, const Vector4& vector2) {
		return vector1.Subtract(vector2);
	}
	Vector4 Vector4::Subtract(const Vector4& vector, double scalar) {
		return vector.Subtract(scalar);
	}

	Vector4 Vector4::Multiply(const Vector4& vector1, const Vector4& vector2) {
		return vector1.Multiply(vector2);
	}
	Vector4 Vector4::Multiply(const Vector4& vector, double scalar) {
		return vector.Multiply(scalar);
	}

	Vector4 Vector4::Divide(const Vector4& vector1, const Vector4& vector2) {
		return vector1.Divide(vector2);
	}
	Vector4 Vector4::Divide(const Vector4& vector, double scalar) {
		return vector.Divide(scalar);
	}

	std::ostream& operator<<(std::ostream& ostream, const Vector4& vector) {
		return ostream <<
			"Vector4:" << std::endl <<
			"  X: " << vector.mX << std::endl <<
			"  Y: " << vector.mY << std::endl <<
			"  Z: " << vector.mZ << std::endl <<
			"  A: " << vector.mA << std::endl <<
			"  Magnitude: " << vector.mMagnitude;
	}

}