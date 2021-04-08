#include "Vector2.h"

namespace Penjin {

	const Vector2 Vector2::Zero(0.0f, 0.0f);

	Vector2::Vector2()
		: Vector2(0.0f,0.0f) {
	}

	Vector2::Vector2(float x, float y)
		: x(x), y(y) {
	}

	void Vector2::Add(Vector2 vector)
	{
		this->x += vector.x;
		this->y += vector.y;
	}
	void Vector2::Subtract(Vector2 vector)
	{
		this->x -= vector.x;
		this->y -= vector.y;
	}
	void Vector2::Multiply(float value)
	{
		this->x *= value;
		this->y *= value;
	}
	void Vector2::Divide(float value)
	{
		this->x /= value;
		this->y /= value;
	}

	void Vector2::Normalize()
	{
		float length = GetLength();
		if (length == 0) return;
		Divide(length);
	}

	float Vector2::GetLength()
	{
		return sqrt(x*x+y*y);
	}


	Vector2 Vector2::operator+(Vector2 vector)
	{
		Vector2 vec(this->x, this->y);
		vec.Add(vector);
		return vec;
	}

	Vector2& Vector2::operator+=(Vector2 vector)
	{
		this->Add(vector);
		return *this;
	}
	Vector2 Vector2::operator-(Vector2 vector)
	{
		Vector2 vec(this->x, this->y);
		vec.Subtract(vector);
		return vec;

	}
	Vector2& Vector2::operator-=(Vector2 vector)
	{
		this->Subtract(vector);
		return *this;
	}

	Vector2 Vector2::operator*(float value)
	{
		Vector2 vec(this->x, this->y);
		vec.Multiply(value);
		return vec;
	}
	Vector2& Vector2::operator*=(float value)
	{
		Multiply(value);
		return *this;
	}

	Vector2 Vector2::operator/(float value)
	{
		Vector2 vec(this->x, this->y);
		vec.Divide(value);
		return vec;

	}
	Vector2& Vector2::operator/=(float value)
	{
		Divide(value);
		return *this;
	}


	std::ostream& operator<<(std::ostream& os, Vector2 const& v)
	{
		return os << "[" << v.x << "," << v.y << "]";
	}

}
