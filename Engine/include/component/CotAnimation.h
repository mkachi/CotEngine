#pragma once

#include "CotIComponent.h"
#include "asset/CotTexture.h"
#include "asset/CotTextureAtlas.h"
#include <vector>
#include <initializer_list>

namespace Cot
{
	class COT_API AnimationData final
	{
	private:
		string	_filename;
		string	_key;
		bool	_atlas;

	public:
		AnimationData(const string& filename);
		AnimationData(const string& caif, const string& key);
		~AnimationData();

		string GetFileName() { return _filename; }
		string GetKey() { return _key; }
		bool IsAtlas() { return _atlas; }

	};

	class SpriteRenderer;
	Component(Animation, COT_API)
	{
		COT_COMPONENT(Animation);
	private:
		SpriteRenderer*			_spriteRenderer;
		std::vector<AnimationData>		_textures;
		bool	_play;
		bool	_pause;
		bool	_reverse;
		bool	_playAwake;
		int		_index;
		float	_delay;
		float	_delayCount;

	public:
		Animation* Init(const std::vector<AnimationData>& textures, float delay);

		void Reset() override;
		void Update(Time& time) override;

		void Play();
		void Pause();
		void Stop();

		bool IsPlay() { return _play; }

		void SetData(const std::vector<AnimationData>& textures);
		void SetData(const std::vector<AnimationData>& textures, float delay);

		void SetReverse(bool reverse);
		bool IsReverse() { return _reverse; }

		void SetPlayAwake(bool awake);
		bool IsPlayAwake() { return _playAwake; }

		int GetCurrentIndex() { return _index; }

	};
}