#ifndef _SINGLETON_H_FILE
#define _SINGLETON_H_FILE
#include <mutex>

template<typename T>
class singleton
{
private:
	static T* _instance;
	static std::mutex _mutex;
	class my_class
	{
	public:
		~my_class()
		{
			if (singleton<T>::_instance != nullptr)
				delete singleton<T>::_instance;

			singleton<T>::_instance = nullptr;
		}
	};
	static my_class harmonior;
protected:
	singleton(){};
public:
	virtual ~singleton(){};
	static T* get_instance()
	{
		if (_instance == nullptr)
		{
			std::lock_guard<std::mutex> l(_mutex);
			if (_instance == nullptr)
			{
				_instance = new T();
			}
		}
		return _instance;
	}
};

template <typename T>
T* singleton<T>::_instance = nullptr;

template <typename T>
std::mutex singleton<T>::_mutex;

#endif // !_SINGLETON_H_FILE
