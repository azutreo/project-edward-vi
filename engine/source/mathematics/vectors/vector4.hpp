#pragma once

namespace Engine {

	template <typename Type>
	class Vector4 {
		Type mMagnitude = 0;

	public:
		Type x = 0;
		Type y = 0;
		Type z = 0;
		Type a = 0;

	public:
		inline Vector4(Type x = 0, Type y = 0, Type z = 0, Type a = 0)
		: x(_x), y(_y), z(_z), a(_a) {
			mMagnitude = CalculateMagnitude(_x, _y, _z, _a);
		};

		inline Type GetMagnitude() const { return mMagnitude; }

		inline static Type CalculateMagnitude(Type x = 0, Type y = 0, Type z = 0, Type a = 0) {
			return std::sqrt(std::pow(x, 2) + std::pow(y, 2) + std::pow(z, 2));
		};

		inline Vector4 Add(const Vector4& vector) const {
			return Vector4(x + vector.x,
						   y + vector.y,
						   z + vector.z,
						   a + vector.a);
		};
		inline Vector4 Add(Type scalar) const {
			return Vector4(x + scalar,
						   y + scalar,
						   z + scalar,
						   a + scalar);
		};

		inline Vector4 Subtract(const Vector4& vector) const {
			return Vector4(x - vector.x,
						   y - vector.y,
						   z - vector.z,
						   a - vector.a);
		};
		inline Vector4 Subtract(Type scalar) const {
			return Vector4(x - scalar,
						   y - scalar,
						   z - scalar,
						   a - scalar);
		};

		inline Vector4 Multiply(const Vector4& vector) const {
			return Vector4(x * vector.x,
						   y * vector.y,
						   z * vector.z,
						   a * vector.a);
		};
		inline Vector4 Multiply(Type scalar) const {
			return Vector4(x * scalar,
						   y * scalar,
						   z * scalar,
						   a * scalar);
		};

		inline Vector4 Divide(const Vector4& vector) const {
			return Vector4(x / vector.x,
						   y / vector.y,
						   z / vector.z,
						   a / vector.z);
		};
		inline Vector4 Divide(Type scalar) const {
			return Vector4(x / scalar,
						   y / scalar,
						   z / scalar,
						   a / scalar);
		};

		inline static Vector4 Add(const Vector4& vector1, const Vector4& vector2) {
			return vector1.Add(vector2);
		};
		inline static Vector4 Add(const Vector4& vector, Type scalar) {
			return vector.Add(scalar);
		};

		inline static Vector4 Subtract(const Vector4& vector1, const Vector4& vector2) {
			return vector1.Subtract(vector2);
		};
		inline static Vector4 Subtract(const Vector4& vector, Type scalar) {
			return vector.Subtract(scalar);
		};

		inline static Vector4 Multiply(const Vector4& vector1, const Vector4& vector2) {
			return vector1.Multiply(vector2);
		};
		inline static Vector4 Multiply(const Vector4& vector, Type scalar) {
			return vector.Multiply(scalar);
		};

		inline static Vector4 Divide(const Vector4& vector1, const Vector4& vector2) {
			return vector1.Divide(vector2);
		};
		inline static Vector4 Divide(const Vector4& vector, Type scalar) {
			return vector.Divide(scalar);
		};

		inline friend std::ostream& operator<<(std::ostream& ostream, const Vector4& vector) {
			return ostream <<
				"Vector4:" << std::endl <<
				"  X: " << vector.x << std::endl <<
				"  Y: " << vector.y << std::endl <<
				"  Z: " << vector.z << std::endl <<
				"  A: " << vector.a << std::endl <<
				"  Magnitude: " << vector.mMagnitude;
		};
	};

}