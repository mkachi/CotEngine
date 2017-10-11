#pragma once

#include "base/CotDefine.h"

namespace Cot 
{
	COT_API inline float ToRad(const float deg);
	COT_API inline float ToDeg(const float rad);
	COT_API inline float Clamp(const float value, const float min, const float max);
	COT_API inline float Pi();
}