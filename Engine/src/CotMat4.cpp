#include "math/CotMat4.h"
#include "math/CotGeometry.h"
#include "math/CotVec3.h"
#include "math/CotVec4.h"
#include "math/CotQuaternion.h"
#include "math/CotMathFunc.h"
#include <cmath>

namespace Cot 
{
	Mat4::Mat4()
		: _11(1.0f), _12(0.0f), _13(0.0f), _14(0.0f)
		, _21(0.0f), _22(1.0f), _23(0.0f), _24(0.0f)
		, _31(0.0f), _32(0.0f), _33(1.0f), _34(0.0f)
		, _41(0.0f), _42(0.0f), _43(0.0f), _44(1.0f)
	{ }

	Mat4::Mat4
	(
		const float m11, const float m12, const float m13, const float m14,
		const float m21, const float m22, const float m23, const float m24,
		const float m31, const float m32, const float m33, const float m34,
		const float m41, const float m42, const float m43, const float m44
	)
		: _11(m11), _12(m12), _13(m13), _14(m14)
		, _21(m21), _22(m22), _23(m23), _24(m24)
		, _31(m31), _32(m32), _33(m33), _34(m34)
		, _41(m41), _42(m42), _43(m43), _44(m44)
	{ }

	Mat4::Mat4(const float* mat)
		: _11(mat[0]), _12(mat[1]), _13(mat[2]), _14(mat[3])
		, _21(mat[4]), _22(mat[5]), _23(mat[6]), _24(mat[7])
		, _31(mat[8]), _32(mat[9]), _33(mat[10]), _34(mat[11])
		, _41(mat[12]), _42(mat[13]), _43(mat[14]), _44(mat[15])
	{ }

	Mat4::Mat4(const float** mat)
		: _11(mat[0][0]), _12(mat[0][1]), _13(mat[0][2]), _14(mat[0][3])
		, _21(mat[1][0]), _22(mat[1][1]), _23(mat[1][2]), _24(mat[1][3])
		, _31(mat[2][0]), _32(mat[2][1]), _33(mat[2][2]), _34(mat[2][3])
		, _41(mat[3][0]), _42(mat[3][1]), _43(mat[3][2]), _44(mat[3][3])
	{ }

	Mat4::Mat4(const Mat4& mat)
		: _11(mat._11), _12(mat._12), _13(mat._13), _14(mat._14)
		, _21(mat._21), _22(mat._22), _23(mat._23), _24(mat._24)
		, _31(mat._31), _32(mat._32), _33(mat._33), _34(mat._34)
		, _41(mat._41), _42(mat._42), _43(mat._43), _44(mat._44)
	{ }

	Mat4::~Mat4()
	{ }

	const Mat4 Mat4::operator+(const Mat4& mat) const
	{
		return Mat4
		(
			_11 + mat._11, _12 + mat._12, _13 + mat._13, _14 + mat._14,
			_21 + mat._21, _22 + mat._22, _23 + mat._23, _24 + mat._24,
			_31 + mat._31, _32 + mat._32, _33 + mat._33, _34 + mat._34,
			_41 + mat._41, _42 + mat._42, _43 + mat._43, _44 + mat._44
		);
	}

	const Mat4 Mat4::operator-(const Mat4& mat) const
	{
		return Mat4
		(
			_11 - mat._11, _12 - mat._12, _13 - mat._13, _14 - mat._14,
			_21 - mat._21, _22 - mat._22, _23 - mat._23, _24 - mat._24,
			_31 - mat._31, _32 - mat._32, _33 - mat._33, _34 - mat._34,
			_41 - mat._41, _42 - mat._42, _43 - mat._43, _44 - mat._44
		);
	}

	const Mat4 Mat4::operator*(const Mat4& mat) const
	{
		return Multiply(mat, *this);
	}

