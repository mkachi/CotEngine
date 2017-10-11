#pragma once

#include "base/CotRule.h"

namespace Cot 
{
	class COT_API Vec2 final
	{
	public:
		union
		{
			struct
			{
				float x, y;
			};
			float ToArray[2];
		};

		Vec2();
		Vec2(const float value);
		Vec2(const float xx, const float yy);
		Vec2(const float* array);
		Vec2(const Vec2& other);
		Vec2(const Vec2&& other);
		~Vec2();

		const Vec2 operator+(const Vec2& other) const;
		const Vec2 operator-(const Vec2& other) const;
		const Vec2 operator*(const Vec2& other) const;
		const Vec2 operator/(const Vec2& other) const;

		const Vec2 operator+(const float value) const;
		const Vec2 operator-(const float value) const;
		const Vec2 operator*(const float value) const;
		const Vec2 operator/(const float value) const;

		Vec2& operator+=(const Vec2& other);
		Vec2& operator-=(const Vec2& other);
		Vec2& operator*=(const Vec2& other);
		Vec2& operator/=(const Vec2& other);
		Vec2& operator=(const Vec2& other);

		Vec2& operator+=(const float value);
		Vec2& operator-=(const float value);
		Vec2& operator*=(const float value);
		Vec2& operator/=(const float value);
		Vec2& operator=(const float value);

		const Vec2 operator-() const;

		bool operator<(const Vec2& other) const;
		bool operator<=(const Vec2& other) const;
		bool operator>(const Vec2& other) const;
		bool operator>=(const Vec2& other) const;

		bool operator==(const Vec2& other) const;
		bool operator!=(const Vec2& other) const;

		bool IsZero() const;
		bool IsOne() const;

		Vec2 Normalize();
		static Vec2 Normalize(const Vec2& other);

		float Length() const;
		float Distance(const Vec2& other) const;
		static float Distance(const Vec2& other1, const Vec2& other2);

		float Dot(const Vec2& other) const;
		static float Dot(const Vec2& other1, const Vec2& other2);

		static const Vec2 Zero;
		static const Vec2 One;

		static const Vec2 Up;
		static const Vec2 Down;
		static const Vec2 Left;
		static const Vec2 Right;

		static const Vec2 AxisX;
		static const Vec2 AxisY;

	};
}