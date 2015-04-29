#pragma once
#include <windows.h>
#include "IRunnable.h"

class Thread 
{
private:
	bool _IsRunning;
	IRunnable* _Runnable;
	HANDLE _ThreadHandle;
public:
	Thread();
	~Thread();
	void Init(IRunnable *runfuc);
	void Start();
	void Suspend();
	void Resume();
	void Stop();
	inline bool IsRunning() const;
protected:
	static DWORD _stdcall ThreadFunc(void* p);
};

