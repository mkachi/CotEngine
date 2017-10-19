#include "math/CotGL2DX.h"

namespace Cot
{
	D3DXCOLOR ToDxMath(const Color32& color)
	{
		return D3DCOLOR_ARGB(color.a, color.r, color.g, color.b);
	}

	D3DXMATRIX ToDxMath(const Mat4& mat)
	{
		return mat.ToArray;
	}

	D3DXVECTOR2 ToDxMath(const Vec2& vec)
	{
		return vec.ToArray;
	}

	D3DXVECTOR3 ToDxMath(const Vec3& vec)
	{
		return vec.ToArray;
	}

	D3DXVECTOR4 ToDxMath(const Vec4& vec)
	{
		return vec.ToArray;
	}

	D3DXQUATERNION ToDxMath(const Quaternion& quternion)
	{
		return quternion.ToArray;
	}

	RECT ToDxMath(Rect& rect)
	{
		return { (long)rect.GetMinX(), (long)rect.GetMinY(), (long)rect.GetMaxX(), (long)rect.GetMaxY() };
	}
}