	const Mat4 Mat4::operator+(float value) const
	{
		return Mat4
		(
			_11 + value, _12 + value, _13 + value, _14 + value,
			_21 + value, _22 + value, _23 + value, _24 + value,
			_31 + value, _32 + value, _33 + value, _34 + value,
			_41 + value, _42 + value, _43 + value, _44 + value
		);
	}

	const Mat4 Mat4::operator-(float value) const
	{
		return Mat4
		(
			_11 - value, _12 - value, _13 - value, _14 - value,
			_21 - value, _22 - value, _23 - value, _24 - value,
			_31 - value, _32 - value, _33 - value, _34 - value,
			_41 - value, _42 - value, _43 - value, _44 - value
		);
	}

	const Mat4 Mat4::operator*(float value) const
	{
		return Mat4
		(
			_11 * value, _12 * value, _13 * value, _14 * value,
			_21 * value, _22 * value, _23 * value, _24 * value,
			_31 * value, _32 * value, _33 * value, _34 * value,
			_41 * value, _42 * value, _43 * value, _44 * value
		);
	}

	Mat4& Mat4::operator+=(const Mat4& mat)
	{
		_11 += mat._11; _12 += mat._12; _13 += mat._13; _14 += mat._14;
		_21 += mat._21; _22 += mat._22; _23 += mat._23; _24 += mat._24;
		_31 += mat._31; _32 += mat._32; _33 += mat._33; _34 += mat._34;
		_41 += mat._41; _42 += mat._42; _43 += mat._43; _44 += mat._44;
		return *this;
	}

	Mat4& Mat4::operator-=(const Mat4& mat)
	{
		_11 -= mat._11; _12 -= mat._12; _13 -= mat._13; _14 -= mat._14;
		_21 -= mat._21; _22 -= mat._22; _23 -= mat._23; _24 -= mat._24;
		_31 -= mat._31; _32 -= mat._32; _33 -= mat._33; _34 -= mat._34;
		_41 -= mat._41; _42 -= mat._42; _43 -= mat._43; _44 -= mat._44;
		return *this;
	}

	Mat4& Mat4::operator*=(const Mat4& mat)
	{
		(*this) = Multiply(mat, *this);
		return *this;
	}

	Mat4& Mat4::operator+=(float value)
	{
		_11 += value; _12 += value; _13 += value; _14 += value;
		_21 += value; _22 += value; _23 += value; _24 += value;
		_31 += value; _32 += value; _33 += value; _34 += value;
		_41 += value; _42 += value; _43 += value; _44 += value;
		return *this;
	}

	Mat4& Mat4::operator-=(float value)
	{
		_11 -= value; _12 -= value; _13 -= value; _14 -= value;
		_21 -= value; _22 -= value; _23 -= value; _24 -= value;
		_31 -= value; _32 -= value; _33 -= value; _34 -= value;
		_41 -= value; _42 -= value; _43 -= value; _44 -= value;
		return *this;
	}

	Mat4& Mat4::operator*=(float value)
	{
		_11 *= value; _12 *= value; _13 *= value; _14 *= value;
		_21 *= value; _22 *= value; _23 *= value; _24 *= value;
		_31 *= value; _32 *= value; _33 *= value; _34 *= value;
		_41 *= value; _42 *= value; _43 *= value; _44 *= value;
		return *this;
	}

	const Mat4 Mat4::operator-() const
	{
		return Mat4
		(
			-_11, -_12, -_13, -_14,
			-_21, -_22, -_23, -_24,
			-_31, -_32, -_33, -_34,
			-_41, -_42, -_43, -_44
		);
	}

