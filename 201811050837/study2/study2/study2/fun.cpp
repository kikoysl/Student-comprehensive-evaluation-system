#include<iostream>
#include"test.h"
#include <stdlib.h>
#define N 100
using namespace std;
int a[N],k,j=0;

int fun1(int m, int n)
{
	 

	for (int i = 1; i <= m - 1; i++)
	{
		k = 0;
		while (k < n)
		{
			if (j == m) //����ѭ��
				j = 0;
			j++;
			if (a[j] == 0)
				k++;
		}
		a[j] = 1;
	}
	for (int i = 1; i <= m; i++)
	{
		if (a[i] == 0)
		{
			cout << "���Ӵ����ǣ�" << i << "�� " << endl << endl;
			return 0;
		}
	}
	return 0;

}
/*//< ��ʼ������ѭ������
void ds_init(node **pNode)
{
	int item;
	node *temp;
	node *target;

	printf("��ʼ������ѭ������\n");

	while (1)
	{
		cin >> item;
		fflush(stdin);
		printf("item = %d\n\n", item);
		if (item == 0)
			return;


		if ((*pNode) == NULL)
		{

			*pNode = (node*)malloc(sizeof(struct CLinkList));
			if (!(*pNode))
				exit(0);
			(*pNode)->data = item;
			(*pNode)->next = *pNode;
		}
		else
		{
			//< ָ������Ϊ0��ҲҪ��������г�ʼ��
			for (target = (*pNode); target->next != (*pNode); target = target->next)
				;


			temp = (node *)malloc(sizeof(struct CLinkList));

			if (!temp)
				exit(0);

			temp->data = item;
			temp->next = *pNode;
			target->next = temp;
		}
	}
}

void ds_delete(node **pNode, int i) //ɾ���ض����
{
	node *target;
	node *temp;
	int j = 1;

	if (i == 1)
	{
		for (target = *pNode; target->next != *pNode; target = target->next)
			;

		temp = *pNode;
		*pNode = (*pNode)->next;
		target->next = *pNode;
		free(temp);
	}
	else
	{
		target = *pNode;

		for (; j < i - 1; ++j)
		{
			target = target->next;
		}

		temp = target->next;
		target->next = temp->next;
		free(temp);
	}
}

void ds_insert(node **pNode, int i) //��������
{
	node *temp;
	node *target;
	node *p;
	int item;
	int j = 1;

	printf("�������в�������:");
	cin >> item;

	if (i == 1)
	{
		temp = (node *)malloc(sizeof(struct CLinkList));

		if (!temp)
			exit(0);

		temp->data = item;


		for (target = (*pNode); target->next != (*pNode); target = target->next)
			;

		temp->next = (*pNode);
		target->next = temp;
		*pNode = temp;
	}
	else
	{
		target = *pNode;

		for (; j < (i - 1); ++j)
		{
			target = target->next;
		}

		temp = (node *)malloc(sizeof(struct CLinkList));

		if (!temp)
			exit(0);

		temp->data = item;
		p = target->next;
		target->next = temp;
		temp->next = p;
	}
}
*/


int fun2(int m,int n)
{
	int count = 0, i;
	struct CLinkList *head = NULL, *s, *q = NULL, *t;
	for (i = 0; i < m; i++)

	{
		s = (struct CLinkList *)malloc(sizeof(struct CLinkList));

		s->data = i + 1;

		s->next = NULL;

		if (i == 0)
		{
			head = s;
			q = head;
		}
		else
		{
			q->next = s;
			q = q->next;
		}
	}//����һ������ͷ���ĵ�����
	q->next = head;//�γɵ�ѭ������
	q = head;
	while (q->next != head)
	{
		q = q->next;
	}
	q = head;
	cout << endl;
	do {
		count++;//����
		if (count == n - 1)
		{
			t = q->next;
			q->next = t->next;//��nǰ���Ǹ��ڵ�stop��Ȼ��ɾ����n���ڵ�
			count = 0;//ѭ����λ
			free(t);//�ͷ��ڴ�
		q = q->next;
	}
	while (q->next != q);//�ж��Ƿ�ֻʣһ��
	cout << "���Ӵ����ǣ�" << q->data << "��" << endl;
	return 0;
}