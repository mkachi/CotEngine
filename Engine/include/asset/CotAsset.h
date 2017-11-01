#pragma once

#include "base/CotRule.h"

namespace Cot
{
	class COT_API Asset
	{
	protected:
		string	_key;
		string	_filePath;
		uint	_refCount;

	public:
		Asset();
		virtual ~Asset();

		const string& GetKey() { return _key; }

		void Retain();
		void Release();
		uint GetRefCount() { return _refCount; }

		virtual void Reload() = 0;

	};
}