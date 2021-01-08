#pragma once
#ifndef TEST_H_
#define TEST_H_

typedef struct student {
	int num;
	int chi_sco;
	int eng_sco;
	int mat_sc0;
	int sum;
	struct student *next;
}/*node,*LinkList*/ stu;

int fun1(int);

//void CreatList(LinkList &L, int n);
//void SortList(LinkList &L, int n);


#endif