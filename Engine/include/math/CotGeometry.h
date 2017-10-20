#pragma once

#include "CotVec2.h"

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
		Vec2 origin;
		Size size;

		Rect();
		Rect(const float x, const float y, const float w, const float h);
		Rect(const Vec2& origin, const Size& size);
		Rect(const Rect& rect);
		Rect(const Rect&& rect);
		~Rect();

		Rect& operator=(const Rect& rect);

		void SetRect(float x, float y, float w, float h);

		float GetMinX();
		float GetMidX();
		float GetMaxX();
		float GetMinY();
		float GetMidY();
		float GetMaxY();

	};

	class COT_API Circle
	{
	public:
		float r;
		Vec2 center;

		Circle();
		Circle(float r, Vec2& center);
		Circle(Circle& circle);

		Circle& operator=(Circle& circle);

		void SetCircle(float r, Vec2& center);

	};
}