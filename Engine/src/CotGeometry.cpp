#include "math/CotGeometry.h"

namespace Cot 
{
	Size::Size()
		:width(0.0f), height(0.0f)
	{	}

	Size::Size(const uint w, const uint h)
		: width(w), height(h)
	{	}

	Size::Size(const Size& size)
		: width(size.width), height(size.height)
	{	}

	Size::Size(const Size&& size)
		: width(size.width), height(size.height)
	{	}

	Size::~Size()
	{   }

	Size& Size::operator=(const Size& size)
	{
		SetSize(size.width, size.height);
		return *this;
	}

	Size Size::operator+(const Size& size) const
	{
		return Size(width + size.width, height + size.height);
	}

	Size Size::operator-(const Size& size) const
	{
		return Size(width - size.width, height - size.height);
	}

	Size Size::operator*(uint value) const
	{
		return Size(width * value, height*value);
	}

	Size Size::operator/(uint value) const
	{
		COT_ASSERT(value <= 0.0f, "Division by 0");

		return Size(width / value, width / value);
	}

	void Size::SetSize(const uint w, const uint h)
	{
		width = w;
		height = h;
	}

	const Size Size::Zero(0, 0);
	const Size Size::One(1, 1);

	Rect::Rect()
		:x(0.0f), y(0.0f), width(0.0f), height(0.0f)
	{	}

	Rect::Rect(const uint xx, const uint yy, const uint w, const uint h)
		: x(xx), y(yy), width(w), height(h)
	{	}

	Rect::Rect(const Rect& rect)
		: x(rect.x), y(rect.y), width(rect.width), height(rect.height)
	{	}

	Rect::Rect(const Rect&& rect)
		: x(rect.x), y(rect.y), width(rect.width), height(rect.height)
	{	}

	Rect::~Rect()
	{   }

	Rect& Rect::operator=(const Rect& rect)
	{
		SetRect(rect.x, rect.y, rect.width, rect.height);
		return *this;
	}

	Rect Rect::operator+(const Rect& rect) const
	{
		return Rect(x + rect.x, y + rect.y, width + rect.width, height + rect.height);
	}

	Rect Rect::operator-(const Rect& rect) const
	{
		return Rect(x - rect.x, y - rect.y, width - rect.width, height - rect.height);
	}

	Rect Rect::operator*(uint value) const
	{
		return Rect(x * value, y * value, width * value, height * value);
	}

	Rect Rect::operator/(uint value) const
	{
		COT_ASSERT(value <= 0.0f, "Division by 0");

		return Rect(x / value, y / value, width / value, height / value);
	}

	void Rect::SetRect(const uint xx, const uint yy, const uint w, const uint h)
	{
		x = xx;
		y = yy;
		width = w;
		height = h;
	}
}