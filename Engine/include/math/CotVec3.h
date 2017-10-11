#pragma once

#include "base/CotRule.h"

namespace Cot 
{
	class Vec2;
	class Mat4;
	class COT_API Vec3 final
	{
	public:
		union
		{
			struct
			{
				float x, y, z;
			};
			float ToArray[3];
		};

		Vec3();
		Vec3(const float value);
		Vec3(const float xx, const float yy);
		Vec3(const Vec2& other);
		Vec3(const float xx, const float yy, const float zz);
		Vec3(const float* array);
		Vec3(const Vec3& other);
		Vec3(const Vec3&& other);
		~Vec3();

		const Vec3 operator+(const Vec3& other) const;
		const Vec3 operator-(const Vec3& other) const;
		const Vec3 operator*(const Vec3& other) const;
		const Vec3 operator/(const Vec3& other) const;

		const Vec3 operator+(const float value) const;
		const Vec3 operator-(const float value) const;
		const Vec3 operator*(const float value) const;
		const Vec3 operator/(const float value) const;

		Vec3& operator+=(const Vec3& other);
		Vec3& operator-=(const Vec3& other);
		Vec3& operator*=(const Vec3& other);
		Vec3& operator/=(const Vec3& other);
		Vec3& operator=(const Vec3& other);

		Vec3& operator+=(const float value);
		Vec3& operator-=(const float value);
		Vec3& operator*=(const float value);
		Vec3& operator/=(const float value);
		Vec3& operator=(const float value);

		const Vec3 operator*(const Mat4& mat) const;
		Vec3& operator*=(const Mat4& mat);

		const Vec3 operator-() const;

		bool operator<(const Vec3& other) const;
		bool operator<=(const Vec3& other) const;
		bool operator>(const Vec3& other) const;
		bool operator>=(const Vec3& other) const;

		bool operator==(const Vec3& other) const;
		bool operator!=(const Vec3& other) const;

		bool IsZero() const;
		bool IsOne() const;

		Vec3 Normalize();
		static Vec3 Normalize(const Vec3& other);

		float Length() const;
		float Distance(const Vec3& other) const;
		static float Distance(const Vec3& other1, const Vec3& other2);

		float Dot(const Vec3& other) const;
		static float Dot(const Vec3& other1, const Vec3& other2);

		Vec3 Cross(const Vec3& other) const;
		static Vec3 Cross(const Vec3& other1, const Vec3& other2);

		static const Vec3 Zero;
		static const Vec3 One;

		static const Vec3 Front;
		static const Vec3 Back;
		static const Vec3 Up;
		static const Vec3 Down;
		static const Vec3 Left;
		static const Vec3 Right;

		static const Vec3 AxisX;
		static const Vec3 AxisY;
		static const Vec3 AxisZ;
	};
}