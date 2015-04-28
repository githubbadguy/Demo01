#ifndef _SINGLETON_H_FILE
#define _SINGLETON_H_FILE
#include "CriticalSection.h"

template<typename T>
class Singleton : CriticalSection
{
private:
	Singleton(){};
	static T* _Instance;

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
public:
	virtual ~Singleton(){};
	static T* GetInstance()
	{
		if (_Instance == nullptr)
		{
			Lock(this);
			if (_Instance == nullptr)
			{
				_Instance = new T();
			}
		}

		return _Instance;
	}
};

template <typename T>
T Singleton<T>::_Instance = nullptr;


#endif // !_SINGLETON_H_FILE
