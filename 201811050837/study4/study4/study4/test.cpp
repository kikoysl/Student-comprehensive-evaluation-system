#include<iostream>
#include<string>S
#include"test.h"
using namespace std;

int main()
{
	int m, n, x;
    string str2[50];

	cout << "����������������" << endl;
	cin >> m >> n;
	

	cout << "������" << m << "��" << n << "�е�λ��״̬��OXP��ʾ��" << endl;
	for (int i = 0; i < n; i++)
	{
		cin >> str2[i]; //�����ַ���
	}

	cout << "�����벡�����������������ڣ�" << endl;
	cin >> x;

	fun1(str2, m, n, x);

	system("pause");
	return 0;
}