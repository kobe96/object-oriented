#include"Scan.h"

queue<string>Scan::ToStringQueue(string input)
{
	while (!result_queue.empty())
	{
		result_queue.pop();
	}


	for (i = 0; i < input.size(); i++)
	{
		if (input[i] > 47 && input[i] < 58 || input[i] == '.')
			midsection += input[i];
		else
		{
			if (!midsection.empty())
				result_queue.push(midsection);

			midsection.clear();
			midsection = input[i];

			if (!midsection.empty())
				result_queue.push(midsection);
			midsection.clear();

		}

	}
	if (!midsection.empty())
	{
		result_queue.push(midsection);
	}
	input.clear();
	midsection.clear();
	return result_queue;
}

