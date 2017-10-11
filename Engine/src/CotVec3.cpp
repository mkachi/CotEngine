#include "math/CotVec3.h"
#include "math/CotVec2.h"
#include "math/CotMat4.h"

namespace Cot 
{
	Vec3::Vec3()
		: x(0.0f), y(0.0f), z(0.0f)
	{	}

	Vec3::Vec3(const float value)
		: x(value), y(value), z(value)
	{	}

	Vec3::Vec3(const float xx, const float yy)
		: x(xx), y(yy), z(0.0f)
	{	}

	Vec3::Vec3(const Vec2& other)
		: x(other.x), y(other.y), z(0.0f)
	{	}

	Vec3::Vec3(const float xx, const float yy, const float zz)
		: x(xx), y(yy), z(zz)
	{	}

	Vec3::Vec3(const float* array)
		: x(array[0]), y(array[1]), z(array[2])
	{	}

	Vec3::Vec3(const Vec3& other)
		: x(other.x), y(other.y), z(other.z)
	{	}

	Vec3::Vec3(const Vec3&& other)
		: x(other.x), y(other.y), z(other.z)
	{	}

	Vec3::~Vec3()
	{	}

	const Vec3 Vec3::operator+(const Vec3& other) const
	{
		return Vec3(x + other.x, y + other.y, z + other.z);
	}

	const Vec3 Vec3::operator-(const Vec3& other) const
	{
		return Vec3(x - other.x, y - other.y, z - other.z);
	}

	const Vec3 Vec3::operator*(const Vec3& other) const
	{
		return Vec3(x * other.x, y * other.y, z * other.z);
	}

	const Vec3 Vec3::operator/(const Vec3& other) const
	{
		COT_ASSERT(other.x <= 0.0f, "Division by 0");
		COT_ASSERT(other.y <= 0.0f, "Division by 0");
		COT_ASSERT(other.z <= 0.0f, "Division by 0");

		return Vec3(x / other.x, y / other.y, z / other.z);
	}

	const Vec3 Vec3::operator+(const float value) const
	{
		return Vec3(x + value, y + value, z + value);
	}

	const Vec3 Vec3::operator-(const float value) const
	{
		return Vec3(x - value, y - value, z - value);
	}

	const Vec3 Vec3::operator*(const float value) const
	{
		return Vec3(x * value, y * value, z * value);
	}

	const Vec3 Vec3::operator/(const float value) const
	{
		COT_ASSERT(value <= 0.0f, "Division by 0");

		return Vec3(x / value, y / value, z / value);
	}

	Vec3& Vec3::operator+=(const Vec3& other)
	{
		x += other.x;
		y += other.y;
		z += other.z;
		return *this;
	}

	Vec3& Vec3::operator-=(const Vec3& other)
	{
		x -= other.x;
		y -= other.y;
		z -= other.z;
		return *this;
	}

	Vec3& Vec3::operator*=(const Vec3& other)
	{
		x *= other.x;
		y *= other.y;
		z *= other.z;
		return *this;
	}

	Vec3& Vec3::operator/=(const Vec3& other)
	{
		COT_ASSERT(other.x <= 0.0f, "Division by 0");
		COT_ASSERT(other.y <= 0.0f, "Division by 0");
		COT_ASSERT(other.z <= 0.0f, "Division by 0");

		x /= other.x;
		y /= other.y;
		z /= other.z;
		return *this;
	}

	Vec3& Vec3::operator=(const Vec3& other)
	{
		x = other.x;
		y = other.y;
		z = other.z;
		return *this;
	}

	Vec3& Vec3::operator+=(const float value)
	{
		x += value;
		y += value;
		z += value;
		return *this;
	}

	Vec3& Vec3::operator-=(const float value)
	{
		x -= value;
		y -= value;
		z -= value;
		return *this;
	}

	Vec3& Vec3::operator*=(const float value)
	{
		x *= value;
		y *= value;
		z *= value;
		return *this;
	}

	Vec3& Vec3::operator/=(const float value)
	{
		COT_ASSERT(value <= 0.0f, "Division by 0");

		x /= value;
		y /= value;
		z /= value;
		return *this;
	}

	Vec3& Vec3::operator=(const float value)
	{
		x = value;
		y = value;
		z = value;
		return *this;
	}

	const Vec3 Vec3::operator*(const Mat4& mat) const
	{
		return Vec3(
			mat.ToArray4x4[0][0] * x +
			mat.ToArray4x4[0][1] * y +
			mat.ToArray4x4[0][2] * z +
			mat.ToArray4x4[0][3] + mat.ToArray4x4[3][0],

			mat.ToArray4x4[1][0] * x +
			mat.ToArray4x4[1][1] * y +
			mat.ToArray4x4[1][2] * z +
			mat.ToArray4x4[1][3] + mat.ToArray4x4[3][1],

			mat.ToArray4x4[2][0] * x +
			mat.ToArray4x4[2][1] * y +
			mat.ToArray4x4[2][2] * z +
			mat.ToArray4x4[2][3] + mat.ToArray4x4[3][2]);
	}

