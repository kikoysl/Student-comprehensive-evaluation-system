#include<iostream>
#include<string>S
#include"test.h"
using namespace std;

int main()
{
	int m, n, x;
    string str2[50];

	cout << "请输入两个整数：" << endl;
	cin >> m >> n;
	

	cout << "请输入" << m << "行" << n << "列的位置状态（OXP表示）" << endl;
	for (int i = 0; i < n; i++)
	{
		cin >> str2[i]; //输入字符串
	}

	cout << "请输入病毒传播所经历的周期：" << endl;
	cin >> x;

	fun1(str2, m, n, x);

	system("pause");
	return 0;
}