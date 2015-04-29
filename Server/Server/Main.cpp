#include <iostream>
#include <string>
#include "IRunnable.h"
#include "Thread.h"
using namespace std;

class Demo : public IRunnable
{
public:
	Demo()
	{
	}

	~Demo()
	{
	}
	void Run()
	{
		cout << "running" << endl;
	}
private:

};


int main(char* argv[], int argc)
{
	Thread t;
	Demo d;
	t.Init(&d);

	long count = GetTickCount();

	t.Start();

	while (getchar() == 'z')
	{
		break;
	}

	t.Stop();

	return 0;
}