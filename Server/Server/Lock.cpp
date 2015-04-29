#include "Lock.h"


Lock::Lock(CriticalSection* cs) 
	:_cs(cs)
{
	_cs->Lock();
}

Lock::~Lock()
{
	_cs->UnLock();
}
