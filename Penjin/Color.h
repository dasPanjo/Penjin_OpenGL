#pragma once
#include <iostream>
namespace Penjin {
	class Color
	{
	public:
		float r, g, b, a;
		Color();
		Color(float r, float g, float b);
		Color(float r, float g, float b, float a);

		void Add(Color vector);
		void Subtract(Color vector);
		void Multiply(float value);
		void Divide(float value);

		Color operator+(Color vector);
		Color& operator+=(Color vector);
		Color operator-(Color vector);
		Color& operator-=(Color vector);
		Color operator*(float value);
		Color& operator*=(float value);
		Color operator/(float value);
		Color& operator/=(float value);
		friend std::ostream& operator<<(std::ostream& os, Color const& v);
	};

}
