#include <assert.h>
#include "Thread.h"


Thread::Thread() :
	_Runnable(nullptr),
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
void Thread::Init(IRunnable *runfuc)
{
	assert(_Runnable == nullptr || runfuc != nullptr);
	_Runnable = runfuc;
	_ThreadHandle = ::CreateThread(NULL, 0, ThreadFunc, this, CREATE_SUSPENDED, nullptr);
}
void Thread::Start()
{
	_IsRunning = true;
	Suspend();
}
void Thread::Suspend()
{
	if (_IsRunning && _ThreadHandle != nullptr)
		::SuspendThread(_ThreadHandle);
}
void Thread::Resume()
{
	if (_IsRunning && _ThreadHandle != nullptr)
		::ResumeThread(_ThreadHandle);
}
void Thread::Stop()
{
	if (!_IsRunning)
		return;

	_IsRunning = false;
	if (::WaitForSingleObject(_ThreadHandle, 3000) == WAIT_TIMEOUT)
	{
		::TerminateThread(_ThreadHandle, 0);
	}
	::CloseHandle(_ThreadHandle);
	_Runnable = nullptr;
	_ThreadHandle = nullptr;
}
DWORD Thread::ThreadFunc(void* p)
{
	Thread* pThread = static_cast<Thread*>(p);
	if (pThread != nullptr)
	{
		while (pThread->_IsRunning)
		{
			IRunnable* runnable = pThread->_Runnable;
			runnable->Run();
		}
	}
	return 0;
}
