#include<string>
#include <fstream>
#include<queue> 
#include<iostream>
using namespace std;
class print
{
public:
	void PrintStringQueue(queue<string>result_queue);
	void OutputResult(double result, string error, string argv);
private:
	int i, sum;
};