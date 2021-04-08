#include "Vector4.h"

namespace Penjin {

	const Vector4 Vector4::Zero(0.0f, 0.0f, 0.0f);

	Vector4::Vector4()
		: Vector4(0.0f, 0.0f, 0.0f, 0.0f) {
	}
	Vector4::Vector4(float x, float y)
		: Vector4(x, y, 0.0f, 0.0f) {
	}
	Vector4::Vector4(float x, float y, float z)
		: Vector4(x, y, z, 0.0f) {
	}
	Vector4::Vector4(float x, float y, float z, float w)
		: Vector3(x, y, z), w(w) {
	}

	void Vector4::Add(Vector4 vector)
	{
		Vector3::Add(vector);
		this->w += vector.w;
	}
	void Vector4::Subtract(Vector4 vector) {
		Vector3::Subtract(vector);
		this->w -= vector.w;
	}
	void Vector4::Multiply(float value) {
		Vector3::Multiply(value);
		this->w *= value;
	}

	void Vector4::Divide(float value)
	{
		x /= x;
		y /= y;
		z /= z;
		w /= w;
	}

	void Vector4::Normalize()
	{
		float length = GetLength();
		if (length == 0) return;
		Divide(length);
	}

	float Vector4::GetLength()
	{
		return sqrt(x*x+y*y+z*z+w*w);
	}

	Vector4 Vector4::operator+(Vector4 vector)
	{
		Vector4 vec(this->x, this->y, this->z, this->w);
		vec.Add(vector);
		return vec;
	}
	Vector4& Vector4::operator+=(Vector4 vector)
	{
		this->Add(vector);
		return *this;
	}

	Vector4 Vector4::operator-(Vector4 vector)
	{
		Vector4 vec(this->x, this->y, this->z, this->w);
		vec.Subtract(vector);
		return vec;
	}

	Vector4& Vector4::operator-=(Vector4 vector)
	{
		this->Subtract(vector);
		return *this;
	}

	Vector4 Vector4::operator*(float value)
	{
		Vector4 vec(this->x, this->y, this->z, this->w);
		vec.Multiply(value);
		return vec;
	}

	Vector4& Vector4::operator*=(float value)
	{
		this->Multiply(value);
		return *this;
	}

	Vector4 Vector4::operator/(float value)
	{
		Vector4 vec(this->x, this->y, this->z, this->w);
		vec.Divide(value);
		return vec;
	}

	Vector4& Vector4::operator/=(float value)
	{
		this->Divide(value);
		return *this;
	}

	std::ostream& operator<<(std::ostream& os, Vector4 const& v)
	{
		return os << "[" << v.x << ";" << v.y << ";" << v.z << "]";
	}

}
