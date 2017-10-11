#include "math/CotVec4.h"
#include "math/CotVec2.h"
#include "math/CotVec3.h"
#include <cmath>

namespace Cot 
{
	Vec4::Vec4()
		: x(0.0f), y(0.0f), z(0.0f), w(0.0f)
	{	}

	Vec4::Vec4(const float value)
		: x(value), y(value), z(value), w(value)
	{	}

	Vec4::Vec4(const float xx, const float yy)
		: x(xx), y(yy), z(0.0f), w(0.0f)
	{	}

	Vec4::Vec4(const Vec2& other)
		: x(other.x), y(other.y), z(0.0f), w(0.0f)
	{	}

	Vec4::Vec4(const float xx, const float yy, const float zz)
		: x(xx), y(yy), z(zz), w(0.0f)
	{	}

	Vec4::Vec4(const Vec3& other)
		: x(other.x), y(other.y), z(other.z), w(0.0f)
	{	}

	Vec4::Vec4(const float xx, const float yy, const float zz, const float ww)
		: x(xx), y(yy), z(zz), w(ww)
	{	}

	Vec4::Vec4(const float* array)
		: x(array[0]), y(array[1]), z(array[2]), w(array[3])
	{	}

	Vec4::Vec4(const Vec4& other)
		: x(other.x), y(other.y), z(other.z), w(other.w)
	{	}

	Vec4::Vec4(const Vec4&& other)
		: x(other.x), y(other.y), z(other.z), w(other.w)
	{	}

	Vec4::~Vec4()
	{	}

	const Vec4 Vec4::operator+(const Vec4& other) const
	{
		return Vec4(x + other.x, y + other.y, z + other.z, w + other.w);
	}

	const Vec4 Vec4::operator-(const Vec4& other) const
	{
		return Vec4(x - other.x, y - other.y, z - other.z, w - other.w);
	}

	const Vec4 Vec4::operator*(const Vec4& other) const
	{
		return Vec4(x * other.x, y * other.y, z * other.z, w * other.w);
	}

	const Vec4 Vec4::operator/(const Vec4& other) const
	{
		COT_ASSERT(other.x <= 0.0f, "Division by 0");
		COT_ASSERT(other.y <= 0.0f, "Division by 0");
		COT_ASSERT(other.z <= 0.0f, "Division by 0");
		COT_ASSERT(other.w <= 0.0f, "Division by 0");

		return Vec4(x / other.x, y / other.y, z / other.z, w / other.w);
	}

	const Vec4 Vec4::operator+(const float value) const
	{
		return Vec4(x + value, y + value, z + value, w + value);
	}

	const Vec4 Vec4::operator-(const float value) const
	{
		return Vec4(x - value, y - value, z - value, w - value);
	}

	const Vec4 Vec4::operator*(const float value) const
	{
		return Vec4(x * value, y * value, z * value, w * value);
	}

	const Vec4 Vec4::operator/(const float value) const
	{
		COT_ASSERT(value <= 0.0f, "Division by 0");

		return Vec4(x / value, y / value, z / value, w / value);
	}

	Vec4& Vec4::operator+=(const Vec4& other)
	{
		x += other.x;
		y += other.y;
		z += other.z;
		w += other.w;
		return *this;
	}

	Vec4& Vec4::operator-=(const Vec4& other)
	{
		x -= other.x;
		y -= other.y;
		z -= other.z;
		w -= other.w;
		return *this;
	}

	Vec4& Vec4::operator*=(const Vec4& other)
	{
		x *= other.x;
		y *= other.y;
		z *= other.z;
		w *= other.w;
		return *this;
	}

	Vec4& Vec4::operator/=(const Vec4& other)
	{
		COT_ASSERT(other.x <= 0.0f, "Division by 0");
		COT_ASSERT(other.y <= 0.0f, "Division by 0");
		COT_ASSERT(other.z <= 0.0f, "Division by 0");
		COT_ASSERT(other.w <= 0.0f, "Division by 0");

		x /= other.x;
		y /= other.y;
		z /= other.z;
		w /= other.w;
		return *this;
	}

