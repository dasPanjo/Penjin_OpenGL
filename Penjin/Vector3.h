#pragma once
#include "Vector2.h"

namespace Penjin {
	class Vector3 :
		public Vector2
	{
	public:
		float z;

		static const Vector3 Zero;

		Vector3();
		Vector3(float x, float y);
		Vector3(float x, float y, float z);

		void Add(Vector3 vector);
		void Subtract(Vector3 vector);
		void Multiply(float value);

		Vector3 operator+(Vector3 vector);
		Vector3& operator+=(Vector3 vector);
		Vector3 operator-(Vector3 vector);
		Vector3& operator-=(Vector3 vector);
		Vector3 operator*(float value);
		Vector3& operator*=(float value);

		std::string ToString();
		friend std::ostream& operator<<(std::ostream& os, Vector3 const& v);
	};
}

