#pragma once

namespace Engine::Mathematics {

	class Vector3 {

		double mX;
		double mY;
		double mZ;
		double mMagnitude;

	public:

		Vector3(double x = 0, double y = 0, double z = 0);
		virtual ~Vector3() = default;

		void SetX(double x);
		void SetY(double y);
		void SetZ(double z);

		inline double GetX() const { return mX; }
		inline double GetY() const { return mY; }
		inline double GetZ() const { return mZ; }
		inline double GetMagnitude() const { return mMagnitude; }

		static double CalculateMagnitude(double x, double y, double z);

		Vector3 Add(const Vector3& vector) const;
		Vector3 Add(double scalar) const;

		Vector3 Subtract(const Vector3& vector) const;
		Vector3 Subtract(double scalar) const;

		Vector3 Multiply(const Vector3& vector) const;
		Vector3 Multiply(double scalar) const;

		Vector3 Divide(const Vector3& vector) const;
		Vector3 Divide(double scalar) const;

		static Vector3 Add(const Vector3& vector1, const Vector3& vector2);
		static Vector3 Add(const Vector3& vector, double scalar);

		static Vector3 Subtract(const Vector3& vector1, const Vector3& vector2);
		static Vector3 Subtract(const Vector3& vector, double scalar);

		static Vector3 Multiply(const Vector3& vector1, const Vector3& vector2);
		static Vector3 Multiply(const Vector3& vector, double scalar);

		static Vector3 Divide(const Vector3& vector1, const Vector3& vector2);
		static Vector3 Divide(const Vector3& vector, double scalar);

		friend std::ostream& operator<<(std::ostream& ostream, const Vector3& vector);

	};

}