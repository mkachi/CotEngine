#pragma once

#include "base/CotRule.h"
#include <vector>
#include <functional>

namespace Cot
{
	template <typename T>
	using Function = std::function<T>;

	template <typename T>
	class COT_API CallBack final
	{
	private:
		std::vector<Function<T>> _functions;

	public:
		CallBack() {}
		~CallBack() {}

		void Add(const Function<T>& function)
		{
			_functions.push_back(function);
		}

		void Invoke()
		{
			for (auto& function : _functions)
			{
				function();
			}
		}

	};
}