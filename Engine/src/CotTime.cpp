#include "base/CotTime.h"

namespace Cot
{
	Time::Time()
		: _lastTime(std::chrono::high_resolution_clock::now())
		, _timeScale(1.0f)
		, _deltaTime(0.0f)
	{	}

	Time::~Time()
	{	}

	void Time::Tick()
	{
		_currentTime = std::chrono::high_resolution_clock::now();
		_deltaTime = std::chrono::duration_cast<std::chrono::nanoseconds>(_currentTime - _lastTime).count();
		_deltaTime /= 1000000000;
		_lastTime = _currentTime;
	}

	void Time::SetTimeScale(const float scale)
	{
		_timeScale = scale;
	}
}