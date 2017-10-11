#pragma once

#include "base/CotRule.h"

namespace Cot 
{
	class Vec3;
	class COT_API Mat4 final
	{
	public:
		union
		{
			struct
			{
				float _11, _12, _13, _14;
				float _21, _22, _23, _24;
				float _31, _32, _33, _34;
				float _41, _42, _43, _44;
			};

			float ToArray4x4[4][4];
			float ToArray[16];
		};

		Mat4();
		Mat4
		(
			const float m11, const float m12, const float m13, const float m14,
			const float m21, const float m22, const float m23, const float m24,
			const float m31, const float m32, const float m33, const float m34,
			const float m41, const float m42, const float m43, const float m44
		);
		Mat4(const float* mat);
		Mat4(const float** mat);
		Mat4(const Mat4& mat);
		~Mat4();

		const Mat4 operator+(const Mat4& mat) const;
		const Mat4 operator-(const Mat4& mat) const;
		const Mat4 operator*(const Mat4& mat) const;

		const Mat4 operator+(float value) const;
		const Mat4 operator-(float value) const;
		const Mat4 operator*(float value) const;

		Mat4& operator+=(const Mat4& mat);
		Mat4& operator-=(const Mat4& mat);
		Mat4& operator*=(const Mat4& mat);

		Mat4& operator+=(float value);
		Mat4& operator-=(float value);
		Mat4& operator*=(float value);

		const Mat4 operator-() const;

		Mat4 Inverse();
		class Vec4 GetColumn(int index);

		static Mat4 Multiply(const Mat4& mat1, const Mat4& mat2);

		static Mat4 Orthographic(float left, float right, float bottom, float top, float near, float far);
		static Mat4 Perspective(float fov, float aspectRatio, float near, float far);
		static Mat4 LookAt(const class Vec3& eye, const Vec3& center, const Vec3& up);

		static Mat4 Translate(const Vec3& position);
		static Mat4 Rotate(float angle, const Vec3& axis);
		static Mat4 Rotate(const class Quaternion& quaternion);
		static Mat4 Scale(const Vec3& scale);
		static Mat4 Transpose(const Mat4& mat);

		static const Mat4 Zero;
		static const Mat4 Identity;

	};
}