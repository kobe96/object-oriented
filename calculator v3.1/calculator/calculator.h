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
	stack<string> operators;
	stack<string> input;
	stack<string> Oppositeoutput;
	stack<string> output;
	double read(queue<string>inputfrommain);
private:
	double number, result = 0, firstnum;
	string strinput;
	stringstream stream;
	int level(string priority);
	double js(double firstnum, double secondnum, string operators);
};

