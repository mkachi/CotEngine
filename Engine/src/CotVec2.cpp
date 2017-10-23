#include "math/CotVec2.h"
#include <cmath>

namespace Cot 
{
	Vec2::Vec2()
		: x(0.0f), y(0.0f)
	{	}

	Vec2::Vec2(const float value)
		: x(value), y(value)
	{	}

	Vec2::Vec2(const float xx, const float yy)
		: x(xx), y(yy)
	{	}

	Vec2::Vec2(const float* array)
		: x(array[0]), y(array[1])
	{	}

	Vec2::Vec2(const Vec2& other)
		: x(other.x), y(other.y)
	{	}

	Vec2::Vec2(const Vec2&& other)
		: x(other.x), y(other.y)
	{	}

	Vec2::~Vec2()
	{	}

	const Vec2 Vec2::operator+(const Vec2& other) const
	{
		return Vec2(x + other.x, y + other.y);
	}

	const Vec2 Vec2::operator-(const Vec2& other) const
	{
		return Vec2(x - other.x, y - other.y);
	}

	const Vec2 Vec2::operator*(const Vec2& other) const
	{
		return Vec2(x * other.x, y * other.y);
	}

	const Vec2 Vec2::operator/(const Vec2& other) const
	{
		float xx = 0.0f;
		if (other.x > 0.0f)
		{
			xx = x / other.x;
		}

		float yy = 0.0f;
		if (other.y > 0.0f)
		{
			yy = y / other.y;
		}
		return Vec2(xx, yy);
	}

	const Vec2 Vec2::operator+(const float value) const
	{
		return Vec2(x + value, y + value);
	}

	const Vec2 Vec2::operator-(const float value) const
	{
		return Vec2(x - value, y - value);
	}

	const Vec2 Vec2::operator*(const float value) const
	{
		return Vec2(x * value, y * value);
	}

	const Vec2 Vec2::operator/(const float value) const
	{
		float xx = 0.0f;
		if (value > 0.0f)
		{
			xx = x / value;
		}

		float yy = 0.0f;
		if (value > 0.0f)
		{
			yy = y / value;
		}
		return Vec2(xx, yy);
	}

	Vec2& Vec2::operator+=(const Vec2& other)
	{
		x += other.x;
		y += other.y;
		return *this;
	}

	Vec2& Vec2::operator-=(const Vec2& other)
	{
		x -= other.x;
		y -= other.y;
		return *this;
	}

	Vec2& Vec2::operator*=(const Vec2& other)
	{
		x *= other.x;
		y *= other.y;
		return *this;
	}

	Vec2& Vec2::operator/=(const Vec2& other)
	{
		float xx = 0.0f;
		if (other.x > 0.0f)
		{
			xx = x / other.x;
		}
		x = xx;

		float yy = 0.0f;
		if (other.y > 0.0f)
		{
			yy = y / other.y;
		}
		y = yy;

		return *this;
	}

	Vec2& Vec2::operator=(const Vec2& other)
	{
		x = other.x;
		y = other.y;
		return *this;
	}

	Vec2& Vec2::operator+=(const float value)
	{
		x += value;
		y += value;
		return *this;
	}

	Vec2& Vec2::operator-=(const float value)
	{
		x -= value;
		y -= value;
		return *this;
	}

	Vec2& Vec2::operator*=(const float value)
	{
		x *= value;
		y *= value;
		return *this;
	}

	Vec2& Vec2::operator/=(const float value)
	{
		if (value > 0.0f)
		{
			x /= value;
			y /= value;
		}
		else
		{
			x = y = 0.0f;
		}
		return *this;
	}

	Vec2& Vec2::operator=(const float value)
	{
		x = value;
		y = value;
		return *this;
	}

	const Vec2 Vec2::operator-() const
	{
		return Vec2(-x, -y);
	}

	bool Vec2::operator<(const Vec2& other) const
	{
		return (x < other.x && y < other.y);
	}

	bool Vec2::operator<=(const Vec2& other) const
	{
		return (x <= other.x && y <= other.y);
	}

	bool Vec2::operator>(const Vec2& other) const
	{
		return (x > other.x && y > other.y);
	}

	bool Vec2::operator>=(const Vec2& other) const
	{
		return (x >= other.x && y >= other.y);
	}

	bool Vec2::operator==(const Vec2& other) const
	{
		return (x == other.x && y == other.y);
	}

	bool Vec2::operator!=(const Vec2& other) const
	{
		return (x != other.x || y != other.y);
	}

	bool Vec2::IsZero() const
	{
		return (x == 0.0f && y == 0.0f);
	}

	bool Vec2::IsOne() const
	{
		return (x == 1.0f && y == 1.0f);
	}

	Vec2 Vec2::Normalize()
	{
		float length = sqrt(x * x + y * y);
		return Vec2(x / length, y / length);
	}

	Vec2 Vec2::Normalize(const Vec2& other)
	{
		float length = other.Length();
		return Vec2(other.x / length, other.y / length);
	}

	float Vec2::Length() const
	{
		return sqrt(x * x + y * y);
	}

	float Vec2::Distance(const Vec2& other) const
	{
		float deltaX = other.x - x;
		float deltaY = other.y - y;
		return sqrt(deltaX * deltaX + deltaY * deltaY);
	}

	float Vec2::Distance(const Vec2& other1, const Vec2& other2)
	{
		float deltaX = other1.x - other2.x;
		float deltaY = other1.y - other2.y;
		return sqrt(deltaX * deltaX + deltaY * deltaY);
	}

	float Vec2::Dot(const Vec2& other) const
	{
		return x * other.x + y * other.y;
	}

	float Vec2::Dot(const Vec2& other1, const Vec2& other2)
	{
		return other1.x * other2.x + other1.y * other2.y;
	}

	const Vec2 Vec2::Zero	( 0.0f,  0.0f);
	const Vec2 Vec2::One	( 1.0f,  1.0f);
									 
	const Vec2 Vec2::Up		( 0.0f,  1.0f);
	const Vec2 Vec2::Down	( 0.0f, -1.0f);
	const Vec2 Vec2::Left	(-1.0f,  0.0f);
	const Vec2 Vec2::Right	( 1.0f,  1.0f);

	const Vec2 Vec2::AxisX	( 1.0f,  0.0f);
	const Vec2 Vec2::AxisY	( 0.0f,  1.0f);
}