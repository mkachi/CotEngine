#pragma once

#include "CotRule.h"
#include <vector>

namespace Cot
{
	class COT_API Node
	{
	protected:
		string		_name;
		Node*		_parent;
		std::vector<Node*> _children;

	public:
		Node();
		Node(const string& name);
		virtual ~Node();

		void SetParent(Node* parent);
		Node* GetParent() { return _parent; }

		void AddChild(Node* child);
		std::vector<Node*>& GetChildren() { return _children; }

		void RemoveChild(Node* child);
		void RemoveChildByName(const string& name);
		void RemoveAllChild();

		void SetName(const string& name);
		string GetName() { return _name; }

	};
}