	Vec3& Vec3::operator*=(const Mat4& mat)
	{
		Vec3 temp(*this);
		x =
			mat.ToArray4x4[0][0] * temp.x +
			mat.ToArray4x4[0][1] * temp.y +
			mat.ToArray4x4[0][2] * temp.z +
			mat.ToArray4x4[0][3] + mat.ToArray4x4[3][0];

		y = mat.ToArray4x4[1][0] * temp.x +
			mat.ToArray4x4[1][1] * temp.y +
			mat.ToArray4x4[1][2] * temp.z +
			mat.ToArray4x4[1][3] + mat.ToArray4x4[3][1];

		z = mat.ToArray4x4[2][0] * temp.x +
			mat.ToArray4x4[2][1] * temp.y +
			mat.ToArray4x4[2][2] * temp.z +
			mat.ToArray4x4[2][3] + mat.ToArray4x4[3][2];

		return *this;
	}

	const Vec3 Vec3::operator-() const
	{
		return Vec3(-x, -y, -z);
	}

	bool Vec3::operator<(const Vec3& other) const
	{
		return (x < other.x && y < other.y && z < other.z);
	}

	bool Vec3::operator<=(const Vec3& other) const
	{
		return (x <= other.x && y <= other.y && z <= other.z);
	}

	bool Vec3::operator>(const Vec3& other) const
	{
		return (x > other.x && y > other.y && z > other.z);
	}

	bool Vec3::operator>=(const Vec3& other) const
	{
		return (x >= other.x && y >= other.y && z >= other.z);
	}

	bool Vec3::operator==(const Vec3& other) const
	{
		return (x == other.x && y == other.y && z == other.z);
	}

	bool Vec3::operator!=(const Vec3& other) const
	{
		return (x != other.x || y != other.y || z != other.z);
	}

	bool Vec3::IsZero() const
	{
		return (x == 0.0f && y == 0.0f && z == 0.0f);
	}

	bool Vec3::IsOne() const
	{
		return (x == 1.0f && y == 1.0f && z == 1.0f);
	}

	Vec3 Vec3::Normalize()
	{
		float length = sqrt(x * x + y * y + z * z);
		return Vec3(x / length, y / length, z / length);
	}

	Vec3 Vec3::Normalize(const Vec3& other)
	{
		float length = other.Length();
		return Vec3(other.x / length, other.y / length, other.z / length);
	}

	float Vec3::Length() const
	{
		return sqrt(x * x + y * y + z * z);
	}

	float Vec3::Distance(const Vec3& other) const
	{
		float deltaX = (other.x - x);
		float deltaY = (other.y - y);
		float deltaZ = (other.z - z);
		return sqrt(deltaX * deltaX + deltaY * deltaY + deltaZ * deltaZ);
	}

	float Vec3::Distance(const Vec3& other1, const Vec3& other2)
	{
		float deltaX = (other1.x - other2.x);
		float deltaY = (other1.y - other2.y);
		float deltaZ = (other1.z - other2.z);
		return sqrt(deltaX * deltaX + deltaY * deltaY + deltaZ * deltaZ);
	}

	float Vec3::Dot(const Vec3& other) const
	{
		return x * other.x + y * other.y + z * other.z;
	}

	float Vec3::Dot(const Vec3& other1, const Vec3& other2)
	{
		return other1.x * other2.x + other1.y * other2.y + other1.z * other2.z;
	}

	Vec3 Vec3::Cross(const Vec3& other) const
	{
		float cx = (y * other.z) - (z * other.y);
		float cy = (z * other.x) - (x * other.z);
		float cz = (x * other.y) - (y * other.x);
		return Vec3(cx, cy, cz);
	}

	Vec3 Vec3::Cross(const Vec3& other1, const Vec3& other2)
	{
		float cx = (other1.y * other2.z) - (other1.z * other2.y);
		float cy = (other1.z * other2.x) - (other1.x * other2.z);
		float cz = (other1.x * other2.y) - (other1.y * other2.x);

		return Vec3(cx, cy, cz);
	}

	const Vec3 Vec3::Zero	( 0.0f,  0.0f,  0.0f);
	const Vec3 Vec3::One	( 1.0f,  1.0f,  1.0f);

	const Vec3 Vec3::Front	( 0.0f,  0.0f,  1.0f);
	const Vec3 Vec3::Back	( 0.0f,  0.0f, -1.0f);
	const Vec3 Vec3::Up		( 0.0f,  1.0f,  0.0f);
	const Vec3 Vec3::Down	( 0.0f, -1.0f,  0.0f);
	const Vec3 Vec3::Left	(-1.0f,  0.0f,  0.0f);
	const Vec3 Vec3::Right	( 1.0f,  1.0f,  0.0f);

	const Vec3 Vec3::AxisX	( 1.0f,  0.0f,  0.0f);
	const Vec3 Vec3::AxisY	( 0.0f,  1.0f,  0.0f);
	const Vec3 Vec3::AxisZ	( 0.0f,  0.0f,  1.0f);
}