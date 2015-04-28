#include "Thread.h"


Thread::Thread() :_IsRunning(false)
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
