#include <iostream>
#include <string>
#include "IRunnable.h"
#include "thread_pool.h"
#include "singleton.h"
#include "idb_connection.h"
#include "base_exception.h"
#include <mutex>

using namespace std;



int main(char* argv[], int argc)
{
	base_exception e("message");
	string er = e.what();

	string s;
	cin >> s;
	cout << s;

	return 0;
}