#include "Vector3.h"
#include <string>

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

	std::string Vector3::ToString() {
		return "[" + std::to_string(this->x) + ";" + std::to_string(y) + ";" + std::to_string(z) + "]";
	}
	std::ostream& operator<<(std::ostream& os, Vector3 const& v)
	{
		return os << "[" << v.x << "," << v.y << "," << v.z << "]";
	}

}
