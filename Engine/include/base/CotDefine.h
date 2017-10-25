#pragma once

#include <cassert>

#define COT_SINGLETON_H(_CLASS_) \
private: \
	_CLASS_() {} \
public: \
	~_CLASS_() {} \
	static _CLASS_& GetInstance(); \
	static void Destroy()

#define COT_SINGLETON_CPP(_CLASS_) \
	static _CLASS_* _instance = nullptr; \
	_CLASS_& _CLASS_::GetInstance() \
	{ \
		if (_instance == nullptr) \
		{ \
			_instance = new _CLASS_(); \
		} \
		return *_instance; \
	} \
	void _CLASS_::Destroy() \
	{ \
		SafeDelete(_instance); \
	}

#define COT_INTERFACE(_CLASS_) \
protected: \
	_CLASS_() {} \
public: \
	virtual ~_CLASS_() {}

#define COT_DEFAULT_CASE default: break

#define CLEAR_QUEUE(_queue_) \
	for(int i = 0; i < _queue_.size(); ++i) \
	{ \
		_queue_.pop(); \
	}

#ifdef _DEBUG
#define COT_ASSERT(_IF_, _MESSAGE_) if (_IF_) { assert(0); }
#else
#define COT_ASSERT(_IF_, _MESSAGE_)
#endif

#ifdef COT_EXPORTS
#define COT_API __declspec(dllexport)
#else
#define COT_API __declspec(dllexport)
#endif

template <typename T>
struct COT_API ComponentType;

#define Component(_TYPE_, ...) \
class _TYPE_; \
template <> \
struct ComponentType<_TYPE_> \
{ static constexpr const char* GetType() { return #_TYPE_; } }; \
class __VA_ARGS__ _TYPE_ \
	: public Cot::IComponent

#define ComponentExt(_TYPE_, _EXT_, ...) \
class _TYPE_; \
template <> \
struct ComponentType<_TYPE_> \
{ static constexpr const char* GetType() { return #_TYPE_; } }; \
class __VA_ARGS__ _TYPE_ \
	: public _EXT_

#define COT_COMPONENT(_CLASS_) \
public: \
_CLASS_() { _type = #_CLASS_; _enable = true; Reset(); } \
virtual ~_CLASS_() { OnDisable(); OnDestroy(); }

namespace Cot 
{
	template <typename T>
	COT_API inline void SafeDelete(T*& obj)
	{
		if (obj != nullptr)
		{
			delete obj;
			obj = nullptr;
		}
	}
	template <typename T>
	COT_API inline void SafeDeleteArray(T*& obj)
	{
		if (obj != nullptr)
		{
			delete[] obj;
			obj = nullptr;
		}
	}
	template <typename T>
	COT_API inline void SafeRelease(T*& obj)
	{
		if (obj != nullptr)
		{
			obj->Release();
			obj = nullptr;
		}
	}
	template <typename T>
	COT_API inline void SafeDestroy(T*& obj)
	{
		if (obj != nullptr)
		{
			obj->Destroy();
			delete obj;
			obj = nullptr;
		}
	}
}