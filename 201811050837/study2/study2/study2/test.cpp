#include<iostream>
#include"test.h"
using namespace std;
int main()
{
	int a , n, m;
	cout << "请输入两个整数m和n，其中n<m,输入格式为：m n" << endl;
	cin >> m >> n;
	if (n >= m)
	{
		cout << "输入不合格。" << endl;
		return 0;
	}
	cout << endl;

   //首先使用数组来实现
	cout << "数组实现" << endl;
	fun1(m, n);

   //使用单链表实现
	cout << "单循环链表实现";
	fun2(m, n);



	system("pause");
	return 0;
}