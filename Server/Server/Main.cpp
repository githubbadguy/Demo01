#include <iostream>
#include <string>
#include "IRunnable.h"
#include "Thread.h"
#include "singleton.h"
#include "IDBConnection.h"
#include "exception.h"
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