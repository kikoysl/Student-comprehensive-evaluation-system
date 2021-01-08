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
			if (j == m) //数组循环
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
			cout << "猴子大王是：" << i << "号 " << endl << endl;
			return 0;
		}
	}
	return 0;

}
/*//< 初始化单向循环链表
void ds_init(node **pNode)
{
	int item;
	node *temp;
	node *target;

	printf("初始化单向循环链表\n");

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
			//< 指定链表为0，也要对链表进行初始化
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

void ds_delete(node **pNode, int i) //删除特定结点
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

void ds_insert(node **pNode, int i) //插入数据
{
	node *temp;
	node *target;
	node *p;
	int item;
	int j = 1;

	printf("向链表中插入数据:");
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
	}//建立一个不带头结点的单链表
	q->next = head;//形成单循环链表
	q = head;
	while (q->next != head)
	{
		q = q->next;
	}
	q = head;
	cout << endl;
	do {
		count++;//计数
		if (count == n - 1)
		{
			t = q->next;
			q->next = t->next;//到n前面那个节点stop，然后删除第n个节点
			count = 0;//循环复位
			free(t);//释放内存
		q = q->next;
	}
	while (q->next != q);//判断是否只剩一个
	cout << "猴子大王是：" << q->data << "号" << endl;
	return 0;
}