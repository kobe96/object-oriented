#include "print.h"

void print::PrintStringQueue(queue<string> result_queue)
{
	sum = result_queue.size();
	for (i = 0; i < sum; i++)
	{
		cout << result_queue.front();
		result_queue.pop();
	}

}

