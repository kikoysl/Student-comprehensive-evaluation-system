#include"head.h"
#include<iostream>
using namespace std;


int fun1(int a, int b) //����ֵ��ʽ
{
	int c;
	c = a / 10 * 10 + a % 10 * 1000 + b / 10 + b % 10 * 100;
	return c;
}

void fun2(int &x, int &y) //���ô���
{
	int a ,b, c;
	a = x;
	b = y;
	c = a / 10 * 10 + a % 10 * 1000 + b / 10 + b % 10 * 100;
	cout << "���ɵ�����Ϊ��" << c << endl;
}

void fun3(int *a, int *b)
{
	int c;
	c = *a / 10 * 10 + *a % 10 * 1000 + *b / 10 + *b %10 * 100;
	cout << "���ɵ�����Ϊ��" << c << endl;
}