#ifndef _SINGLETON_H_FILE
#define _SINGLETON_H_FILE
#include "CriticalSection.h"
#include "Lock.h"

template<typename T>
class Singleton
{
private:
	static T* _Instance;
	static CriticalSection _CS;
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
			Lock l(&_CS);
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
CriticalSection Singleton<T>::_CS;


#endif // !_SINGLETON_H_FILE
