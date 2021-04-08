#include "Color.h"

namespace Penjin {
	Color::Color()
		: Color(1.0f, 1.0f, 1.0f, 1.0f) {
	}
	Color::Color(float r, float g, float b)
		: Color(r, g, b, 1.0f) {
	}
	Color::Color(float r, float g, float b, float a)
		: r(r), g(g), b(b), a(a) {
	}

	void Color::Add(Color color)
	{
		this->r += color.r;
		this->g += color.g;
		this->b += color.b;
		this->a += color.a;
	}
	void Color::Subtract(Color color) {
		this->r -= color.r;
		this->g -= color.g;
		this->b -= color.b;
		this->a -= color.a;
	}
	void Color::Multiply(float value) {
		this->r *= value;
		this->g *= value;
		this->b *= value;
		this->a *= value;
	}

	void Color::Divide(float value) {
		this->r /= value;
		this->g /= value;
		this->b /= value;
		this->a /= value;
	}

	Color Color::operator+(Color color)
	{
		Color result(this->r, this->g, this->b, this->a);
		result.Add(color);
		return result;
	}
	Color& Color::operator+=(Color color)
	{
		this->Add(color);
		return *this;
	}

	Color Color::operator-(Color color)
	{
		Color result(this->r, this->g, this->b, this->a);
		result.Subtract(color);
		return result;
	}

	Color& Color::operator-=(Color color)
	{
		this->Subtract(color);
		return *this;
	}

	Color Color::operator*(float value)
	{
		Color color(this->r, this->g, this->b, this->a);
		color.Multiply(value);
		return color;
	}

	Color& Color::operator*=(float value)
	{
		this->Multiply(value);
		return *this;
	}

	Color Color::operator/(float value)
	{
		Color color(this->r, this->g, this->b, this->a);
		color.Divide(value);
		return color;
	}

	Color& Color::operator/=(float value)
	{
		this->Divide(value);
		return *this;
	}

	std::ostream& operator<<(std::ostream& os, Color const& c)
	{
		return os << "[" << c.r << ";" << c.g << ";" << c.b << "]";
	}
}
