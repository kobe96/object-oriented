#include"stdafx.h"
#include"calculator.h"

double calculator::read(queue<CString> inputfrommain)
{
	if (inputfrommain.front()[0] == '-'|| inputfrommain.front()[0] == '+')
	{
		strinput = { '0' };
		input.push(strinput);
	}

	while (!inputfrommain.empty())
	{
		if (inputfrommain.front()[0] == '(')
		{
			strinput = inputfrommain.front();
			input.push(strinput);
			inputfrommain.pop();
			if (inputfrommain.front()[0] == '-' || inputfrommain.front()[0] == '+')
			{
				strinput = { '0' };
				input.push(strinput);
			}
		}
		else
		{
			strinput = inputfrommain.front();
			input.push(strinput);
			inputfrommain.pop();
		}
	}


	while (!input.empty())
	{
		strinput = input.top();
		if (strinput[0] >= '0'&&strinput[0] <= '9')
		{
			Oppositeoutput.push(strinput);
			input.pop();
		}
		else if (strinput[0] == ')')
		{
			operators.push(strinput);
			input.pop();
		}
		else if (strinput[0] == '(')
		{
			while (operators.top()[0] != ')')
			{
				Oppositeoutput.push(operators.top());
				operators.pop();
			}
			operators.pop();
			input.pop();
		}
		else
		{
			if (operators.empty())
			{
				operators.push(strinput);
				input.pop();
			}
			else if (operators.top()[0] == ')')
			{
				operators.push(strinput);
				input.pop();
			}
			else if (level(strinput) >= level(operators.top()))
			{
				operators.push(strinput);
				input.pop();
			}

			else
			{
				Oppositeoutput.push(operators.top());
				operators.pop();
			}

		}

	}
	while (!operators.empty())
	{
		Oppositeoutput.push(operators.top());
		operators.pop();
	}

	while (!Oppositeoutput.empty())
	{
		output.push(Oppositeoutput.top());
		Oppositeoutput.pop();
	}
	while (!output.empty())
	{
		strinput = output.top();
		if (strinput[0] >= '0'&&strinput[0] <= '9')
		{
			stream << strinput;
			stream >> number;
			num.push(number);
			output.pop();
			stream.clear();
		}
		else
		{
			firstnum = num.top();
			num.pop();
			result = js(firstnum, num.top(), strinput);
			num.pop();
			num.push(result);
			output.pop();
		}
	}
	while (!operators.empty())
	{
		operators.pop();
	}
	while (!input.empty())
	{
		input.pop();
	}
	while (!Oppositeoutput.empty())
	{
		Oppositeoutput.pop();
	}
	while (!output.empty())
	{
		output.pop();
	}
	while (!inputfrommain.empty())
	{
		inputfrommain.pop();
	}
	while (!num.empty())
	{
		num.pop();
	}


	return result;
}

int calculator::level(CString priority)
{
	if (priority[0] == '-' || priority[0] == '+')
		return 1;
	if (priority[0] == '/' || priority[0] == '*')
		return 2;
}

double calculator::js(double firstnum, double secondnum, CString operators)
{
	if (strinput[0] == '+')
		return firstnum + secondnum;
	if (strinput[0] == '-')
		return firstnum - secondnum;
	if (strinput[0] == '*')
		return firstnum * secondnum;
	if (strinput[0] == '/')
		return firstnum / secondnum;

	return 0.0;
}
