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
		return Vector2(this->x *value, this->y * value);
	}
	Vector2& Vector2::operator*=(float value)
	{
		Vector2 vec(this->x, this->y);
		vec.Multiply(value);
		return vec;
	}


	std::ostream& operator<<(std::ostream& os, Vector2 const& v)
	{
		return os << "[" << v.x << "," << v.y << "]";
	}

}
