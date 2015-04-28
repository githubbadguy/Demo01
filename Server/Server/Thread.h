#pragma once
#include <windows.h>
#include "IRunnable.h"

class Thread 
{
private:
	HANDLE _ThreadHandle;
	DWORD _ThreadID;
	bool _IsRunning;
public:
	Thread();
	~Thread();
	void Start(IRunnable *runfuc);
	void Suspend();
	void Resume();
	void Stop();
	inline bool IsRunning() const;
};

