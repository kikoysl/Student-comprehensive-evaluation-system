#include<iostream>
#include<string>
#include"test.h"
using namespace std;

int fun1(string str2[50], int m, int n, int x)
{
	int a[100][100];
	for (int k = 0; k < x; k++) //周期
	{
		for (int i = 0; i < m; i++)
		{
			for (int j = 0; j < n; j++) //遍历
			{
				if (str2[i][j] == 'X')
				{
					a[i][j] = 1; //计数 
				}
			}
		}
		for (int i = 0; i < m; i++)
		{
			for (int j = 0; j < n; j++)
			{
				if (a[i][j] == 1)
				{
					if (i == 0 && j == 0 && str2[i][j + 1] != 'P'&& str2[i + 1][j] != 'P')
					{
						str2[i][j + 1] = 'X'; str2[i + 1][j] = 'X';
					}
					else if (i == 0 && j == 0 && str2[i][j + 1] != 'P')
					{
						str2[i + 1][j] = 'X';
					}
					else if (i == 0 && j == 0 && str2[i + 1][j] != 'P')
					{
						str2[i][j + 1] = 'X';
					}
					else if (i != 0 && j == 0 && str2[i][j + 1] != 'P' && str2[i + 1][j] != 'P' && str2[i - 1][j] != 'P')
					{
						str2[i][j + 1] = 'X'; str2[i + 1][j] = 'X'; str2[i - 1][j] = 'X';
					}
					else if (i != 0 && j == 0 && str2[i][j + 1] != 'P'&& str2[i + 1][j] != 'P')
					{
						str2[i][j + 1] = 'X'; str2[i + 1][j] = 'X';
					}
					else if (i != 0 && j == 0 && str2[i][j + 1] != 'P')
					{
						str2[i][j + 1] = 'X';
					}
					else if (i != 0 && j == 0 && str2[i + 1][j] != 'P' && str2[i - 1][j] != 'P')
					{
						str2[i + 1][j] = 'X'; str2[i - 1][j] = 'X';
					}
					else if (i != 0 && j == 0 && str2[i + 1][j] != 'P')
					{
						str2[i + 1][j] = 'X';
					}
					else if (i != 0 && j == 0 && str2[i][j + 1] != 'P' && str2[i - 1][j] != 'P')
					{
						str2[i][j + 1] = 'X'; str2[i - 1][j] = 'X';
					}
					else if (i != 0 && j == 0 && str2[i - 1][j] != 'P')
					{
						str2[i - 1][j] = 'X';
					}
					else if (i == 0 && j != 0 && str2[i][j + 1] != 'P' && str2[i + 1][j] != 'P' && str2[i][j - 1] != 'P')
					{
						str2[i][j + 1] = 'X'; str2[i + 1][j] = 'X'; str2[i][j - 1] = 'X';
					}
					else if (i == 0 && j != 0 && str2[i][j + 1] != 'P'&& str2[i + 1][j] != 'P')
					{
						str2[i][j + 1] = 'X'; str2[i + 1][j] = 'X';
					}
					else if (i == 0 && j != 0 && str2[i][j + 1] != 'P')
					{
						str2[i][j + 1] = 'X';
					}
					else if (i == 0 && j != 0 && str2[i + 1][j] != 'P' && str2[i][j - 1] != 'P')
					{
						str2[i + 1][j] = 'X'; str2[i][j - 1] = 'X';
					}
					else if (i == 0 && j != 0 && str2[i + 1][j] != 'P')
					{
						str2[i + 1][j] = 'X';
					}
					else if (i == 0 && j != 0 && str2[i][j + 1] != 'P' && str2[i][j - 1] != 'P')
					{
						str2[i][j + 1] = 'X'; str2[i][j - 1] = 'X';
					}
					else if (i == 0 && j != 0 && str2[i][j - 1] != 'P')
					{
						str2[i][j - 1] = 'X';
					}
					else if (i != 0 && j != 0 && str2[i][j + 1] != 'P' && str2[i + 1][j] != 'P' && str2[i - 1][j] != 'P' && str2[i][j - 1] != 'P')
					{
						str2[i][j + 1] = 'X'; str2[i + 1][j] = 'X'; str2[i - 1][j] = 'X'; str2[i][j - 1] = 'X';
					}
					else if (i != 0 && j != 0 && str2[i][j + 1] != 'P' && str2[i + 1][j] != 'P' && str2[i - 1][j] != 'P')
					{
						str2[i][j + 1] = 'X'; str2[i + 1][j] = 'X'; str2[i - 1][j] = 'X';
					}
					else if (i != 0 && j != 0 && str2[i][j + 1] != 'P' && str2[i + 1][j] != 'P' && str2[i][j - 1] != 'P')
					{
						str2[i][j + 1] = 'X'; str2[i + 1][j] = 'X'; str2[i][j - 1] = 'X';
					}
					else if (i != 0 && j != 0 && str2[i][j + 1] != 'P' && str2[i - 1][j] != 'P' && str2[i][j - 1] != 'P')
					{
						str2[i][j + 1] = 'X'; str2[i - 1][j] = 'X'; str2[i][j - 1] = 'X';
					}
					else if (i != 0 && j != 0 && str2[i + 1][j] != 'P' && str2[i - 1][j] != 'P' && str2[i][j - 1] != 'P')
					{
						str2[i + 1][j] = 'X'; str2[i - 1][j] = 'X'; str2[i][j - 1] = 'X';
					}
					else if (i != 0 && j != 0 && str2[i][j + 1] != 'P', str2[i - 1][j] != 'P')
					{
						str2[i][j + 1] = 'X'; str2[i - 1][j] = 'X';
					}
					else if (i != 0 && j != 0 && str2[i][j + 1] != 'P', str2[i + 1][j] != 'P')
					{
						str2[i][j + 1] = 'X'; str2[i + 1][j] = 'X';
					}
					else if (i != 0 && j != 0 && str2[i][j + 1] != 'P', str2[i][j - 1] != 'P')
					{
						str2[i][j + 1] = 'X'; str2[i][j - 1] = 'X';
					}
					else if (i != 0 && j != 0 && str2[i - 1][j] != 'P', str2[i][j - 1] != 'P')
					{
						str2[i - 1][j] = 'X'; str2[i][j - 1] = 'X';
					}
					else if (i != 0 && j != 0 && str2[i - 1][j] != 'P', str2[i + 1][j] != 'P')
					{
						str2[i - 1][j] = 'X'; str2[i + 1][j] = 'X';
					}
					else if (i != 0 && j != 0 && str2[i][j - 1] != 'P', str2[i + 1][j] != 'P')
					{
						str2[i][j - 1] = 'X'; str2[i + 1][j] = 'X';
					}
					else if (i != 0 && j != 0 && str2[i][j + 1] != 'P')
					{
						str2[i][j + 1] = 'X';
					}
					else if (i != 0 && j != 0 && str2[i][j - 1] != 'P')
					{
						str2[i + 1][j + 1] = 'X';
					}
					else if (i != 0 && j != 0 && str2[i - 1][j] != 'P')
					{
						str2[i - 1][j] = 'X';
					}
					else if (i != 0 && j != 0 && str2[i + 1][j] != 'P')
					{
						str2[i + 1][j] = 'X';
					}
				}
			}
		}

	}
	for (int i = 0; i < n; i++)
	{
		cout << str2[i] << endl;
	}
	return 0;
}

