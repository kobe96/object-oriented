#include"stdafx.h"
#include "print.h"

void print::PrintStringQueue(queue<CString> result_queue)
{
	sum = result_queue.size();
	for (i = 0; i < sum; i++)
	{
		cout << result_queue.front();
		result_queue.pop();
	}

}

void print::OutputResult(double result, CString error, CString argv)
{

	ofstream out(argv, ios::app);

	if (out.is_open())
	{
		if (error == "")
		{
			if ((int)result == result)
			{
				out << result << endl;
			}
			else
			{
				out.precision(3);
				out << setiosflags(ios::fixed) <<result << endl;
			}
		}
		else
			out << "error" << endl;
	}
	else
	{
		cout << "open fail!" << endl;
	}

	out.close();
}