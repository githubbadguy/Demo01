#include "Thread.h"


Thread::Thread() :
	_ThreadHandle(nullptr),
	_IsRunning(false)
{
}
Thread::~Thread()
{
}
inline bool Thread::IsRunning() const
{
	return _IsRunning;
}
void Thread::Start(IRunnable *runfuc)
{
	_ThreadHandle = ::CreateThread(NULL, 0, NULL, NULL, CREATE_SUSPENDED, &_ThreadID);
}
void Thread::Suspend()
{

}
void Thread::Resume()
{

}
void Thread::Stop()
{

}
