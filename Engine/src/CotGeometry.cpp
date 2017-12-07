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
	{
		SetRect(0.0f, 0.0f, 0.0f, 0.0f);
	}

	Rect::Rect(float xx, float yy, float w, float h)
	{	
		SetRect(xx, yy, w, h);
	}

	Rect::Rect(const Vec2& origin, const Size& size)
	{
		this->origin = origin;
		this->size = size;
	}

	Rect::Rect(const Rect& rect)
	{
		SetRect(rect.origin.x, rect.origin.y, rect.size.width, rect.size.height);
	}

	Rect::Rect(const Rect&& rect)
	{	
		SetRect(rect.origin.x, rect.origin.y, rect.size.width, rect.size.height);
	}

	Rect::~Rect()
	{   }

	Rect& Rect::operator=(const Rect& rect)
	{
		SetRect(rect.origin.x, rect.origin.y, rect.size.width, rect.size.height);
		return *this;
	}

	void Rect::SetRect(float x, float y, float w, float h)
	{
		origin.x = x;
		origin.y = y;
		size.width = w;
		size.height = h;
	}

	float Rect::GetMinX()
	{
		return origin.x - (size.width / 2);
		return origin.x;
	}

	float Rect::GetMidX()
	{
		return origin.x;
		return origin.x + size.width / 2.0f;
	}

	float Rect::GetMaxX()
	{
		return origin.x + (size.width / 2);
		return origin.x + size.width;
	}

	float Rect::GetMinY()
	{
		return origin.y - (size.height / 2);
		return origin.y;
	}

	float Rect::GetMidY()
	{
		return origin.y;
		return origin.y + size.height / 2.0f;
	}

	float Rect::GetMaxY()
	{
		return origin.y + (size.height / 2);
		return origin.y + size.height;
	}

	Circle::Circle()
		: r(0.0f), center(Vec2::Zero)
	{	}

	Circle::Circle(const float r, Vec2& center)
		: r(r), center(center)
	{	}

	Circle::Circle(Circle& circle)
		: r(circle.r), center(circle.center)
	{	}

	Circle& Circle::operator=(Circle& circle)
	{
		SetCircle(circle.r, circle.center);
		return *this;
	}

	void Circle::SetCircle(float r, Vec2& center)
	{
		this->r = r;
		this->center = center;
	}
}