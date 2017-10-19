#pragma once

#include "base/CotCallback.hpp"
#include <unordered_map>

#define COT_BROAD_CAST(_FUNCTION_) #_FUNCTION_, std::bind(&_FUNCTION_, this)

namespace Cot
{
	class COT_API BroadCastProtocol final
	{
	private:
		std::unordered_map<string, CallBack<void()>*> _functions;

	public:
		BroadCastProtocol();
		~BroadCastProtocol();

		void Add(const string& name, const Function<void()>& function);
		void Invoke(const string& function);

	};
}