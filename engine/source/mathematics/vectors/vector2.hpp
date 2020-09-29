#pragma once

namespace Engine::Mathematics {

	template <typename Type>
	class Vector2 {
		Type mMagnitude;

	public:
		Type x = 0;
		Type y = 0;

	public:
		Vector2(Type _x = 0, Type _y = 0);
		virtual ~Vector2() = default;

		inline Type GetMagnitude() const { return mMagnitude; }

		static Type CalculateMagnitude(Type x, Type y);

		Vector2 Add(const Vector2& vector) const;
		Vector2 Add(Type scalar) const;

		Vector2 Subtract(const Vector2& vector) const;
		Vector2 Subtract(Type scalar) const;

		Vector2 Multiply(const Vector2& vector) const;
		Vector2 Multiply(Type scalar) const;

		Vector2 Divide(const Vector2& vector) const;
		Vector2 Divide(Type scalar) const;

		static Vector2 Add(const Vector2& vector1, const Vector2& vector2);
		static Vector2 Add(const Vector2& vector, Type scalar);

		static Vector2 Subtract(const Vector2& vector1, const Vector2& vector2);
		static Vector2 Subtract(const Vector2& vector, Type scalar);

		static Vector2 Multiply(const Vector2& vector1, const Vector2& vector2);
		static Vector2 Multiply(const Vector2& vector, Type scalar);

		static Vector2 Divide(const Vector2& vector1, const Vector2& vector2);
		static Vector2 Divide(const Vector2& vector, Type scalar);

		friend std::ostream& operator<<(std::ostream& ostream, const Vector2& vector);
	};

}