#pragma once

namespace Engine {

	template <typename Type>
	class Vector2 {
		Type mMagnitude = 0;

	public:
		Type x = 0;
		Type y = 0;

	public:
		inline Vector2(Type _x = 0, Type _y = 0)
		: x(_x), y(_y) {
			mMagnitude = CalculateMagnitude(x, y);
		};

		inline Type GetMagnitude() const { return mMagnitude; }

		inline static Type CalculateMagnitude(Type x = 0, Type y = 0) {
			return std::sqrt(std::pow(x, 2) + std::pow(y, 2));
		};

		inline Vector2 Add(const Vector2& vector) const {
			return Vector2(x + vector.x,
						   y + vector.y);
		};
		inline Vector2 Add(Type scalar) const {
			return Vector2(x + scalar,
						   y + scalar);
		};

		inline Vector2 Subtract(const Vector2& vector) const {
			return Vector2(x - vector.x,
						   y - vector.y);
		};
		inline Vector2 Subtract(Type scalar) const {
			return Vector2(x - scalar,
						   y - scalar);
		};

		inline Vector2 Multiply(const Vector2& vector) const {
			return Vector2(x * vector.x,
						   y * vector.y);
		};
		inline Vector2 Multiply(Type scalar) const {
			return Vector2(x * scalar,
						   y * scalar);
		};

		inline Vector2 Divide(const Vector2& vector) const {
			return Vector2(x / vector.x,
						   y / vector.y);
		};
		inline Vector2 Divide(Type scalar) const {
			return Vector2(x / scalar,
						   y / scalar);
		};

		inline static Vector2 Add(const Vector2& vector1, const Vector2& Vector2) {
			return vector1.Add(Vector2);
		};
		inline static Vector2 Add(const Vector2& vector, Type scalar) {
			return vector.Add(scalar);
		};

		inline static Vector2 Subtract(const Vector2& vector1, const Vector2& Vector2) {
			return vector1.Subtract(Vector2);
		};
		inline static Vector2 Subtract(const Vector2& vector, Type scalar) {
			return vector.Subtract(scalar);
		};

		inline static Vector2 Multiply(const Vector2& vector1, const Vector2& Vector2) {
			return vector1.Multiply(Vector2);
		};
		inline static Vector2 Multiply(const Vector2& vector, Type scalar) {
			return vector.Multiply(scalar);
		};

		inline static Vector2 Divide(const Vector2& vector1, const Vector2& Vector2) {
			return vector1.Divide(Vector2);
		};
		inline static Vector2 Divide(const Vector2& vector, Type scalar) {
			return vector.Divide(scalar);
		};

		inline friend std::ostream& operator<<(std::ostream& ostream, const Vector2& vector) {
			return ostream <<
				"Vector2:" << std::endl <<
				"  X: " << vector.x << std::endl <<
				"  Y: " << vector.y << std::endl <<
				"  Magnitude: " << vector.mMagnitude;
		};
	};

}