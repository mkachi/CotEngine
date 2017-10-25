#include "base/CotNode.h"
#include "input/CotInputManager.h"

namespace Cot
{
	Node::Node()
	{	}

	Node::~Node()
	{
		DestroyListeners();
	}

	void Node::CreateKeyListener()
	{
		if (_keyListener == nullptr)
		{
			_keyListener = new KeyListener();
			InputManager::GetInstance().AddKeyListener(_keyListener);
		}
	}

	void Node::CreateMouseListener()
	{
		if (_mouseListener == nullptr)
		{
			_mouseListener = new MouseListener();
			InputManager::GetInstance().AddMouseListener(_mouseListener);
		}
	}

	void Node::DestroyListeners()
	{
		if (_mouseListener != nullptr)
		{
			InputManager::GetInstance().RemoveMouseListener(_mouseListener);
			SafeDelete(_mouseListener);
			_mouseListener = nullptr;
		}

		if (_keyListener != nullptr)
		{
			InputManager::GetInstance().RemoveKeyListener(_keyListener);
			SafeDelete(_keyListener);
			_keyListener = nullptr;
		}
	}
}