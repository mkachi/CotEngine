#include "math/CotColor.h"
#include "math/CotColor32.h"

namespace Cot 
{
	Color::Color()
		:r(0), g(0), b(0), a(1.0f)
	{	}

	Color::Color(const float red, const float green, const float blue, const float alpha)
		: r(red), g(green), b(blue), a(alpha)
	{	}

	Color::Color(const float* arr)
		: r(arr[0]), g(arr[1]), b(arr[2]), a(arr[3])
	{	}

	Color::Color(const Color& color)
		: r(color.r), g(color.g), b(color.b), a(color.a)
	{	}

	Color::Color(const Color&& color)
		: r(color.r), g(color.g), b(color.b), a(color.a)
	{	}

	Color::Color(const Color32& color)
		: r(static_cast<float>(color.a / 255.0f))
		, g(static_cast<float>(color.g / 255.0f))
		, b(static_cast<float>(color.b / 255.0f))
		, a(static_cast<float>(color.a / 255.0f))
	{	}

	Color::~Color()
	{   }

	const Color Color::operator+(const Color& color) const
	{
		return Color(r + color.r, g + color.g, b + color.b, a + color.a);
	}

	const Color Color::operator-(const Color& color) const
	{
		return Color(r - color.r, g - color.g, b - color.b, a - color.a);
	}

	const Color Color::operator*(const Color& color) const
	{
		return Color(r * color.r, g * color.g, b * color.b, a * color.a);
	}

	const Color Color::operator/(const Color& color) const
	{
		return Color(r / color.r, g / color.g, b / color.b, a / color.a);
	}

	const Color Color::operator+(const float value) const
	{
		return Color(r + value, g + value, b + value, a + value);
	}

	const Color Color::operator-(const float value) const
	{
		return Color(r - value, g - value, b - value, a - value);
	}

	const Color Color::operator*(const float value) const
	{
		return Color(r * value, g * value, b * value, a * value);
	}

	const Color Color::operator/(const float value) const
	{
		COT_ASSERT(value <= 0.0f, "Division by 0");
		return Color(r / value, g / value, b / value, a / value);
	}

	Color& Color::operator+=(const Color& color)
	{
		r += color.r;
		g += color.g;
		b += color.b;
		a += color.a;
		return *this;
	}

	Color& Color::operator-=(const Color& color)
	{
		r -= color.r;
		g -= color.g;
		b -= color.b;
		a -= color.a;
		return *this;
	}

	Color& Color::operator*=(const Color& color)
	{
		r *= color.r;
		g *= color.g;
		b *= color.b;
		a *= color.a;
		return *this;
	}

	Color& Color::operator/=(const Color& color)
	{
		COT_ASSERT(color.r <= 0.0f, "Division by 0");
		COT_ASSERT(color.g <= 0.0f, "Division by 0");
		COT_ASSERT(color.b <= 0.0f, "Division by 0");
		COT_ASSERT(color.a <= 0.0f, "Division by 0");

		r /= color.r;
		g /= color.g;
		b /= color.b;
		a /= color.a;
		return *this;
	}

	Color& Color::operator+=(const float value)
	{
		r += value;
		g += value;
		b += value;
		a += value;
		return *this;
	}

	Color& Color::operator-=(const float value)
	{
		r -= value;
		g -= value;
		b -= value;
		a -= value;
		return *this;
	}

	Color& Color::operator*=(const float value)
	{
		r *= value;
		g *= value;
		b *= value;
		a *= value;
		return *this;
	}

	Color& Color::operator/=(const float value)
	{
		COT_ASSERT(value <= 0.0f, "Division by 0");

		r /= value;
		g /= value;
		b /= value;
		a /= value;
		return *this;
	}

	Color& Color::operator=(const Color& color)
	{
		r = color.r;
		g = color.g;
		b = color.b;
		a = color.a;
		return *this;
	}

	Color& Color::operator=(const Color32& color)
	{
		r = static_cast<float>(color.r / 255.0f);
		g = static_cast<float>(color.g / 255.0f);
		b = static_cast<float>(color.b / 255.0f);
		a = static_cast<float>(color.a / 255.0f);
		return *this;
	}

	bool Color::operator==(const Color& color) const
	{
		return (r == color.r && g == color.g && b == color.b && a == color.a);
	}

	bool Color::operator==(const Color32& color) const
	{
		return (r == static_cast<float>(color.r / 255.0f) && g == static_cast<float>(color.g / 255.0f) && b == static_cast<float>(color.b / 255.0f) && a == static_cast<float>(color.a / 255.0f));
	}

	bool Color::operator!=(const Color& color) const
	{
		return (r != color.r || g != color.g || b != color.b || a != color.a);
	}

	bool Color::operator!=(const Color32& color) const
	{
		return (r != static_cast<float>(color.r / 255.0f) || g != static_cast<float>(color.g / 255.0f) || b != static_cast<float>(color.b / 255.0f) || a != static_cast<float>(color.a / 255.0f));
	}

	const Color Color::White	( 1.0f,  1.0f,  1.0f, 1.0f);
	const Color Color::Yellow	( 1.0f,  1.0f,  0.0f, 1.0f);
	const Color Color::Blue		( 0.0f,  0.0f,  1.0f, 1.0f);
	const Color Color::Green	( 0.0f,  1.0f,  0.0f, 1.0f);
	const Color Color::Red		( 1.0f,  0.0f,  0.0f, 1.0f);
	const Color Color::Magenta	( 1.0f,  0.0f,  1.0f, 1.0f);
	const Color Color::Black	( 0.0f,  0.0f,  0.0f, 1.0f);
	const Color Color::Orange	( 1.0f,  0.5f,  0.0f, 1.0f);
	const Color Color::Gray		(0.65f, 0.65f, 0.65f, 1.0f);
}