	Mat4 Mat4::Inverse()
	{
		float a0 = ToArray[0] * ToArray[5] - ToArray[1] * ToArray[4];
		float a1 = ToArray[0] * ToArray[6] - ToArray[2] * ToArray[4];
		float a2 = ToArray[0] * ToArray[7] - ToArray[3] * ToArray[4];
		float a3 = ToArray[1] * ToArray[6] - ToArray[2] * ToArray[5];
		float a4 = ToArray[1] * ToArray[7] - ToArray[3] * ToArray[5];
		float a5 = ToArray[2] * ToArray[7] - ToArray[3] * ToArray[6];
		float b0 = ToArray[8] * ToArray[13] - ToArray[9] * ToArray[12];
		float b1 = ToArray[8] * ToArray[14] - ToArray[10] * ToArray[12];
		float b2 = ToArray[8] * ToArray[15] - ToArray[11] * ToArray[12];
		float b3 = ToArray[9] * ToArray[14] - ToArray[10] * ToArray[13];
		float b4 = ToArray[9] * ToArray[15] - ToArray[11] * ToArray[13];
		float b5 = ToArray[10] * ToArray[15] - ToArray[11] * ToArray[14];

		float det = a0 * b5 - a1 * b4 + a2 * b3 + a3 * b2 - a4 * b1 + a5 * b0;

		COT_ASSERT(fabs(det) <= 0.0f, "Division by 0");

		Mat4 result;
		result.ToArray[0] = ToArray[5] * b5 - ToArray[6] * b4 + ToArray[7] * b3;
		result.ToArray[1] = -ToArray[1] * b5 + ToArray[2] * b4 - ToArray[3] * b3;
		result.ToArray[2] = ToArray[13] * a5 - ToArray[14] * a4 + ToArray[15] * a3;
		result.ToArray[3] = -ToArray[9] * a5 + ToArray[10] * a4 - ToArray[11] * a3;

		result.ToArray[4] = -ToArray[4] * b5 + ToArray[6] * b2 - ToArray[7] * b1;
		result.ToArray[5] = ToArray[0] * b5 - ToArray[2] * b2 + ToArray[3] * b1;
		result.ToArray[6] = -ToArray[12] * a5 + ToArray[14] * a2 - ToArray[15] * a1;
		result.ToArray[7] = ToArray[8] * a5 - ToArray[10] * a2 + ToArray[11] * a1;

		result.ToArray[8] = ToArray[4] * b4 - ToArray[5] * b2 + ToArray[7] * b0;
		result.ToArray[9] = -ToArray[0] * b4 + ToArray[1] * b2 - ToArray[3] * b0;
		result.ToArray[10] = ToArray[12] * a4 - ToArray[13] * a2 + ToArray[15] * a0;
		result.ToArray[11] = -ToArray[8] * a4 + ToArray[9] * a2 - ToArray[11] * a0;

		result.ToArray[12] = -ToArray[4] * b3 + ToArray[5] * b1 - ToArray[6] * b0;
		result.ToArray[13] = ToArray[0] * b3 - ToArray[1] * b1 + ToArray[2] * b0;
		result.ToArray[14] = -ToArray[12] * a3 + ToArray[13] * a1 - ToArray[14] * a0;
		result.ToArray[15] = ToArray[8] * a3 - ToArray[9] * a1 + ToArray[10] * a0;
		det = 1.0f / det;
		result *= det;

		return result;
	}

	Vec4 Mat4::GetColumn(int index)
	{
		return Vec4(ToArray[index + 0 * 4], ToArray[index + 1 * 4], ToArray[index + 2 * 4], ToArray[index + 3 * 4]);
	}

