#include "asset/CotAsset.h"

namespace Cot
{
	Asset::Asset()
		: _key("")
		, _refCount(1)
	{	}

	Asset::~Asset()
	{	}

	void Asset::Retain()
	{
		++_refCount;
	}

	void Asset::Release()
	{
		--_refCount;
		if (_refCount < 1)
		{
			delete this;
		}
	}
}