#pragma once

namespace Engine::Mathematics {

	template <typename Type>
	class Vector4 {
		Type mMagnitude;

	public:
		Type x;
		Type y;
		Type z;
		Type a;

	public:
		Vector4(Type x = 0.0f, Type y = 0.0f, Type z = 0.0f, Type a = 0.0f);
		virtual ~Vector4() = default;

		inline Type GetMagnitude() const { return mMagnitude; }

		static Type CalculateMagnitude(Type x, Type y, Type z, Type a);

		Vector4 Add(const Vector4& vector) const;
		Vector4 Add(Type scalar) const;

		Vector4 Subtract(const Vector4& vector) const;
		Vector4 Subtract(Type scalar) const;

		Vector4 Multiply(const Vector4& vector) const;
		Vector4 Multiply(Type scalar) const;

		Vector4 Divide(const Vector4& vector) const;
		Vector4 Divide(Type scalar) const;

		static Vector4 Add(const Vector4& vector1, const Vector4& vector2);
		static Vector4 Add(const Vector4& vector, Type scalar);

		static Vector4 Subtract(const Vector4& vector1, const Vector4& vector2);
		static Vector4 Subtract(const Vector4& vector, Type scalar);

		static Vector4 Multiply(const Vector4& vector1, const Vector4& vector2);
		static Vector4 Multiply(const Vector4& vector, Type scalar);

		static Vector4 Divide(const Vector4& vector1, const Vector4& vector2);
		static Vector4 Divide(const Vector4& vector, Type scalar);

		friend std::ostream& operator<<(std::ostream& ostream, const Vector4& vector);
	};

}