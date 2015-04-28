#ifndef _RUNNABLE_INTERFACE_H_FILE
#define _RUNNABLE_INTERFACE_H_FILE
struct IRunnable
{
	virtual void Run(void* p = nullptr) = 0;
};
#endif