#pragma once
#include <mutex>

class Lock
{
private: 
	std::mutex* _mutex;
public:
	Lock(std::mutex* m);
	~Lock();
	bool trylock();
};

