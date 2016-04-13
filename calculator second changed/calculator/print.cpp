#include "print.h"

void print::PrintStringQueue(queue<string> result_queue)
{
	a = result_queue.size();
	for (i = 0; i < a; i++)
	{
		cout << result_queue.front();
		result_queue.pop();
	}

}

