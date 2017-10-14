#pragma once

#include "CotIComponent.h"
#include "audio/CotOpenAL.h"

namespace Cot
{
	Component(AudioListener, COT_API)
	{
		COT_COMPONENT(AudioListener);
	private:
		ALCdevice*	_device;
		ALCcontext* _context;

	public:
		AudioListener* Init();
		void Update(Time& time) override;

	};
}