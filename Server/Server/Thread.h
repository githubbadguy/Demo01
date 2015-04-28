#pragma once
#include "IRunnable.h"

class Thread 
{
public:
	Thread();
	~Thread();
	void Start(IRunnable *runfuc);
	void Suspend();
	void Resume();
	void Stop();
};