	Vec4& Vec4::operator=(const Vec4& other)
	{
		x = other.x;
		y = other.y;
		z = other.z;
		w = other.w;
		return *this;
	}

	Vec4& Vec4::operator+=(const float value)
	{
		x += value;
		y += value;
		z += value;
		w += value;
		return *this;
	}

	Vec4& Vec4::operator-=(const float value)
	{
		x -= value;
		y -= value;
		z -= value;
		w -= value;
		return *this;
	}

	Vec4& Vec4::operator*=(const float value)
	{
		x *= value;
		y *= value;
		z *= value;
		w *= value;
		return *this;
	}

	Vec4& Vec4::operator/=(const float value)
	{
		COT_ASSERT(value <= 0.0f, "Division by 0");

		x /= value;
		y /= value;
		z /= value;
		w /= value;
		return *this;
	}

	Vec4& Vec4::operator=(const float value)
	{
		x = value;
		y = value;
		z = value;
		w = value;
		return *this;
	}

	const Vec4 Vec4::operator-() const
	{
		return Vec4(-x, -y, -z, -w);
	}

	bool Vec4::operator<(const Vec4& other) const
	{
		return (x < other.x && y < other.y && z < other.z && w < other.w);
	}

	bool Vec4::operator<=(const Vec4& other) const
	{
		return (x <= other.x && y <= other.y && z <= other.z && w <= other.w);
	}

	bool Vec4::operator>(const Vec4& other) const
	{
		return (x > other.x && y > other.y && z > other.z && w > other.w);
	}

	bool Vec4::operator>=(const Vec4& other) const
	{
		return (x >= other.x && y >= other.y && z >= other.z && w >= other.w);
	}

	bool Vec4::operator==(const Vec4& other) const
	{
		return (x == other.x && y == other.y && z == other.z && w == other.w);
	}

	bool Vec4::operator!=(const Vec4& other) const
	{
		return (x != other.x || y != other.y || z != other.z, w != other.w);
	}

	bool Vec4::IsZero() const
	{
		return (x == 0.0f && y == 0.0f && z == 0.0f && w == 0.0f);
	}

	bool Vec4::IsOne() const
	{
		return (x == 1.0f && y == 1.0f && z == 1.0f && w == 1.0f);
	}

	Vec4 Vec4::Normalize()
	{
		float length = sqrt(x * x + y * y + z * z + w * w);
		return Vec4(x / length, y / length, z / length, w / length);
	}

	Vec4 Vec4::Normalize(const Vec4& other)
	{
		float length = other.Length();
		return Vec4(other.x / length, other.y / length, other.z / length, other.w / length);
	}

	float Vec4::Length() const
	{
		return sqrt(x * x + y * y + z * z + w * w);
	}

	float Vec4::Distance(const Vec4& other) const
	{
		float deltaX = (other.x - x);
		float deltaY = (other.y - y);
		float deltaZ = (other.z - z);
		float deltaW = (other.w - w);
		return sqrt(deltaX * deltaX + deltaY * deltaY + deltaZ * deltaZ + deltaW * deltaW);
	}

	float Vec4::Distance(const Vec4& other1, const Vec4& other2)
	{
		float deltaX = (other1.x - other2.x);
		float deltaY = (other1.y - other2.y);
		float deltaZ = (other1.z - other2.z);
		float deltaW = (other1.w - other2.w);
		return sqrt(deltaX * deltaX + deltaY * deltaY + deltaZ * deltaZ + deltaW * deltaW);
	}

	float Vec4::Dot(const Vec4& other) const
	{
		return x * other.x + y * other.y + z * other.z + w * other.w;
	}

	float Vec4::Dot(const Vec4& other1, const Vec4& other2)
	{
		return other1.x * other2.x + other1.y * other2.y + other1.z * other2.z + other1.w * other2.w;
	}

	const Vec4 Vec4::Zero	(0.0f, 0.0f, 0.0f, 0.0f);
	const Vec4 Vec4::One	(1.0f, 1.0f, 1.0f, 1.0f);
}