#pragma once
#include <vector>
#include <mutex>
#include "../base/singleton.h"

namespace std
{
	class thread;
}

class thread_pool : public singleton<thread_pool>
{
public:
	~thread_pool();
	void assign(unsigned int thread_count);
	void fread();
	bool has_idle_thread();
	void push_idle(std::thread* t);
	std::thread* pop_idle();
private:
	thread_pool();
private:
	std::vector<std::thread*> _idle_threads;
	std::vector<std::thread*> _in_use_threads;
	std::mutex _mutex;
};

