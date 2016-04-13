#include <iostream>
#include <stack>
#include <string>
#include <queue>
#include <sstream>
using namespace std;
class calculator
{
public:
	stack<double> s1;
	stack<string> s2;
	stack<string> s3;
	stack<string> s4;
	stack<string> s5;
	double read(queue<string>p);
private:
	int i, j = 0, n, c, d;
	double a, e = 0, f;
	string g, output;
	stringstream stream;
	int level(string a);
	double js(double a, double b, string c);
};

