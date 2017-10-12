#include "base/CotBroadCastProtocol.h"

namespace Cot
{
	void BroadCastProtocol::Add(const string& name, const Function& function)
	{
		auto iter = _functions.find(name);
		if (iter != _functions.cend())
		{
			iter->second->Add(function);
			return;
		}

		_functions.emplace(std::make_pair(name, new BroadCastProtocol::CallBack()));
		_functions[name]->Add(function);
	}

	void BroadCastProtocol::Invoke(const string& function)
	{
		auto iter = _functions.find(function);
		if (iter != _functions.cend())
		{
			iter->second->Invoke();
		}
	}

	void BroadCastProtocol::CallBack::Add(const Function& function)
	{
		_functions.push_back(function);
	}

	void BroadCastProtocol::CallBack::Invoke()
	{
		for (auto& function : _functions)
		{
			function();
		}
	}
}