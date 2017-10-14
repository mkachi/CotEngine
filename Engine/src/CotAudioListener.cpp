#include "component/CotAudioListener.h"

namespace Cot
{
	AudioListener* AudioListener::Init()
	{
		_device = alcOpenDevice(nullptr);
		_context = alcCreateContext(_device, nullptr);
		alcMakeContextCurrent(_context);

		alListenerfv(AL_POSITION, GetOwner()->GetPosition().ToArray);

		return this;
	}

	void AudioListener::Update(Time& time)
	{
		if (GetOwner()->IsDirty())
		{
			alListenerfv(AL_POSITION, GetOwner()->GetPosition().ToArray);
		}
	}
}