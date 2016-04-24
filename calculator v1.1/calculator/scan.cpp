#include"Scan.h"

queue<string>Scan::ToStringQueue(string a)
{


	for (i = 0; i < a.size(); i++)
	{
		if (a[i] > 47 && a[i] < 58 || a[i] == '.')
			b += a[i];
		else
		{
			if (!b.empty())
				result_queue.push(b);

			b.clear();
			b = a[i];

			if (!b.empty())
				result_queue.push(b);
			b.clear();

		}

	}
	if (!b.empty())
	{
		result_queue.push(b);
	}
	return result_queue;
}

