#pragma once

namespace Engine::Mathematics {

	template <typename Type>
	class Vector3 {
		Type mMagnitude;
		
	public:
		Type x;
		Type y;
		Type z;

	public:
		Vector3(Type x = 0.0f, Type y = 0.0f, Type z = 0.0f);
		virtual ~Vector3() = default;

		inline Type GetMagnitude() const { return mMagnitude; }

		static Type CalculateMagnitude(Type x, Type y, Type z);

		Vector3 Add(const Vector3& vector) const;
		Vector3 Add(Type scalar) const;

		Vector3 Subtract(const Vector3& vector) const;
		Vector3 Subtract(Type scalar) const;

		Vector3 Multiply(const Vector3& vector) const;
		Vector3 Multiply(Type scalar) const;

		Vector3 Divide(const Vector3& vector) const;
		Vector3 Divide(Type scalar) const;

		static Vector3 Add(const Vector3& vector1, const Vector3& vector2);
		static Vector3 Add(const Vector3& vector, Type scalar);

		static Vector3 Subtract(const Vector3& vector1, const Vector3& vector2);
		static Vector3 Subtract(const Vector3& vector, Type scalar);

		static Vector3 Multiply(const Vector3& vector1, const Vector3& vector2);
		static Vector3 Multiply(const Vector3& vector, Type scalar);

		static Vector3 Divide(const Vector3& vector1, const Vector3& vector2);
		static Vector3 Divide(const Vector3& vector, Type scalar);

		friend std::ostream& operator<<(std::ostream& ostream, const Vector3& vector);
	};

}