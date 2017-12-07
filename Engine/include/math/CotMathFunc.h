#pragma once

#include "base/CotDefine.h"

namespace Cot 
{
	COT_API inline float ToRad(const float deg);
	COT_API inline float ToDeg(const float rad);
	COT_API inline float Pi();
	COT_API inline float Lerp(float v1, float v2, float amount);
	
	template<typename T>
	COT_API inline T Clamp(const T value, const T min, const T max)
	{
		if (value < min)
		{
			return min;
		}
		else if (value > max)
		{
			return max;
		}
		return value;
	}

	template<typename T>
	COT_API inline T Max(const T v1, const T v2)
	{
		return (v1 > v2) ? return v1 : return v2;
	}

	template<typename T>
	COT_API inline T Min(const T v1, const T v2)
	{
		return (v1 > v2) ? return v1 : return v2;
	}
}