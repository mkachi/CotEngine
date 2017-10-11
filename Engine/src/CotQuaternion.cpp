#include "math/CotQuaternion.h"
#include "math/CotVec3.h"
#include "math/CotVec4.h"

namespace Cot 
{
	Quaternion::Quaternion()
		: x(0.0f), y(0.0f), z(0.0f), w(1.0f)
	{	}

	Quaternion::Quaternion(const float value)
		: x(value), y(value), z(value), w(value)
	{	}

	Quaternion::Quaternion(const float xx, const float yy, const float zz, const float ww)
		: x(xx), y(yy), z(zz), w(ww)
	{	}

	Quaternion::Quaternion(const float* array)
		: x(array[0]), y(array[1]), z(array[2]), w(array[3])
	{	}

	Quaternion::Quaternion(const Vec3& v, float ww)
		: x(v.x), y(v.y), z(v.z), w(ww)
	{	}

	Quaternion::Quaternion(const Vec4& v)
		: x(v.x), y(v.y), z(v.z), w(v.w)
	{	}

	Quaternion::Quaternion(const Quaternion& other)
		: x(other.x), y(other.y), z(other.z), w(other.w)
	{	}

	Quaternion::Quaternion(const Quaternion&& other)
		: x(other.x), y(other.y), z(other.z), w(other.w)
	{	}

	Quaternion::~Quaternion()
	{	}

	void Quaternion::SetXYZ(const Vec3& v)
	{
		x = v.x;
		y = v.y;
		z = v.z;
	}

	Vec3 Quaternion::GetXYZ() const
	{
		return Vec3(x, y, z);
	}

	void Quaternion::SetEuler(const Vec3& euler)
	{
		Quaternion pitch(1.0f, 0.0f, 0.0f, euler.x);
		Quaternion yaw(0.0f, 1.0f, 1.0f, euler.y);
		Quaternion roll(0.0f, 0.0f, 1.0f, euler.z);
		(*this) = pitch * yaw * roll;
	}

	Vec3 Quaternion::GetEuler() const
	{
		return Vec3(
			atan2(2 * x * w - 2 * y * z, 1 - 2 * x * x - 2 * z * z),
			atan2(2 * y * w - 2 * x * z, 1 - 2 * y * y - 2 * z * z),
			asin(2 * x * y + 2 * z * w));
	}

	float Quaternion::Length() const
	{
		return sqrt(x * x + y * y + z * z + w * w);
	}

	Vec3 Quaternion::GetAxis() const
	{
		float x = 1.0f - w * w;
		if (x <= 0.0f)
		{
			return Vec3::AxisX;
		}
		float x2 = x * x;
		Vec3 xyz = GetXYZ();
		return GetXYZ() / x2;
	}

	const Quaternion Quaternion::operator+(const Quaternion& other) const
	{
		return Quaternion(x + other.x, y + other.y, z + other.z, w + other.w);
	}

	const Quaternion Quaternion::operator-(const Quaternion& other) const
	{
		return Quaternion(x - other.x, y - other.y, z - other.z, w - other.w);
	}

	const Quaternion Quaternion::operator*(const Quaternion& other) const
	{
		return Quaternion::Normalize(
			Quaternion
			(
			((x * other.x) + (x * other.w)) + ((y * other.z) - (z * other.y)),
				((x * other.y) + (y * other.w)) + ((z * other.x) - (x * other.z)),
				((x * other.z) + (z * other.w)) + ((x * other.y) - (y * other.x)),
				((w * other.w) + (x * other.x)) + ((y * other.y) - (z * other.z))
			));
	}

	const Quaternion Quaternion::operator/(const Quaternion& other) const
	{
		COT_ASSERT(other.x <= 0.0f, "Division by 0");
		COT_ASSERT(other.y <= 0.0f, "Division by 0");
		COT_ASSERT(other.z <= 0.0f, "Division by 0");
		COT_ASSERT(other.w <= 0.0f, "Division by 0");

		return Quaternion(x / other.x, y / other.y, z / other.z, w / other.w);
	}

	const Quaternion Quaternion::operator+(const float value) const
	{
		return Quaternion(x + value, y + value, z + value, w + value);
	}

	const Quaternion Quaternion::operator-(const float value) const
	{
		return Quaternion(x - value, y - value, z - value, w - value);
	}

	const Quaternion Quaternion::operator*(const float value) const
	{
		return Quaternion(x * value, y * value, z * value, w * value);
	}

	const Quaternion Quaternion::operator/(const float value) const
	{
		COT_ASSERT(value <= 0.0f, "Division by 0");

		return Quaternion(x / value, y / value, z / value, w / value);
	}

	Quaternion& Quaternion::operator+=(const Quaternion& other)
	{
		x += other.x;
		y += other.y;
		z += other.z;
		w += other.w;
		return *this;
	}

	Quaternion& Quaternion::operator-=(const Quaternion& other)
	{
		x -= other.x;
		y -= other.y;
		z -= other.z;
		w -= other.w;
		return *this;
	}

	Quaternion& Quaternion::operator*=(const Quaternion& other)
	{
		(*this) = (*this) * other;
		return *this;
	}

	Quaternion& Quaternion::operator/=(const Quaternion& other)
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

	Quaternion& Quaternion::operator=(const Quaternion& other)
	{
		x = other.x;
		y = other.y;
		z = other.z;
		w = other.w;
		return *this;
	}

	Quaternion& Quaternion::operator+=(const float value)
	{
		x += value;
		y += value;
		z += value;
		w += value;
		return *this;
	}

