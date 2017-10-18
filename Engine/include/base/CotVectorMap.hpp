#pragma once

#include <vector>
#include "CotRule.h"

namespace Cot
{
	template<typename Key, typename Value>
	class COT_API VectorMap
	{
		typedef std::pair<Key, Value> Element;
	private:
		std::vector<Element> _map;

	public:
		typedef typename std::vector<Element>::iterator iterator;
		typedef typename std::vector<Element>::const_iterator const_iterator;

		iterator begin() { return _map.begin(); }
		iterator begin() const { return _map.begin(); }

		iterator end() { return _map.end(); }
		iterator end() const { return _map.end(); }

		const_iterator cbegin() const { return _map.begin(); }
		const_iterator cend() const { return _map.end(); }

		VectorMap()
		{
			_map.clear();
			_map.reserve(150);
		}

		VectorMap(const VectorMap& other)
			: _map(other._map)
		{	}

		~VectorMap()
		{
			_map.clear();
		}

		void add(const Key& key, Value value) noexcept
		{
			_map.emplace_back(std::make_pair(key, component));
		}

		void remove(const Key& key) noexcept
		{
			if (_map.empty())
			{
				return;
			}
			Value value = find(key);
			Element element = std::make_pair(key, value);
			_map.erase(std::find(_map.cbegin(), _map.cend(), element));
		}

		void erase(const_iterator iter) noexcept
		{
			_map.erase(iter);
		}

		Value find(const Key& key) noexcept
		{
			if (_map.empty())
			{
				return NULL;
			}
			for (uint i = 0; i < _map.size(); ++i)
			{
				if (_map[i].first == key)
				{
					return _map[i].second;
				}
			}
			return NULL;
		}

		bool isHave(const Key& key) noexcept
		{
			if (_map.empty())
			{
				return false;
			}
			for (uint i = 0; i < _map.size(); ++i)
			{
				if (_map[i].first == key)
				{
					return true;
				}
			}

			return false;
		}

		VectorMap& operator=(const VectorMap& other) noexcept
		{
			_map = other._map;
		}

		Value operator[](const Key& key) noexcept
		{
			return find(key);
		}

		Element operator[](const int index) noexcept
		{
			return _map[index];
		}

		void clear() noexcept
		{
			_map.clear();
		}

		uint size() const noexcept { return _map.size(); }

	};

	template<typename Key, typename Value>
	class COT_API MultiVectorMap
	{
		typedef std::pair<Key, Value> Element;
	private:
		std::vector<Element> _map;

	public:
		typedef typename std::vector<Element>::iterator iterator;
		typedef typename std::vector<Element>::const_iterator const_iterator;

		iterator begin() { return _map.begin(); }
		iterator begin() const { return _map.begin(); }

		iterator end() { return _map.end(); }
		iterator end() const { return _map.end(); }

		const_iterator cbegin() const { return _map.cbegin(); }
		const_iterator cend() const { return _map.cend(); }

		MultiVectorMap()
		{
			_map.clear();
			_map.reserve(150);
		}

		MultiVectorMap(const MultiVectorMap& other)
			: _map(other._map)
		{	}

		~MultiVectorMap()
		{
			_map.clear();
		}

		void add(const Key& key, Value value) noexcept
		{
			_map.emplace_back(std::make_pair(key, value));
		}

		void remove(const Key& key) noexcept
		{
			if (_map.empty())
			{
				return;
			}
			Value value = find(key);
			Element element = std::make_pair(key, value);
			_map.erase(std::find(_map.cbegin(), _map.cend(), element));
		}

		void erase(const_iterator iter) noexcept
		{
			_map.erase(iter);
		}

		Value find(const Key& key) noexcept
		{
			if (_map.empty())
			{
				return NULL;
			}
			for (uint i = 0; i < _map.size(); ++i)
			{
				if (_map[i].first == key)
				{
					return _map[i].second;
				}
			}
			return NULL;
		}

		template<typename T>
		std::vector<T> finds(const Key& key) noexcept
		{
			std::vector<T> result;
			result.clear();
			if (_map.empty())
			{
				return result;
			}

			result.reserve(150);
			for (uint i = 0; i < _map.size(); ++i)
			{
				if (_map[i].first == key)
				{
					result.push_back(static_cast<T>(_map[i].second));
				}
			}
			return result;
		}

		bool isHave(const Key& key) noexcept
		{
			if (_map.empty())
			{
				return false;
			}
			for (uint i = 0; i < _map.size(); ++i)
			{
				if (_map[i].first == key)
				{
					return true;
				}
			}

			return false;
		}

		MultiVectorMap& operator=(const MultiVectorMap& other) noexcept
		{
			_map = other._map;
			return *this;
		}

		Value operator[](const Key& key) noexcept
		{
			return find(key);
		}

		Element operator[](const int index) noexcept
		{
			return _map[index];
		}

		void clear() noexcept
		{
			_map.clear();
		}

		uint size() const noexcept { return _map.size(); }

	};
}