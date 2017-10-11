#include "math/CotGL2DX.h"

namespace Cot
{
	D3DXCOLOR ToDxMath(const Color32& color)
	{
		return D3DCOLOR_ARGB(color.a, color.r, color.g, color.b);
	}

	D3DXMATRIX ToDxMath(const Mat4& mat)
	{
		Mat4 temp = Mat4::Transpose(mat);
		return D3DXMATRIX(temp.ToArray);
	}

	D3DXVECTOR2 ToDxMath(const Vec2& vec)
	{
		return D3DXVECTOR2(vec.ToArray);
	}

	D3DXVECTOR3 ToDxMath(const Vec3& vec)
	{
		return D3DXVECTOR3(vec.ToArray);
	}

	D3DXVECTOR4 ToDxMath(const Vec4& vec)
	{
		return D3DXVECTOR4(vec.ToArray);
	}

	D3DXQUATERNION ToDxMath(const Quaternion& quternion)
	{
		return D3DXQUATERNION(quternion.ToArray);
	}

}