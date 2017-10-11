#pragma once

#include "base/CotRule.h"

namespace Cot 
{
	class Vec3;
	class Vec4;
	class COT_API Quaternion final
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

		Quaternion();
		Quaternion(const float value);
		Quaternion(const float xx, const float yy, const float zz, const float ww);
		Quaternion(const float* array);
		Quaternion(const Vec3& v, float ww);
		Quaternion(const Vec4& v);
		Quaternion(const Quaternion& other);
		Quaternion(const Quaternion&& other);
		~Quaternion();

		void SetXYZ(const Vec3& v);
		Vec3 GetXYZ() const;

		void SetEuler(const Vec3& euler);
		Vec3 GetEuler() const;

		float Length() const;
		Vec3 GetAxis() const;

		const Quaternion operator+(const Quaternion& other) const;
		const Quaternion operator-(const Quaternion& other) const;
		const Quaternion operator*(const Quaternion& other) const;
		const Quaternion operator/(const Quaternion& other) const;

		const Quaternion operator+(const float value) const;
		const Quaternion operator-(const float value) const;
		const Quaternion operator*(const float value) const;
		const Quaternion operator/(const float value) const;

		Quaternion& operator+=(const Quaternion& other);
		Quaternion& operator-=(const Quaternion& other);
		Quaternion& operator*=(const Quaternion& other);
		Quaternion& operator/=(const Quaternion& other);
		Quaternion& operator=(const Quaternion& other);

		Quaternion& operator+=(const float value);
		Quaternion& operator-=(const float value);
		Quaternion& operator*=(const float value);
		Quaternion& operator/=(const float value);
		Quaternion& operator=(const float value);

		const Quaternion operator-() const;

		bool operator<(const Quaternion& other) const;
		bool operator<=(const Quaternion& other) const;
		bool operator>(const Quaternion& other) const;
		bool operator>=(const Quaternion& other) const;

		bool operator==(const Quaternion& other) const;
		bool operator!=(const Quaternion& other) const;

		bool IsZero() const;
		bool IsOne() const;

		static const Vec3 Rotate(const Quaternion& quaternion, const Vec3& axis);

		static const Quaternion Rotation(const Vec3& axis1, const Vec3& axis2);
		static const Quaternion Rotation(const float r, const Vec3 axis);

		static const Quaternion RotationX(const float r);
		static const Quaternion RotationY(const float r);
		static const Quaternion RotationZ(const float r);

		Quaternion Normalize();
		static Quaternion Normalize(const Quaternion& other);

		float Dot(const Quaternion& other) const;
		static float Dot(const Quaternion& other1, const Quaternion& other2);

		Quaternion Conjugate() const;

		static const Quaternion Zero;
		static const Quaternion Identity;
	};
}