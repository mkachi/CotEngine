#pragma once

#include "base/CotRule.h"
#include <functional>
#include <unordered_map>
#include <vector>

#define COT_BROAD_CAST(_FUNCTION_) #_FUNCTION_, _FUNCTION_

namespace Cot
{
	class COT_API BroadCastProtocol final
	{
		using Function = std::function<void()>;
		class COT_API CallBack final
		{
		private:
			std::vector<Function> _functions;

		public:
			CallBack() {}
			~CallBack() {}
			void Add(const Function& function);
			void Invoke();

		};
	private:
		std::unordered_map<string, CallBack*> _functions;

	public:
		BroadCastProtocol();
		~BroadCastProtocol();

		void Add(const string& name, const Function& function);
		void Invoke(const string& function);

	};
}