#ifndef TEST_H_
#define TEST_H_

int fun1(int n, int m);

typedef struct CLinkList //结构体
{
	int data;
	struct CLinkList *next;
}node;

/*void ds_init(node **s); //初始化

void ds_insert(node **s, int i);

void ds_delete(node **s, int i); //删除特定结点*/

int fun2(int, int);


#endif