#include"head.h"
#include<iostream>
using namespace std;


int fun1(int a, int b) //返回值形式
{
	int c;
	c = a / 10 * 10 + a % 10 * 1000 + b / 10 + b % 10 * 100;
	return c;
}

void fun2(int &x, int &y) //引用传参
{
	int a ,b, c;
	a = x;
	b = y;
	c = a / 10 * 10 + a % 10 * 1000 + b / 10 + b % 10 * 100;
	cout << "生成的新数为：" << c << endl;
}

void fun3(int *a, int *b)
{
	int c;
	c = *a / 10 * 10 + *a % 10 * 1000 + *b / 10 + *b %10 * 100;
	cout << "生成的新数为：" << c << endl;
}