	Mat4 Mat4::Multiply(const Mat4& mat1, const Mat4& mat2)
	{
		const float m11 = (mat1._11 * mat2._11) + (mat1._12 * mat2._21) + (mat1._13 * mat2._31) + (mat1._14 * mat2._41);
		const float m12 = (mat1._11 * mat2._12) + (mat1._12 * mat2._22) + (mat1._13 * mat2._32) + (mat1._14 * mat2._42);
		const float m13 = (mat1._11 * mat2._13) + (mat1._12 * mat2._23) + (mat1._13 * mat2._33) + (mat1._14 * mat2._43);
		const float m14 = (mat1._11 * mat2._14) + (mat1._12 * mat2._24) + (mat1._13 * mat2._34) + (mat1._14 * mat2._44);

		const float m21 = (mat1._21 * mat2._11) + (mat1._22 * mat2._21) + (mat1._23 * mat2._31) + (mat1._24 * mat2._41);
		const float m22 = (mat1._21 * mat2._12) + (mat1._22 * mat2._22) + (mat1._23 * mat2._32) + (mat1._24 * mat2._42);
		const float m23 = (mat1._21 * mat2._13) + (mat1._22 * mat2._23) + (mat1._23 * mat2._33) + (mat1._24 * mat2._43);
		const float m24 = (mat1._21 * mat2._14) + (mat1._22 * mat2._24) + (mat1._23 * mat2._34) + (mat1._24 * mat2._44);

		const float m31 = (mat1._31 * mat2._11) + (mat1._32 * mat2._21) + (mat1._33 * mat2._31) + (mat1._34 * mat2._41);
		const float m32 = (mat1._31 * mat2._12) + (mat1._32 * mat2._22) + (mat1._33 * mat2._32) + (mat1._34 * mat2._42);
		const float m33 = (mat1._31 * mat2._13) + (mat1._32 * mat2._23) + (mat1._33 * mat2._33) + (mat1._34 * mat2._43);
		const float m34 = (mat1._31 * mat2._14) + (mat1._32 * mat2._24) + (mat1._33 * mat2._34) + (mat1._34 * mat2._44);

		const float m41 = (mat1._41 * mat2._11) + (mat1._42 * mat2._21) + (mat1._43 * mat2._31) + (mat1._44 * mat2._41);
		const float m42 = (mat1._41 * mat2._12) + (mat1._42 * mat2._22) + (mat1._43 * mat2._32) + (mat1._44 * mat2._42);
		const float m43 = (mat1._41 * mat2._13) + (mat1._42 * mat2._23) + (mat1._43 * mat2._33) + (mat1._44 * mat2._43);
		const float m44 = (mat1._41 * mat2._14) + (mat1._42 * mat2._24) + (mat1._43 * mat2._34) + (mat1._44 * mat2._44);

		return Mat4
		(
			m11, m12, m13, m14,
			m21, m22, m23, m24,
			m31, m32, m33, m34,
			m41, m42, m43, m44
		);
	}

	Mat4 Mat4::Orthographic(float left, float right, float bottom, float top, float near, float far)
	{
		Mat4 result = Mat4::Identity;
		result._11 = 2.0f / (right - left);
		result._22 = 2.0f / (top - bottom);
		result._33 = -2.0f / (far - near);
		result._41 = -(right + left) / (right - left);
		result._42 = -(top + bottom) / (top - bottom);
		result._43 = -(far - near) / (far - near);

		return result;
	}

	Mat4 Mat4::Perspective(float fov, float aspectRatio, float near, float far)
	{
		Mat4 result = Mat4::Identity;
		float q = 1.0f / tan(ToRad(0.5f * fov));
		float a = q / aspectRatio;

		float b = (near + far) / (near - far);
		float c = (2.0f * near * far) / (near - far);

		result._11 = a;
		result._22 = q;
		result._33 = b;
		result._34 = c;
		result._43 = -1.0f;
		result._44 = 0;

		return result;
	}

	Mat4 Mat4::LookAt(const Vec3& eye, const Vec3& center, const Vec3& up)
	{
		Mat4 result = Mat4::Identity;
		Vec3 ce = center - eye;
		Vec3 f = ce.Normalize();
		Vec3 s = (Vec3::Normalize(Vec3::Cross(f, up)));
		Vec3 u = Vec3::Cross(s, f);

		result._11 = s.x;
		result._21 = s.y;
		result._31 = s.z;

		result._12 = u.x;
		result._22 = u.y;
		result._32 = u.z;

		result._13 = -f.x;
		result._23 = -f.y;
		result._33 = -f.z;

		result._41 = -Vec3::Dot(s, eye);
		result._42 = -Vec3::Dot(u, eye);
		result._43 = Vec3::Dot(f, eye);

		return result;
	}

