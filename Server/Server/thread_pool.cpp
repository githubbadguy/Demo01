#include <thread>
#include "thread_pool.h"
#include <stack>

using namespace std;

thread_pool::thread_pool() :
_in_use_threads(),
_idle_threads(),
_mutex()
{

}

thread_pool::~thread_pool()
{

}

void thread_pool::assign(unsigned int thread_count)
{
	lock_guard<mutex> lck(_mutex);
	_idle_threads.assign(thread_count,nullptr);
	_in_use_threads.assign(thread_count, nullptr);
	for (int i = 0; i < thread_count;i++)
	{
		thread* thr = new thread();
		_idle_threads[i] = thr;
	}
}

void thread_pool::fread()
{
	
}

bool thread_pool::has_idle_thread()
{
	return !_idle_threads.empty();
}

void thread_pool::push_idle(thread* t)
{
	stack<thread*> st;
}

thread* thread_pool::pop_idle()
{
	return nullptr;
}
