#pragma once

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

#ifdef COT_EXPORTS
#define COT_API __declspec(dllexport)
#else
#define COT_API __declspec(dllimport)
#endif

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
}