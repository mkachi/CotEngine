#include "component/CotIRenderComponent.h"

namespace Cot
{
	void IRenderComponent::SetAnchor(const Vec2& anchor)
	{
		_anchor = anchor;
	}

	void IRenderComponent::SetRect(const Rect& rect)
	{
		_rect = rect;
	}

	void IRenderComponent::SetSize(const Size& size)
	{
		_size = size;
	}
	
	void IRenderComponent::SetDepth(int depth)
	{
		_depth = depth;
	}

	void IRenderComponent::SetColor(const Color& color)
	{
		_color = color;
	}
}
