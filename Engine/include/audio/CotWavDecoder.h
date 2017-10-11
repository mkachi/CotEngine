#pragma once

#include "CotIDecoder.h"

namespace Cot
{
	class COT_API WavDecoder final
		: public IDecoder
	{
	private:
		ALuint  _buffer;
		int     _length;

	public:
		WavDecoder();
		virtual ~WavDecoder();

		bool Decode(const string& filename) override;

		ALuint GetBuffer() const override { return _buffer; }
		int GetLength() const override { return _length; }

	};
}