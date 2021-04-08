#pragma once
#include <iostream>

namespace Penjin {
	class Vector2
	{
	public:
		float x, y;

		static const Vector2 Zero;

		Vector2();
		Vector2(float x, float y);

		void Add(Vector2 vector);
		void Subtract(Vector2 vector);
		void Multiply(float value);
		void Divide(float value);

		void Normalize();
		virtual float GetLength();

		Vector2 operator+(Vector2 vector);
		Vector2& operator+=(Vector2 vector);

		Vector2 operator-(Vector2 vector);
		Vector2& operator-=(Vector2 vector);

		Vector2 operator*(float value);
		Vector2& operator*=(float value);

		Vector2 operator/(float value);
		Vector2& operator/=(float value);

		friend std::ostream& operator<<(std::ostream& os, Vector2 const& v);
	};
}

