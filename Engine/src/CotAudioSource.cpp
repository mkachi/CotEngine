#include "component/CotAudioSource.h"

namespace Cot
{
	AudioSource* AudioSource::Init(const string& filename, bool loop)
	{
		Reset();
		_clip = AudioClip::Load(filename);
		_clip->Retain();
		alGenSources(1, &_source);
		alSourcei(_source, AL_BUFFER, _clip->GetBuffer());

		alSourcei(_source, AL_LOOPING, loop);
		alSourcef(_source, AL_MIN_GAIN, 0.0f);
		alSourcef(_source, AL_MAX_GAIN, 1.0f);
		alSourcef(_source, AL_PITCH, _pitch);
		alSourcef(_source, AL_GAIN, _volume);

		alSourcefv(_source, AL_POSITION, GetOwner()->GetPosition().ToArray);
		alSourcefv(_source, AL_VELOCITY, _velocity.ToArray);
		
		return this;
	}

	void AudioSource::Reset()
	{
		SafeRelease(_clip);
		_velocity = Vec3::Zero;
		_source = 0;
		_volume = 1.0f;
		_pitch = 1.0f;
		_loop = false;
		_2d = false;
	}

	void AudioSource::Update(Time& time)
	{
		if (GetOwner()->IsDirty() && !_2d)
		{
			alSourcefv(_source, AL_POSITION, GetOwner()->GetPosition().ToArray);
		}
	}

	void AudioSource::OnDestroy()
	{
		_clip->Release();
	}

	void AudioSource::Play()
	{
		alSourceStop(_source);
		alSourcePlay(_source);
	}

	void AudioSource::Pause()
	{
		alSourcePause(_source);
	}

	void AudioSource::Resume()
	{
		alSourcePlay(_source);
	}

	void AudioSource::Stop()
	{
		alSourceStop(_source);
	}

	void AudioSource::SetClip(const string& filename)
	{
		SafeRelease(_clip);
		_clip = AudioClip::Load(filename);
		alGenSources(1, &_source);
		alSourcei(_source, AL_BUFFER, _clip->GetBuffer());
	}

	void AudioSource::SetPitch(float pitch)
	{
		_pitch = pitch;
		alSourcef(_source, AL_PITCH, pitch);
	}

	void AudioSource::SetLoop(bool loop)
	{
		_loop = loop;
		alSourcef(_source, AL_LOOPING, loop);
	}

	int AudioSource::GetPosition()
	{
		int result = 0;
		alGetSourcei(_source, AL_SEC_OFFSET, &result);
		return result;
	}

	void AudioSource::SetVelocity(const Vec3& velocity)
	{
		_velocity = velocity;
		alSourcefv(_source, AL_VELOCITY, _velocity.ToArray);
	}

	void AudioSource::Set2D(bool value)
	{
		_2d = value;
	}

	AudioState AudioSource::GetState()
	{
		int state;
		alGetSourcei(_source, AL_SOURCE_STATE, &state);

		if (state == AL_PLAYING)
		{
			return AudioState::Playing;
		}
		else if (state == AL_PAUSED)
		{
			return AudioState::Paused;
		}
		else if (state == AL_STOPPED)
		{
			return AudioState::Stopped;
		}
	}

	void AudioSource::SetMaxDistance(float maxDistance)
	{
		_maxDistance = maxDistance;
		alSourcef(_source, AL_MAX_DISTANCE, _maxDistance);
	}
}