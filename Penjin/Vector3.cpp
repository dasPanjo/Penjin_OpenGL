#include "Vector3.h"
#include <string>
#include <iostream>
#include <cmath>

namespace Penjin {

	const Vector3 Vector3::Zero(0.0f,0.0f,0.0f);

	Vector3::Vector3()
		: Vector3(0.0f, 0.0f, 0.0f) {
	}
	Vector3::Vector3(float x, float y)
		: Vector3(x, y, 0.0f) {
	}
	Vector3::Vector3(float x, float y, float z)
		: Vector2(x, y), z(z) {
	}

	void Vector3::Add(Vector3 vector)
	{
		Vector2::Add(vector);
		this->z += vector.z;
	}
	void Vector3::Subtract(Vector3 vector)
	{
		Vector2::Subtract(vector);
		this->z -= vector.z;
	}
	void Vector3::Multiply(float value)
	{
		Vector2::Multiply(value);
		this->z *= value;
	}

	void Vector3::Divide(float value)
	{
		x /= value;
		y /= value;
		z /= value;
	}

	//float Vector3::GetLength()
	//{
	//	return sqrt(x*x+y*y+z*z);
	//}

	float lerp(float a, float b, float f) {
		return a + f * (b - a);
	}

	Vector3 Vector3::Lerp(Vector3 vector1, Vector3 vector2, float t) {
		Vector3 vec;
		vec.x = lerp(vector1.x, vector2.x, t);
		vec.y = lerp(vector1.y, vector2.y, t);
		vec.z = lerp(vector1.z, vector2.z, t);
		return vec;
	}

	void Vector3::Normalize()
	{
		float length = GetLength();
		if (length == 0) return;
		Divide(length);
	}

	float Vector3::GetLength()
	{
		return sqrt(x * x + y * y + z * z);
	}

	Vector3 Vector3::operator+(Vector3 vector)
	{
		Vector3 vec(this->x, this->y, this->z);
		vec.Add(vector);
		return vec;
	}
	Vector3& Vector3::operator+=(Vector3 vector)
	{
		this->Add(vector);
		return *this;
	}

	Vector3 Vector3::operator-(Vector3 vector)
	{
		Vector3 vec(this->x, this->y, this->z);
		vec.Subtract(vector);
		return vec;
	}
	Vector3& Vector3::operator-=(Vector3 vector)
	{
		this->Subtract(vector);
		return *this;
	}
	Vector3 Vector3::operator*(float value)
	{
		Vector3 vec(this->x, this->y, this->z);
		vec.Multiply(value);
		return vec;
	}
	Vector3& Vector3::operator*=(float value)
	{
		this->Multiply(value);
		return *this;
	}
	Vector3 Vector3::operator/(float value)
	{
		Vector3 vec(this->x, this->y, this->z);
		vec.Divide(value);
		return vec;
	}
	Vector3& Vector3::operator/=(float value)
	{
		this->Divide(value);
		return *this;
	}

	std::string Vector3::ToString() {
		return "[" + std::to_string(this->x) + ";" + std::to_string(y) + ";" + std::to_string(z) + "]";
	}
	std::ostream& operator<<(std::ostream& os, Vector3 const& v)
	{
		return os << "[" << v.x << "," << v.y << "," << v.z << "]";
	}

}
