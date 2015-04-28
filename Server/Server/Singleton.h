#ifndef _SINGLETON_H_FILE
#define _SINGLETON_H_FILE

template<typename T>
class Singleton
{
private:
	static T* _Instance;
	static MyClass _Harmonior;
public:
	virtual ~Singleton(){};
	static T* GetInstance()
	{
		if (_Instance == nullptr)
		{
			_Instance = new T();
		}

		return _Instance;
	}

	class MyClass
	{
	public:
		~MyClass()
		{
			if (_Instance != nullptr)
				delete _Instance;

			_Instance = nullptr;
		}
	};
};

template <typename T>
T Singleton<T>::_Instance = nullptr;

template<typename T>
Singleton<T>::MyClass Singleton<T>::_Harmonior;

#endif // !_SINGLETON_H_FILE
