#pragma once

#include "base/CotRule.h"

namespace Cot
{
	class Vec2;
	class Vec3;
	class COT_API Vec4 final
	{
	public:
		union
		{
			struct
			{
				float x, y, z, w;
			};
			float ToArray[4];
		};

		Vec4();
		Vec4(const float value);
		Vec4(const float xx, const float yy);
		Vec4(const Vec2& other);
		Vec4(const float xx, const float yy, const float zz);
		Vec4(const Vec3& other);
		Vec4(const float xx, const float yy, const float zz, const float ww);
		Vec4(const float* array);
		Vec4(const Vec4& other);
		Vec4(const Vec4&& other);
		~Vec4();

		const Vec4 operator+(const Vec4& other) const;
		const Vec4 operator-(const Vec4& other) const;
		const Vec4 operator*(const Vec4& other) const;
		const Vec4 operator/(const Vec4& other) const;

		const Vec4 operator+(const float value) const;
		const Vec4 operator-(const float value) const;
		const Vec4 operator*(const float value) const;
		const Vec4 operator/(const float value) const;

		Vec4& operator+=(const Vec4& other);
		Vec4& operator-=(const Vec4& other);
		Vec4& operator*=(const Vec4& other);
		Vec4& operator/=(const Vec4& other);
		Vec4& operator=(const Vec4& other);

		Vec4& operator+=(const float value);
		Vec4& operator-=(const float value);
		Vec4& operator*=(const float value);
		Vec4& operator/=(const float value);
		Vec4& operator=(const float value);

		const Vec4 operator-() const;

		bool operator<(const Vec4& other) const;
		bool operator<=(const Vec4& other) const;
		bool operator>(const Vec4& other) const;
		bool operator>=(const Vec4& other) const;

		bool operator==(const Vec4& other) const;
		bool operator!=(const Vec4& other) const;

		bool IsZero() const;
		bool IsOne() const;

		Vec4 Normalize();
		static Vec4 Normalize(const Vec4& other);

		float Length() const;
		float Distance(const Vec4& other) const;
		static float Distance(const Vec4& other1, const Vec4& other2);

		float Dot(const Vec4& other) const;
		static float Dot(const Vec4& other1, const Vec4& other2);

		static const Vec4 Zero;
		static const Vec4 One;
	};
}