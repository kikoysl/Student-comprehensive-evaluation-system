#include<iostream>
#include"test.h"
using namespace std;

 vehicle::vehicle(int whe, int wei) //���ι��캯��
{
	 wheels = whe;
	 weight = wei;
	 //cout << "���캯���ѵ��á�" << endl;
}

 vehicle ::~vehicle() //��������
 {
	 cout << "���������ѵ���" << endl;
 }

 void vehicle::Output() //�������
 {
	 cout << "����������Ϊ��" << wheels << "��" << endl;
	 cout << "�����������ǣ�" << weight << "kg" << endl;
 }

 car::car(int whe,int wei,int pas):vehicle(whe,wei),passenger_load(pas){}

 car::~car()
 {
	 cout << "���������ѵ���" << endl;
 }

 void car::Output()
 {
	 vehicle::Output();
	 cout << "���������ǣ�" << passenger_load << "��" << endl;
 }

truck::truck(int whe,int wei,int pas,int pay):vehicle(whe,wei),passenger_load(pas),payload(pay){}

truck::~truck()
{
	cout << "���������ѵ���" << endl;
}

void truck::Output()
{
	vehicle::Output();
	cout << "���������ǣ�" << passenger_load << "��" << endl;
	cout << "���������ǣ�" << payload << "kg" << endl;
}