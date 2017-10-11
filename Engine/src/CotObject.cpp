#include "base/object/CotObject.h"

namespace Cot
{
	Object::Object()
	{	}

	Object::~Object()
	{	}

	void Object::SetActive(bool active)
	{
		_active = active;
	}

	void Object::Update()
	{
		Node::Update();
	}
}