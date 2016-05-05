// Circle.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include<iostream>
#include"Circle_S.h"
using namespace std;

int main()
{
	Circle_S SQ;		//调用类
	double r, S;
	cin >> r;
	S = SQ.js(r);
	cout << "area = ";
	cout << S;			//输出
	return 0;
}

