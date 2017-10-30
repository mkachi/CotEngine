#pragma once

#include "base/CotRule.h"

namespace Cot
{
	template <typename T>
	class COT_API Queue
	{
	private:
		struct Node
		{
			T		data;
			Node*	next;
		};
		Node*	_head;
		Node*	_back;
		uint	_size;

		void DestroyAllNode()
		{
			Node* node = _head;
			while (node != nullptr)
			{
				node = node->next;
				SafeDelete(node);
			}
		}

	public:
		Queue()
			: _head(nullptr)
			, _size(0)
		{	}

		~Queue()
		{
			DestroyAllNode();
		}

		bool Empty()
		{
			return (_size == 0 || _head == nullptr);
		}

		uint Size() { return _size; }

		T Front()
		{
			COT_ASSERT(_head == nullptr, "Head is nullptr!");
			return _head->data;
		}

		T Back()
		{
			COT_ASSERT(_back == nullptr, "Back is nullptr!");
			return _back->data;
		}

		void Push(T data)
		{
			++_size;
			if (_head != nullptr)
			{
				Node* newNode = new Node();
				newNode->data = data;
				newNode->next = nullptr;

				_back->next = newNode;
				_back = newNode;
			}
			else
			{
				_head = new Node();
				_head->data = data;
				_head->next = nullptr;
				_back = _head;
			}
		}

		void Pop()
		{
			COT_ASSERT(_head == nullptr, "Head is nullptr!");
			--_size;
			Node* temp = _head;
			_head = _head->next;

			SafeDelete(temp);
		}
	};
}