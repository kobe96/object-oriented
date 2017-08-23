#include"stdafx.h"
#include<string>
#include <fstream>
#include<queue> 
#include<iostream>
#include<sstream>
#include<iomanip>
using namespace std;
class print
{
public:
	void PrintStringQueue(queue<CString>result_queue);
	void OutputResult(double result, CString error, CString argv);
private:
	int i, sum;
};