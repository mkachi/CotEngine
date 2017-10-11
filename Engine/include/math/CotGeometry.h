#pragma once

#include "base/CotRule.h"

namespace Cot 
{
	class COT_API Size final
	{
	public:
		uint width;
		uint height;

		Size();
		Size(const uint w, const uint h);
		Size(const Size& size);
		Size(const Size&& size);
		~Size();

		Size& operator=(const Size& size);
		Size operator+(const Size& size) const;
		Size operator-(const Size& size) const;
		Size operator*(uint value) const;
		Size operator/(uint value) const;

		void SetSize(const uint width, const uint height);

		static const Size Zero;
		static const Size One;

	};

	class COT_API Rect final
	{
	public:
		uint x;
		uint y;
		uint width;
		uint height;

		Rect();
		Rect(const uint x, const uint y, const uint w, const uint h);
		Rect(const Rect& rect);
		Rect(const Rect&& rect);
		~Rect();

		Rect& operator=(const Rect& size);
		Rect operator+(const Rect& size) const;
		Rect operator-(const Rect& size) const;
		Rect operator*(const uint value) const;
		Rect operator/(const uint value) const;

		void SetRect(const uint x, const uint y, const uint w, const uint h);

	};
}