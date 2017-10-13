#include "asset/CotAudioClip.h"
#include "asset/CotAssetManager.h"

namespace Cot
{
	static std::vector<IDecoder*> _decoders = {
		new WavDecoder(),
		new OggDecoder(),
	};

	AudioClip::AudioClip()
	{	}

	AudioClip::~AudioClip()
	{
		alDeleteBuffers(1, &_buffer);
	}

	AudioClip* AudioClip::Load(const string& filename)
	{
		if (AssetManager::GetInstance().IsHave(filename))
		{
			return AssetManager::GetInstance().Get<AudioClip*>(filename);
		}

		AudioClip* result = new (std::nothrow) AudioClip();
		if (result != nullptr && result->Init(filename))
		{
			AssetManager::GetInstance().Add(filename, result);
			return result;
		}
		return nullptr;
	}

	bool AudioClip::Init(const string& filename)
	{
		_key = filename;

		for (auto& decoder : _decoders)
		{
			if (decoder->Decode(filename))
			{
				_buffer = decoder->GetBuffer();
				_length = decoder->GetLength();
				return true;
			}
		}

		return false;
	}

	void DestroyAllDecoder()
	{
		for (auto& decoder : _decoders)
		{
			SafeDelete(decoder);
		}
	}
}