#pragma once
#include "CriticalSection.h"

class Lock
{
private:
	CriticalSection* _cs;
public:
	Lock(CriticalSection* cs);
	~Lock();
};

