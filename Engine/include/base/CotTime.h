#pragma once

#include "CotRule.h"
#include <chrono>

namespace Cot 
{
	class COT_API Time final
	{
	private:
		std::chrono::steady_clock::time_point _currentTime;
		std::chrono::steady_clock::time_point _lastTime;
		float _deltaTime;
		float _timeScale;

	public:
		Time();
		~Time();

		void Tick();
		void SetTimeScale(const float scale);
		float GetTimeScale() const { return _timeScale; }
		float GetDeltaTime() const { return _deltaTime * _timeScale; }

	};
}