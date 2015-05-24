#ifndef _SINGLETON_H_FILE
#define _SINGLETON_H_FILE
#include <mutex>
#include "CriticalSection.h"
#include "Lock.h"

template<typename T>
class Singleton
{
private:
	static T* _Instance;
	static std::mutex _mutex;
	class MyClass
	{
	public:
		~MyClass()
		{
			if (Singleton<T>::_Instance != nullptr)
				delete Singleton<T>::_Instance;

			Singleton<T>::_Instance = nullptr;
		}
	};
	static MyClass _Harmonior;
protected:
	Singleton(){};
public:
	virtual ~Singleton(){};
	static T* GetInstance()
	{
		if (_Instance == nullptr)
		{
			Lock l(&_mutex);
			if (_Instance == nullptr)
			{
				_Instance = new T();
			}
		}

		return _Instance;
	}
};

template <typename T>
T* Singleton<T>::_Instance = nullptr;

template <typename T>
std::mutex Singleton<T>::_mutex;

#endif // !_SINGLETON_H_FILE
