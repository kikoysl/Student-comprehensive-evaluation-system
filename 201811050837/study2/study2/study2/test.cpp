#include<iostream>
#include"test.h"
using namespace std;
int main()
{
	int a , n, m;
	cout << "��������������m��n������n<m,�����ʽΪ��m n" << endl;
	cin >> m >> n;
	if (n >= m)
	{
		cout << "���벻�ϸ�" << endl;
		return 0;
	}
	cout << endl;

   //����ʹ��������ʵ��
	cout << "����ʵ��" << endl;
	fun1(m, n);

   //ʹ�õ�����ʵ��
	cout << "��ѭ������ʵ��";
	fun2(m, n);



	system("pause");
	return 0;
}