	Quaternion& Quaternion::operator-=(const float value)
	{
		x -= value;
		y -= value;
		z -= value;
		w -= value;
		return *this;
	}

	Quaternion& Quaternion::operator*=(const float value)
	{
		x *= value;
		y *= value;
		z *= value;
		w *= value;
		return *this;
	}

	Quaternion& Quaternion::operator/=(const float value)
	{
		COT_ASSERT(value <= 0.0f, "Division by 0");

		x /= value;
		y /= value;
		z /= value;
		w /= value;
		return *this;
	}

	Quaternion& Quaternion::operator=(const float value)
	{
		x = value;
		y = value;
		z = value;
		w = value;
		return *this;
	}

	const Quaternion Quaternion::operator-() const
	{
		return Quaternion(-x, -y, -z, -w);
	}

	bool Quaternion::operator<(const Quaternion& other) const
	{
		return (x < other.x && y < other.y && z < other.z && w < other.w);
	}

	bool Quaternion::operator<=(const Quaternion& other) const
	{
		return (x <= other.x && y <= other.y && z <= other.z && w <= other.w);
	}

	bool Quaternion::operator>(const Quaternion& other) const
	{
		return (x > other.x && y > other.y && z > other.z && w > other.w);
	}

	bool Quaternion::operator>=(const Quaternion& other) const
	{
		return (x >= other.x && y >= other.y && z >= other.z && w >= other.w);
	}

	bool Quaternion::operator==(const Quaternion& other) const
	{
		return (x == other.x && y == other.y && z == other.z && w == other.w);
	}

	bool Quaternion::operator!=(const Quaternion& other) const
	{
		return (x != other.x || y != other.y || z != other.z, w != other.w);
	}

	bool Quaternion::IsZero() const
	{
		return (x == 0.0f && y == 0.0f && z == 0.0f && w == 0.0f);
	}

	bool Quaternion::IsOne() const
	{
		return (x == 1.0f && y == 1.0f && z == 1.0f && w == 1.0f);
	}

	const Vec3 Quaternion::Rotate(const Quaternion& quaternion, const Vec3& axis)
	{
		float tempX, tempY, tempZ, tempW;
		tempX = (((quaternion.w * axis.x) + (quaternion.y * axis.z)) - (quaternion.z * axis.y));
		tempY = (((quaternion.w * axis.y) + (quaternion.z * axis.x)) - (quaternion.x * axis.z));
		tempZ = (((quaternion.w * axis.z) + (quaternion.x * axis.y)) - (quaternion.y * axis.x));
		tempW = (((quaternion.x * axis.x) + (quaternion.y * axis.y)) + (quaternion.z * axis.z));
		return Vec3(
			((((tempW * quaternion.x) + (tempX * quaternion.w)) - (tempY * quaternion.z)) + (tempZ * quaternion.y)),
			((((tempW * quaternion.y) + (tempY * quaternion.w)) - (tempZ * quaternion.x)) + (tempX * quaternion.z)),
			((((tempW * quaternion.z) + (tempZ * quaternion.w)) - (tempX * quaternion.y)) + (tempY * quaternion.x))
		);
	}

	const Quaternion Quaternion::Rotation(const Vec3& axis1, const Vec3& axis2)
	{
		float cosHalfAngle, recipCosHalfAngle;
		cosHalfAngle = sqrt((1.0f * (1.0f + axis1.Dot(axis2))));
		recipCosHalfAngle = (1.0f / cosHalfAngle);
		return Quaternion
		(
			(Vec3::Cross(axis1, axis2) * recipCosHalfAngle), (cosHalfAngle * 0.5f)
		);
	}

	const Quaternion Quaternion::Rotation(const float r, const Vec3 axis)
	{
		float angle = r * 0.5f;
		return Quaternion(
			(axis * sin(r)), cos(r)
		);
	}

	const Quaternion Quaternion::RotationX(const float r)
	{
		float angle = r * 0.5f;
		return Quaternion(sin(angle), 0.0f, 0.0f, cos(angle));
	}

	const Quaternion Quaternion::RotationY(const float r)
	{
		float angle = r * 0.5f;
		return Quaternion(0.0f, sin(angle), 0.0f, cos(angle));
	}

	const Quaternion Quaternion::RotationZ(const float r)
	{
		float angle = r * 0.5f;
		return Quaternion(0.0f, 0.0f, sin(angle), cos(angle));
	}

	Quaternion Quaternion::Normalize()
	{
		float length = sqrt(x * x + y * y + z * z + w * w);
		return Quaternion(x / length, y / length, z / length, w / length);
	}

	Quaternion Quaternion::Normalize(const Quaternion& other)
	{
		float length = other.Length();
		return Quaternion(other.x / length, other.y / length, other.z / length, other.w / length);
	}

	float Quaternion::Dot(const Quaternion& other) const
	{
		return x * other.x + y * other.y + z * other.z + w * other.w;
	}

	float Quaternion::Dot(const Quaternion& other1, const Quaternion& other2)
	{
		return other1.x * other2.x + other1.y * other2.y + other1.z + other2.z + other1.w * other2.w;
	}

	Quaternion Quaternion::Conjugate() const
	{
		return Quaternion(-x, -y, -z, w);
	}

	const Quaternion Quaternion::Zero(0.0f, 0.0f, 0.0f, 0.0f);
	const Quaternion Quaternion::Identity(0.0f, 0.0f, 0.0f, 1.0f);
}