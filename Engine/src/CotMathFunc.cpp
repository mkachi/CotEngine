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

	float Pi()
	{
		return 3.141592f;
	}

	float Lerp(float v1, float v2, float amount)
	{
		return (v1 + (v2 - v1) * amount);
	}
}