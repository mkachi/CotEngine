#include "math/CotMathFunc.h"

namespace Cot 
{
	float ToRad(const float deg)
	{
		return deg * 0.017453f;
	}

	float ToDeg(const float rad)
	{
		return rad * 57.295779f;
	}

	float Clamp(const float value, const float min, const float max)
	{
		return (value > min) ? (value < max) ? value : max : min;
	}

	float Pi()
	{
		return 3.141592f;
	}
}