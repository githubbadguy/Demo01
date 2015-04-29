#include "CriticalSection.h"


CriticalSection::CriticalSection()
{
	::InitializeCriticalSection(&_cs);
}

CriticalSection::~CriticalSection()
{
	::DeleteCriticalSection(&_cs);
}