#include <iostream>
#include <string>
#include "IRunnable.h"
#include "Thread.h"
#include "Singleton.h"
#include "IDBConnection.h"
#include "Exception.h"
#include <mutex>

using namespace std;



int main(char* argv[], int argc)
{
	Exception e("message");
	string er = e.What();

	string s;
	cin >> s;
	cout << s;

	return 0;
}