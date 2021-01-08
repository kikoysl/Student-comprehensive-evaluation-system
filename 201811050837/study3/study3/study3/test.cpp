#include<iostream>
#include"test.h"
using namespace std;
int main()
{
	int n , sum;
	int chi, eng, mat;
	cout << "请输入学生总数：" << endl;
	cin >> n;

	/*LinkList L;
	CreatList(L, n);
	SortList(L, n);*/

	fun1(n);

	system("pause");
	return 0;
}