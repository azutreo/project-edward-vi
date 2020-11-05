#pragma once

namespace Engine {

	template <typename Type>
	class Vector3 {
		Type mMagnitude = 0;
		
	public:
		Type x = 0;
		Type y = 0;
		Type z = 0;

	public:
		inline Vector3(Type _x = 0, Type _y = 0, Type _z = 0)
		: x(_x), y(_y), z(_z) {
			mMagnitude = CalculateMagnitude(_x, _y, _z);
		};

		inline Type GetMagnitude() const { return mMagnitude; }

		inline static Type CalculateMagnitude(Type x = 0, Type y = 0, Type z = 0) {
			return std::sqrt(std::pow(x, 2) + std::pow(y, 2) + std::pow(z, 2));
		};

		inline Vector3 Add(const Vector3& vector) const {
			return Vector3(x + vector.x,
						   y + vector.y,
						   z + vector.z);
		};
		inline Vector3 Add(Type scalar) const {
			return Vector3(x + scalar,
						   y + scalar,
						   z + scalar);
		};

		inline Vector3 Subtract(const Vector3& vector) const {
			return Vector3(x - vector.x,
						   y - vector.y,
						   z - vector.z);
		};
		inline Vector3 Subtract(Type scalar) const {
			return Vector3(x - scalar,
						   y - scalar,
						   z - scalar);
		};

		inline Vector3 Multiply(const Vector3& vector) const {
			return Vector3(x * vector.x,
						   y * vector.y,
						   z * vector.z);
		};
		inline Vector3 Multiply(Type scalar) const {
			return Vector3(x * scalar,
						   y * scalar,
						   z * scalar);
		};

		inline Vector3 Divide(const Vector3& vector) const {
			return Vector3(x / vector.x,
						   y / vector.y,
						   z / vector.z);
		};
		inline Vector3 Divide(Type scalar) const {
			return Vector3(x / scalar,
						   y / scalar,
						   z / scalar);
		};

		inline static Vector3 Add(const Vector3& vector1, const Vector3& vector2) {
			return vector1.Add(vector2);
		};
		inline static Vector3 Add(const Vector3& vector, Type scalar) {
			return vector.Add(scalar);
		};

		inline static Vector3 Subtract(const Vector3& vector1, const Vector3& vector2) {
			return vector1.Subtract(vector2);
		};
		inline static Vector3 Subtract(const Vector3& vector, Type scalar) {
			return vector.Subtract(scalar);
		};

		inline static Vector3 Multiply(const Vector3& vector1, const Vector3& vector2) {
			return vector1.Multiply(vector2);
		};
		inline static Vector3 Multiply(const Vector3& vector, Type scalar) {
			return vector.Multiply(scalar);
		};

		inline static Vector3 Divide(const Vector3& vector1, const Vector3& vector2) {
			return vector1.Divide(vector2);
		};
		inline static Vector3 Divide(const Vector3& vector, Type scalar) {
			return vector.Divide(scalar);
		};

		inline friend std::ostream& operator<<(std::ostream& ostream, const Vector3& vector) {
			return ostream <<
				"Vector3:" << std::endl <<
				"  X: " << vector.x << std::endl <<
				"  Y: " << vector.y << std::endl <<
				"  Z: " << vector.z << std::endl <<
				"  Magnitude: " << vector.mMagnitude;
		};
	};

}