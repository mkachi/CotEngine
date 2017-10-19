#pragma once

#include "CotMath.h"
#include <d3dx9.h>

namespace Cot
{
	COT_API inline D3DXCOLOR		ToDxMath(const Color32& color);
	COT_API inline D3DXMATRIX		ToDxMath(const Mat4& mat);
	COT_API inline D3DXVECTOR2		ToDxMath(const Vec2& vec);
	COT_API inline D3DXVECTOR3		ToDxMath(const Vec3& vec);
	COT_API inline D3DXVECTOR4		ToDxMath(const Vec4& vec);
	COT_API inline D3DXQUATERNION	ToDxMath(const Quaternion& quternion);
	COT_API inline RECT				ToDxMath(Rect& rect);
}