#pragma once

#include "base/CotRule.h"
#include "CotOpenAL.h"

namespace Cot
{
	class COT_API IDecoder
	{
		COT_INTERFACE(IDecoder);

		virtual bool Decode(const string& filename) = 0;

		virtual ALuint GetBuffer() const = 0;
		virtual int GetLength() const = 0;

	};
}