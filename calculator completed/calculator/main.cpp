#include<iostream>
#include<string>
#include<queue>
#include"Scan.h"
#include"print.h"

using namespace std;
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

int main()
{
	queue<string>q;
	Scan sc;
	print pr;
	string input;
	cin >> input;
	if (pd(input) == 0)
	{
		q = sc.ToStringQueue(input);
		pr.PrintStringQueue(q);
	}
	else
	{
		cout << "error" << endl;
	}
	return 0;
}