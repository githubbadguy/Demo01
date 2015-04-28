#pragma once
#include "IRunnable.h"

class Thread 
{
private:
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

