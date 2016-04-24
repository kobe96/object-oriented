#include"Scan.h"

queue<string>Scan::ToStringQueue(string input)
{


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
	return result_queue;
}

