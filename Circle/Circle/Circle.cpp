// Circle.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"
#include<iostream>
#include"Circle_S.h"
using namespace std;

int main()
{
	Circle_S SQ;		//������
	double r, S;
	cin >> r;
	S = SQ.js(r);
	cout << "area = ";
	cout << S;			//���
	return 0;
}

