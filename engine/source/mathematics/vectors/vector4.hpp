#pragma once

namespace Engine::Mathematics {

	class Vector4 {

		double mX;
		double mY;
		double mZ;
		double mA;
		double mMagnitude;

	public:

		Vector4(double x = 0, double y = 0, double z = 0, double a = 0);
		virtual ~Vector4() = default;

		void SetX(double x);
		void SetY(double y);
		void SetZ(double z);
		void SetA(double a);

		inline double GetX() const { return mX; }
		inline double GetY() const { return mY; }
		inline double GetZ() const { return mZ; }
		inline double GetA() const { return mA; }
		inline double GetMagnitude() const { return mMagnitude; }

		static double CalculateMagnitude(double x, double y, double z, double a);

		Vector4 Add(const Vector4& vector) const;
		Vector4 Add(double scalar) const;

		Vector4 Subtract(const Vector4& vector) const;
		Vector4 Subtract(double scalar) const;

		Vector4 Multiply(const Vector4& vector) const;
		Vector4 Multiply(double scalar) const;

		Vector4 Divide(const Vector4& vector) const;
		Vector4 Divide(double scalar) const;

		static Vector4 Add(const Vector4& vector1, const Vector4& vector2);
		static Vector4 Add(const Vector4& vector, double scalar);

		static Vector4 Subtract(const Vector4& vector1, const Vector4& vector2);
		static Vector4 Subtract(const Vector4& vector, double scalar);

		static Vector4 Multiply(const Vector4& vector1, const Vector4& vector2);
		static Vector4 Multiply(const Vector4& vector, double scalar);

		static Vector4 Divide(const Vector4& vector1, const Vector4& vector2);
		static Vector4 Divide(const Vector4& vector, double scalar);

		friend std::ostream& operator<<(std::ostream& ostream, const Vector4& vector);

	};

}