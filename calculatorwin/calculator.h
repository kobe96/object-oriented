#include"stdafx.h"
#include <iostream>
#include <stack>
#include <string>
#include <queue>
#include <sstream>
using namespace std;
class calculator
{
public:
	stack<double> num;
	stack<CString> operators;
	stack<CString> input;
	stack<CString> Oppositeoutput;
	stack<CString> output;
	double read(queue<CString>inputfrommain);
private:
	double number, result = 0, firstnum;
	CString strinput;
	stringstream stream;
	int level(CString priority);
	double js(double firstnum, double secondnum, CString operators);
};

