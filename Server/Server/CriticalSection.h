#pragma once
#include <windows.h>

class CriticalSection
{
private:
	CRITICAL_SECTION _cs;
public:
	CriticalSection();
	virtual ~CriticalSection();
	inline void Lock()
	{
		::EnterCriticalSection(&_cs);
	}
	inline bool TryLock()
	{
		return (::TryEnterCriticalSection(&_cs) ? true : false);
	}
	inline void UnLock()
	{
		::LeaveCriticalSection(&_cs);
	}
};

