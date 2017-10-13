#pragma once

#include "CotAsset.h"
#include "audio/CotOggDecoder.h"
#include "audio/CotWavDecoder.h"

namespace Cot
{
	class COT_API AudioClip
		: public Asset
	{
	private:
		ALuint	_buffer;
		int		_length;

		bool Init(const string& filename);

	protected:
		AudioClip();

	public:
		virtual ~AudioClip();

		static AudioClip* Load(const string& filename);

		ALuint GetBuffer() { return _buffer; }
		int GetLength() { return _length; }

	};

	COT_API inline void DestroyAllDecoder();
}