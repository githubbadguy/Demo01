#include "Lock.h"


Lock::Lock(std::mutex* m) 
:_mutex(m)
{
	_mutex->lock();
}

Lock::~Lock()
{
	_mutex->unlock();
}

bool Lock::trylock()
{
	return _mutex->try_lock();
}