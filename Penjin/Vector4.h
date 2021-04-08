#pragma once
#include "Vector3.h"
namespace Penjin
{
	class Vector4
		: public Vector3
	{
	public:
		float w;

		static const Vector4 Zero;

		Vector4();
		Vector4(float x, float y);
		Vector4(float x, float y, float z);
		Vector4(float x, float y, float z, float w);

		void Add(Vector4 vector);
		void Subtract(Vector4 vector);
		void Multiply(float value);
		void Divide(float value);

		void Normalize();
		virtual float GetLength() override;

		Vector4 operator+(Vector4 vector);
		Vector4& operator+=(Vector4 vector);
		Vector4 operator-(Vector4 vector);
		Vector4& operator-=(Vector4 vector);
		Vector4 operator*(float value);
		Vector4& operator*=(float value);
		Vector4 operator/(float value);
		Vector4& operator/=(float value);
		friend std::ostream& operator<<(std::ostream& os, Vector4 const& v);
	};
}

