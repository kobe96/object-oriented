#include <fstream> 
#include<iostream>
#include<string>
#include<queue>
#include<stack>
#include"Scan.h"
#include"print.h"
#include"calculator.h"

using namespace std;

int main(int argc, char* argv[])
{
	int pdinput = 0;
	double result;
	int pdlenth = 0;
	int pd(string str);
	int pdk(string input);
	queue<string>midsection;
	Scan sc;
	print pr;
	calculator ca;
	string input, input1, error;

	if (argc == 4 && argv[1][0] == '-' && argv[1][1] == 'f')
	{
		ifstream in;
		in.open(argv[2]);


		while (!in.eof())
		{
			getline(in, input);

			if (pd(input) == 0 && pdk(input) == 0 && input != "")
			{
				midsection = sc.ToStringQueue(input);
				result = ca.read(midsection);
				pr.OutputResult(result, error, argv[3]);
			}
			else if (input == "")
			{
				continue;
			}
			else
			{
				result = 0;
				error = "error";
				pr.OutputResult(result, error, argv[3]);
			}
			error = "";
			input = "";
			while (!midsection.empty())
			{
				midsection.pop();
			}
		}
		return 0;
	}

	else
	{
		if (argc < 2)
		{
			pdinput = 1;
		}
		if (pdinput == 0)
		{
			if (argc == 3 && argv[1][0] == '-'&&argv[1][1] == 'a')
			{
				pdlenth = 1;
				input = argv[2];
			}
			else
				input = argv[1];
		}
		else
		{
			cin >> input1;
			if (input1[0] == '-'&&input1[1] == 'a')
			{
				cin >> input;
				pdlenth = 1;
			}
			else
			{
				input = input1;
			}
		}

		if (pdlenth == 1)
		{
			if (pd(input) == 0 && pdk(input) == 0)
			{
				midsection = sc.ToStringQueue(input);
				result = ca.read(midsection);
				pr.PrintStringQueue(midsection);
				cout << "= ";
				cout << result << endl;

			}
			else
			{
				cout << "error" << endl;
			}
		}
		if (pdlenth == 0)
		{
			if (pd(input) == 0 && pdk(input) == 0)
			{
				midsection = sc.ToStringQueue(input);
				result = ca.read(midsection);
				cout << result << endl;
			}
			else
			{
				cout << "error" << endl;
			}
		}
		return 0;
	}
}

int pd(string str)
{
	int i, pds = 0, pdd = 0;
	for (i = 0; i < str.size(); i++)
	{
		if (str[i] <= '9'&&str[i] >= '0' || str[i] == '.')
		{
			pds++;
			if (str[i] == '.')
			{
				pdd = 1;
			}
			if (pdd == 1 && pds > 11)
			{
				return 1;
				break;
			}
			if (pdd == 0 && pds > 10)
			{
				return 1;
				break;
			}
		}
		else
		{
			pds = 0;
		}
	}
	return 0;

}

int pdk(string input)
{
	string midsection;
	stack<string>brackets;
	int i;
	for (i = 0; i < input.size(); i++)
	{
		if (input[i] == '(')
		{
			midsection = input[i];
			brackets.push(midsection);
			i++;
		}
		if (input[i] == ')')
		{
			if (brackets.empty())
				return 0;
			else
			{
				brackets.pop();
				continue;
			}
		}
	}
	if (!brackets.empty())
		return 1;
	else
		return 0;
}