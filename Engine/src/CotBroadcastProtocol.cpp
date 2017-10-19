#include "base/CotBroadCastProtocol.h"

namespace Cot
{
	BroadCastProtocol::BroadCastProtocol()
	{	}

	BroadCastProtocol::~BroadCastProtocol()
	{
		for (auto& func : _functions)
		{
			SafeDelete(func.second);
		}
	}

	void BroadCastProtocol::Add(const string& name, const Function<void()>& function)
	{
		std::vector<string> tokens = Split(name, { "::" });
		string splitName;
		if (tokens.size() > 1)
		{
			splitName = tokens[1];
		}
		else
		{
			splitName = name;
		}

		if (!_functions.empty())
		{
			auto iter = _functions.find(splitName);
			if (iter != _functions.cend())
			{
				iter->second->Add(function);
				return;
			}
		}

		_functions.emplace(std::make_pair(splitName, new CallBack<void()>()));
		_functions[splitName]->Add(function);
	}

	void BroadCastProtocol::Invoke(const string& function)
	{
		auto iter = _functions.find(function);
		if (iter != _functions.cend())
		{
			iter->second->Invoke();
		}
	}
}