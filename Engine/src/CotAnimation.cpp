#include "component/CotAnimation.h"
#include "component/CotSpriteRenderer.h"
#include "asset/CotAssetManager.h"

namespace Cot
{
	Animation* Animation::Init(const std::vector<AnimationData>& textures, float delay)
	{
		Reset();
		_spriteRenderer = GetOwner()->GetComponent<SpriteRenderer>();
		_textures = textures;
		_delay = delay;
		return this;
	}

	void Animation::Reset()
	{
		_play = _playAwake;
		_pause = false;
		_loop = false;
		_reverse = false;
		_index = 0;
		_delayCount = 0.0f;
	}

	void Animation::Update(Time& time)
	{
		if (!_play || _pause)
		{
			return;
		}

		_delayCount += time.GetUnscaledDeltaTime();
		if (_delay <= _delayCount)
		{
			_delayCount = 0.0f;

			if (_reverse)
			{
				_index -= 1;
				if (_index < 0)
				{
					if (_loop)
					{
						Stop();
						return;
					}
					_index = _textures.size() - 1;
				}
			}
			else
			{
				_index += 1;
				if (_index >= _textures.size())
				{
					if (_loop)
					{
						Stop();
						return;
					}
					_index = 0;
				}
			}

			if (_textures[_index].IsAtlas())
			{
				_spriteRenderer->SetTexture(
					_textures[_index].GetFileName(), 
					_textures[_index].GetKey());
			}
			else
			{
				_spriteRenderer->SetTexture(_textures[_index].GetFileName());
			}
		}
	}

	void Animation::Play()
	{
		_play = true;
		_pause = false;
		_index = 0;
		_delayCount = 0.0f;
	}

	void Animation::Pause()
	{
		_play = false;
		_pause = true;
	}

	void Animation::Stop()
	{
		_play = false;
		_pause = false;
		_index = 0;
		_delayCount = 0.0f;
	}

	void Animation::SetData(const std::vector<AnimationData>& textures)
	{
		Reset();
		_textures = textures;
	}

	void Animation::SetData(const std::vector<AnimationData>& textures, float delay)
	{
		Reset();
		_textures = textures;
		_delay = delay;
	}

	void Animation::SetReverse(bool reverse)
	{
		_reverse = reverse;
	}

	void Animation::SetPlayAwake(bool awake)
	{
		_playAwake = awake;
	}

	AnimationData::AnimationData(const string& filename)
		: _atlas(false)
		, _filename(filename)
	{	}

	AnimationData::AnimationData(const string& caif, const string& key)
		: _atlas(true)
		, _filename(caif)
		, _key(key)
	{	}

	AnimationData::~AnimationData()
	{	}
}