#pragma once

#include "CotIComponent.h"
#include "asset/CotAudioClip.h"

namespace Cot
{
	enum class AudioState
	{
		Playing,
		Paused,
		Stopped,
	};

	Component(AudioSource, COT_API)
	{
		COT_COMPONENT(AudioSource);
	private:
		AudioClip*	_clip;
		ALuint		_source;
		float		_volume;
		float		_pitch;
		float		_maxDistance;
		Vec3		_velocity;
		bool		_loop;
		bool		_2d;

	public:
		AudioSource* Init(const string& filename, bool loop = false);

		void Reset() override;
		void Update(Time& time) override;
		void OnDestroy() override;

		void Play();
		void Pause();
		void Resume();
		void Stop();

		void SetClip(const string& filename);
		AudioClip& GetClip() { return *_clip; }

		void SetPitch(float pitch);
		float GetPitch() { return _pitch; }

		void SetLoop(bool loop);
		bool IsLoop() { return _loop; }

		int GetPosition();
		int GetLength() { return _clip->GetLength(); }

		void SetMaxDistance(float maxDistance);
		float GetMaxDistance() { return _maxDistance; }

		void SetVelocity(const Vec3& velocity);
		Vec3 GetVelocity() { return _velocity; }

		void Set2D(bool value);
		bool Is2D() { return _2d; }

		AudioState GetState();

	};
}