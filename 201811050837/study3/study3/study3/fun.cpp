#include"test.h"
#include<iostream>
#define N 55
using namespace std;
int m , n, t;
int k = 1;
int j = 0;
int fun1(int n)
{
	stu a[N],max,temp;
	cout << "������" << n << "��ѧ�������ġ���ѧ��Ӣ��ɼ����м��ÿո�տ�" << endl;
	for (int i = 0; i < n; i++)
	{
		a[i].num= i + 1;
		cin >> a[i].chi_sco >> a[i].eng_sco >> a[i].mat_sc0;
        a[i].sum = a[i].chi_sco + a[i].eng_sco + a[i].mat_sc0;
	}
	if(--k==0)
		cout << endl;
	for (int i = 0; i < n-1; i++)
	{
		t = i;
		for (j = i+1; j < n; j++)
		{
			if (a[t].sum < a[j].sum)
			{
				t = j;
			}
			else if (a[t].sum == a[j].sum) //�ܷ���ͬ
			{
				if (a[t].chi_sco < a[j].chi_sco)
				{
					t = j;
				}
				else if (a[t].chi_sco == a[j].chi_sco) //���ĳɼ���ͬ
				{
					if (a[t].num > a[j].num)
					{
						t = j;
					}
				}
			}
		}
		temp = a[i];
		a[i] = a[t];
		a[t] = temp;
	}
	for (int i = 0; i < 5; i++)
	{
		cout << a[i].num << " " << a[i].sum << endl;
	}
	return 0;
}

/*void CreatList(LinkList &L,int n) //����������
{
	LinkList p, r;
	L = new node;
	L->next = NULL;
	cout << "������" << n << "��ѧ�������ġ���ѧ��Ӣ��ɼ����м��ÿո�տ�" << endl;
	for (int i = 0; i < n; i++)
	{
		p = new node;
		p->num = i + 1;
		cin >> p->chi_sco >> p->mat_sc0 >> p->eng_sco;
		p->next = L->next;
		L->next = p;
	}
}


void SortList(LinkList &L, int n)
{
	LinkList p, q, max;
	int temp;
	p = new node;
	p = L->next;
	for (int i = 0; i < n; i++)
	{
		p->sum = p->chi_sco + p->eng_sco + p->mat_sc0;
		p = p->next;
	}
	for (p = L->next; p->next != NULL; p = p->next)  //ѡ������
	{
		max = p;
		for (q = p->next; q; q = q->next)
		{
			if (q->sum > max->sum)
			{
				max = q;
			}
			else if (max->sum = q->sum) //�ܷ���ͬ
			{
				if (q->chi_sco > max->chi_sco)
				{
					max = q;
				}
				else if (q->chi_sco = max->chi_sco) //���ĳɼ���ͬ
				{
					if (q->num < max->num)
					{
						max = q;
					}
				}
			}
		}
		/*if (max != p)
		{
				temp = p;
				p = max;
				max = temp;

		}*

		if (--k == 0)
			cout << n << endl;
		if (--j >= 0)
		{
			cout /*<< "���������£�"<< endl * << max->num << " " << max->sum << endl;
		}

	}
}*/
