#include <iostream>
#include <string>
#include <mutex>
#include "./interface/irunnable.h"
#include "./thread/thread_pool.h"
#include "./base/singleton.h"
#include "./interface/idb_connection.h"
#include "./exception/base_exception.h"


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