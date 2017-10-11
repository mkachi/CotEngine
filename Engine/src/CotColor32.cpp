#include "math/CotColor32.h"
#include "math/CotColor.h"

namespace Cot 
{
	Color32::Color32()
		:r(0), g(0), b(0), a(255)
	{	}

	Color32::Color32(const uchar red, const uchar green, const uchar blue, const uchar alpha)
		: r(red), g(green), b(blue), a(alpha)
	{	}

	Color32::Color32(const uchar* arr)
		: r(arr[0]), g(arr[1]), b(arr[2]), a(arr[3])
	{	}

	Color32::Color32(const Color32& color)
		: r(color.r), g(color.g), b(color.b), a(color.a)
	{	}

	Color32::Color32(const Color32&& color)
		: r(color.r), g(color.g), b(color.b), a(color.a)
	{	}

	Color32::Color32(const Color& color)
		: r(static_cast<uchar>(color.a * 255)), g(static_cast<uchar>(color.g * 255)), b(static_cast<uchar>(color.b * 255))
	{	}

	Color32::~Color32()
	{   }

	const Color32 Color32::operator+(const Color32& color) const
	{
		return Color32(r + color.r, g + color.g, b + color.b, a + color.a);
	}

	const Color32 Color32::operator-(const Color32& color) const
	{
		return Color32(r - color.r, g - color.g, b - color.b, a - color.a);
	}

	const Color32 Color32::operator*(const Color32& color) const
	{
		return Color32(r * color.r, g * color.g, b * color.b, a * color.a);
	}

	const Color32 Color32::operator/(const Color32& color) const
	{
		COT_ASSERT(color.r <= 0.0f, "Division by 0");
		COT_ASSERT(color.g <= 0.0f, "Division by 0");
		COT_ASSERT(color.b <= 0.0f, "Division by 0");
		COT_ASSERT(color.a <= 0.0f, "Division by 0");

		return Color32(r / color.r, g / color.g, b / color.b, a / color.a);
	}

	const Color32 Color32::operator+(float value) const
	{
		return Color32(r + value, g + value, b + value, a + value);
	}

	const Color32 Color32::operator-(float value) const
	{
		return Color32(r - value, g - value, b - value, a - value);
	}

	const Color32 Color32::operator*(float value) const
	{
		return Color32(r * value, g * value, b * value, a * value);
	}

	const Color32 Color32::operator/(float value) const
	{
		COT_ASSERT(value <= 0.0f, "Division by 0");
		return Color32(r / value, g / value, b / value, a / value);
	}

	Color32& Color32::operator+=(const Color32& color)
	{
		r += color.r;
		g += color.g;
		b += color.b;
		a += color.a;
		return *this;
	}

	Color32& Color32::operator-=(const Color32& color)
	{
		r -= color.r;
		g -= color.g;
		b -= color.b;
		a -= color.a;
		return *this;
	}

	Color32& Color32::operator*=(const Color32& color)
	{
		r *= color.r;
		g *= color.g;
		b *= color.b;
		a *= color.a;
		return *this;
	}

	Color32& Color32::operator/=(const Color32& color)
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

	Color32& Color32::operator+=(float value)
	{
		r += value;
		g += value;
		b += value;
		a += value;
		return *this;
	}

	Color32& Color32::operator-=(float value)
	{
		r -= value;
		g -= value;
		b -= value;
		a -= value;
		return *this;
	}

	Color32& Color32::operator*=(float value)
	{
		r *= value;
		g *= value;
		b *= value;
		a *= value;
		return *this;
	}

	Color32& Color32::operator/=(float value)
	{
		COT_ASSERT(value <= 0.0f, "Division by 0");

		r /= value;
		g /= value;
		b /= value;
		a /= value;
		return *this;
	}

	Color32& Color32::operator=(const Color32& color)
	{
		r = color.r;
		g = color.g;
		b = color.b;
		a = color.a;
		return *this;
	}

	Color32& Color32::operator=(const Color& color)
	{
		r = static_cast<uchar>(color.r * 255);
		g = static_cast<uchar>(color.g * 255);
		b = static_cast<uchar>(color.b * 255);
		a = static_cast<uchar>(color.a * 255);
		return *this;
	}

	bool Color32::operator==(const Color32& color) const
	{
		return (r == color.r && g == color.g && b == color.b && a == color.a);
	}

	bool Color32::operator==(const Color& color) const
	{
		return (r == static_cast<uchar>(color.r * 255) && g == static_cast<uchar>(color.g * 255) && b == static_cast<uchar>(color.b * 255) && a == static_cast<uchar>(color.a * 255));
	}

	bool Color32::operator!=(const Color32& color) const
	{
		return (r != color.r || g != color.g || b != color.b || a != color.a);
	}

	bool Color32::operator!=(const Color& color) const
	{
		return (r != static_cast<uchar>(color.r * 255) || g != static_cast<uchar>(color.g * 255) || b != static_cast<uchar>(color.b * 255) || a != static_cast<uchar>(color.a * 255));
	}

	const Color32 Color32::White	(255, 255, 255, 255);
	const Color32 Color32::Yellow	(255, 255,   0, 255);
	const Color32 Color32::Blue		(  0,   0, 255, 255);
	const Color32 Color32::Green	(  0, 255,   0, 255);
	const Color32 Color32::Red		(255,   0,   0, 255);
	const Color32 Color32::Magenta	(255,   0, 255, 255);
	const Color32 Color32::Black	(  0,   0,   0, 255);
	const Color32 Color32::Orange	(255, 127,   0, 255);
	const Color32 Color32::Gray		(166, 166, 166, 255);
}