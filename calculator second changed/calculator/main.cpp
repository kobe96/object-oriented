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
	double k;
	int i = 0;
	int pd(string str);
	int pdk(string b);
	queue<string>q;
	Scan sc;
	print pr;
	calculator ca;
	string input, input1;
	cout << "������������ʽ:";
	cin >> input;
	if (input[0] == '-'&&input[1] == 'a')
	{
		i = 1;
		cin >> input1;
		input = input1;
	}
	if (i == 1)
	{
		if (pd(input) == 0 && pdk(input) == 0)
		{
			q = sc.ToStringQueue(input);
			k = ca.read(q);
			pr.PrintStringQueue(q);
			cout << "= ";
			cout << k;
		}
		else
		{
			cout << "error" << endl;
		}
	}
	if (i == 0)
	{
		if (pd(input) == 0 && pdk(input) == 0)
		{
			q = sc.ToStringQueue(input);
			k = ca.read(q);
			cout << k << endl;
		}
		else
		{
			cout << "error" << endl;
		}
	}
	return 0;
}

int pd(string str)
{
	int i, j = 0, k = 0;
	for (i = 0; i < str.size(); i++)
	{
		if (str[i] <= '9'&&str[i] >= '0' || str[i] == '.')
		{
			j++;
			if (str[i] == '.')
			{
				k = 1;
			}
			if (k == 1 && j > 11)
			{
				return 1;
				break;
			}
			if (k == 0 && j > 10)
			{
				return 1;
				break;
			}
		}
		else
		{
			j = 0;
		}
	}
	return 0;

}

int pdk(string b)
{
	string a;
	stack<string>p;
	int i, j;
	for (i = 0; i < b.size(); i++)
	{
		if (b[i] == '(')
		{
			a = b[i];
			p.push(a);
			i++;
		}
		if (b[i] == ')')
		{
			if (p.empty())
				return 1;
			else
			{
				p.pop();
				continue;
			}
		}
	}
	if (!p.empty())
		return 1;
	else
		return 0;
}