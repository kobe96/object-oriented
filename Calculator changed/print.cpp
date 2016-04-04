#include "print.h"
using namespace std;

void print::PrintStringQueue (queue<string> result_queue)
	{
		while (result_queue.size() > 0)
		{
			cout << result_queue.front() << endl;
			result_queue.pop();
		}	
	}

