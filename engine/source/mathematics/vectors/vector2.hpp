#pragma once

namespace Engine::Mathematics {

	class Vector2 {
		double mX;
		double mY;
		double mMagnitude;

	public:
		Vector2(double x = 0, double y = 0);
		virtual ~Vector2() = default;

		void SetX(double x);
		void SetY(double y);

		inline double GetX() const { return mX; }
		inline double GetY() const { return mY; }
		inline double GetMagnitude() const { return mMagnitude; }

		static double CalculateMagnitude(double x, double y);

		Vector2 Add(const Vector2& vector) const;
		Vector2 Add(double scalar) const;

		Vector2 Subtract(const Vector2& vector) const;
		Vector2 Subtract(double scalar) const;

		Vector2 Multiply(const Vector2& vector) const;
		Vector2 Multiply(double scalar) const;

		Vector2 Divide(const Vector2& vector) const;
		Vector2 Divide(double scalar) const;

		static Vector2 Add(const Vector2& vector1, const Vector2& vector2);
		static Vector2 Add(const Vector2& vector, double scalar);

		static Vector2 Subtract(const Vector2& vector1, const Vector2& vector2);
		static Vector2 Subtract(const Vector2& vector, double scalar);

		static Vector2 Multiply(const Vector2& vector1, const Vector2& vector2);
		static Vector2 Multiply(const Vector2& vector, double scalar);

		static Vector2 Divide(const Vector2& vector1, const Vector2& vector2);
		static Vector2 Divide(const Vector2& vector, double scalar);

		friend std::ostream& operator<<(std::ostream& ostream, const Vector2& vector);
	};

}