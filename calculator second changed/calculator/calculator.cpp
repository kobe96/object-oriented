#include"calculator.h"
double read(queue<string>p);
//s5输出串 s3输入串 s4 s5相反的输出串 s2操作符
double calculator::read(queue<string> p)
{
	if (p.front()[0] == '-')
	{
		g = { '0' };
		s3.push(g);
	}

	while (!p.empty())
	{
		if (p.front()[0] == '(')
		{
			g = p.front();
			s3.push(g);
			p.pop();
			if (p.front()[0] == '-')
			{
				g = { '0' };
				s3.push(g);
			}
		}
		else
		{
			g = p.front();
			s3.push(g);
			p.pop();
		}
	}


	while (!s3.empty())
	{
		g = s3.top();
		if (g[0] >= '0'&&g[0] <= '9')
		{
			s4.push(g);
			s3.pop();
		}
		else if (g[0] == ')')
		{
			s2.push(g);
			s3.pop();
		}
		else if (g[0] == '(')
		{
			while (s2.top()[0] != ')')
			{
				s4.push(s2.top());
				s2.pop();
			}
			s2.pop();
			s3.pop();
		}
		else
		{
			if (s2.empty())
			{
				s2.push(g);
				s3.pop();
			}
			else if (s2.top()[0] == ')')
			{
				s2.push(g);
				s3.pop();
			}
			else if (level(g) >= level(s2.top()))
			{
				s2.push(g);
				s3.pop();
			}

			else
			{
				s4.push(s2.top());
				s2.pop();
			}

		}

	}
	while (!s2.empty())
	{
		s4.push(s2.top());
		s2.pop();
	}

	while (!s4.empty())
	{
		s5.push(s4.top());
		s4.pop();
	}
	while (!s5.empty())
	{
		g = s5.top();
		if (g[0] >= '0'&&g[0] <= '9')
		{
			stream << g;
			stream >> a;
			s1.push(a);
			s5.pop();
			stream.clear();
		}
		else
		{
			f = s1.top();
			s1.pop();
			e = js(f, s1.top(), g);
			s1.pop();
			s1.push(e);
			s5.pop();
		}
	}
	return e;
}

int calculator::level(string a)
{
	if (a[0] == '-' || a[0] == '+')
		return 1;
	if (a[0] == '/' || a[0] == '*')
		return 2;
}

double calculator::js(double a, double b, string c)
{
	if (g[0] == '+')
		return a + b;
	if (g[0] == '-')
		return a - b;
	if (g[0] == '*')
		return a*b;
	if (g[0] == '/')
		return a / b;

	return 0.0;
}
