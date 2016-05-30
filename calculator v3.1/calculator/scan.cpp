#include"Scan.h"

queue<string>Scan::ToStringQueue(string input)
{
	while (!result_queue.empty())
	{
		result_queue.pop();
	}


	for (i = 0; i < input.size(); i++)
	{	if(i >= 1)
		{
		if (input[i] == '-'&&(input[i - 1] == '-' || input[i - 1] == '+' || input[i - 1] == '*' || input[i - 1] == '/'))
		{
			result_queue.push("(");
			midsection = input[i];
			result_queue.push(midsection);
			midsection.clear();
			for (int k = i + 1; k < input.size(); k++)
			{
				if (input[k] > 47 && input[k] < 58 || input[k] == '.')
					midsection += input[k];
				else
				{
					if (!midsection.empty())
						result_queue.push(midsection);

					midsection.clear();
					result_queue.push(")");

					if (!midsection.empty())
						result_queue.push(midsection);
					midsection.clear();
					i = k;
					break;
				}
				i = k+1;
			}
			if (i == input.size())
			{
				if (!midsection.empty())
					result_queue.push(midsection);

				midsection.clear();
				result_queue.push(")");
				break;
			}

			}
		}
	
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

