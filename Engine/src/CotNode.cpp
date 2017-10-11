#include "base/CotNode.h"

namespace Cot
{
	Node::Node()
	{	}

	Node::Node(const string& name)
		: _name(name)
	{	}

	Node::~Node()
	{	
		if (_parent != nullptr)
		{
			_parent->RemoveChild(this);
		}
		RemoveAllChild();
	}

	void Node::SetParent(Node* parent)
	{
		_parent = parent;
	}

	void Node::AddChild(Node* child)
	{
		child->SetParent(this);
		_children.push_back(child);
	}

	void Node::RemoveChild(Node* child)
	{
		_children.erase(std::find(_children.cbegin(), _children.cend(), child));
	}

	void Node::RemoveChildByName(const string& name)
	{
		std::vector<Node*>::const_iterator find;
		for (auto iter = _children.cbegin(); iter != _children.cend(); ++iter)
		{
			if ((*iter)->GetName() == name)
			{
				find = iter;
				break;
			}
		}
		_children.erase(find);
	}

	void Node::RemoveAllChild()
	{
		for (auto& child : _children)
		{
			SafeDelete(child);
		}
	}

	void Node::SetName(const string& name)
	{
		_name = name;
	}
}