	Mat4 Mat4::Translate(const Vec3& position)
	{
		Mat4 result = Mat4::Identity;
		result._41 = position.x;
		result._42 = position.y;
		result._43 = position.z;
		return result;
	}

	Mat4 Mat4::Rotate(float angle, const Vec3& axis)
	{
		Mat4 result = Mat4::Identity;

		float r = angle;
		float c = cos(r);
		float s = sin(r);
		float o = 1.0f - c;

		float x = axis.x;
		float y = axis.y;
		float z = axis.z;

		result._11 = x * o + c;
		result._12 = y * x * o + z * s;
		result._13 = x * z * o - y * s;

		result._21 = x * y * o - z * s;
		result._22 = y * o + c;
		result._23 = y * z * o + x * s;

		result._31 = x * z * o + y * s;
		result._32 = y * z * o - x * s;
		result._33 = z * o + c;

		return result;
	}

	Mat4 Mat4::Rotate(const Quaternion& quaternion)
	{
		Mat4 result = Mat4::Identity;

		Vec4 q;
		q.x = quaternion.x;
		q.y = quaternion.y;
		q.z = quaternion.z;
		q.w = quaternion.w;

		Vec4 q2;
		q2.x = (q.x + q.x);
		q2.y = (q.y + q.y);
		q2.z = (q.z + q.z);
		q2.w = (q.w + q.w);

		float qxqx2 = (q.x * q2.x);
		float qxqy2 = (q.x * q2.y);
		float qxqz2 = (q.x * q2.z);
		float qxqw2 = (q.w * q2.x);
		float qyqy2 = (q.y * q2.y);
		float qyqz2 = (q.y * q2.z);
		float qyqw2 = (q.w * q2.y);
		float qzqz2 = (q.z * q2.z);
		float qzqw2 = (q.w * q2.z);

		result._11 = (1.0f - qyqy2) - qzqz2;
		result._12 = qxqy2 - qzqw2;
		result._13 = qxqz2 + qyqw2;
		result._14 = 0.0f;

		result._21 = qxqy2 + qzqw2;
		result._22 = (1.0f - qxqx2) - qzqz2;
		result._23 = qyqz2 - qxqw2;
		result._24 = 0.0f;

		result._31 = qxqz2 - qyqw2;
		result._32 = qyqz2 + qxqw2;
		result._33 = (1.0f - qxqx2) - qyqy2;
		result._34 = 0.0f;

		return result;
	}

	Mat4 Mat4::Scale(const Vec3& scale)
	{
		Mat4 result = Mat4::Identity;
		result._11 = scale.x;
		result._22 = scale.y;
		result._33 = scale.z;

		return result;
	}

	Mat4 Mat4::Transpose(const Mat4& mat)
	{
		return Mat4
		(
			mat._11, mat._21, mat._31, mat._41,
			mat._12, mat._22, mat._32, mat._42,
			mat._13, mat._23, mat._33, mat._43,
			mat._14, mat._24, mat._34, mat._44
		);
	}

	const Mat4 Mat4::Zero
	(
		0.0f, 0.0f, 0.0f, 0.0f,
		0.0f, 0.0f, 0.0f, 0.0f,
		0.0f, 0.0f, 0.0f, 0.0f,
		0.0f, 0.0f, 0.0f, 0.0f
	);

	const Mat4 Mat4::Identity
	(
		1.0f, 0.0f, 0.0f, 0.0f,
		0.0f, 1.0f, 0.0f, 0.0f,
		0.0f, 0.0f, 1.0f, 0.0f,
		0.0f, 0.0f, 0.0f, 1.0f
	);
}