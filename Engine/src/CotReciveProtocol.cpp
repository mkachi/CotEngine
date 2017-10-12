#include "base/CotReciveProtocol.h"

namespace Cot
{
	void ReciveProtocol::AddRecive(const string& name, const Function& function)
	{
		auto iter = _functions.find(name);
		if (iter != _functions.cend())
		{
			iter->second.AddRecive(function);
			return;
		}

		_functions.emplace(std::make_pair(name, function));
	}

	void ReciveProtocol::Invoke(const string& function)
	{
		auto iter = _functions.find(function);
		if (iter != _functions.cend())
		{
			iter->second.Invoke();
		}
	}

	void ReciveProtocol::CallBack::AddRecive(const Function& function)
	{
		_functions.push_back(function);
	}

	void ReciveProtocol::CallBack::Invoke()
	{
		for (auto& function : _functions)
		{
			function();
		}
	}
}