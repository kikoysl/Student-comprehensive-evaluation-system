#include<iostream>
#include"test.h"
using namespace std;

 vehicle::vehicle(int whe, int wei) //含参构造函数
{
	 wheels = whe;
	 weight = wei;
	 //cout << "构造函数已调用。" << endl;
}

 vehicle ::~vehicle() //析构函数
 {
	 cout << "析构函数已调用" << endl;
 }

 void vehicle::Output() //输出函数
 {
	 cout << "汽车的轮子为：" << wheels << "个" << endl;
	 cout << "汽车的重量是：" << weight << "kg" << endl;
 }

 car::car(int whe,int wei,int pas):vehicle(whe,wei),passenger_load(pas){}

 car::~car()
 {
	 cout << "析构函数已调用" << endl;
 }

 void car::Output()
 {
	 vehicle::Output();
	 cout << "核载人数是：" << passenger_load << "人" << endl;
 }

truck::truck(int whe,int wei,int pas,int pay):vehicle(whe,wei),passenger_load(pas),payload(pay){}

truck::~truck()
{
	cout << "析构函数已调用" << endl;
}

void truck::Output()
{
	vehicle::Output();
	cout << "核载人数是：" << passenger_load << "人" << endl;
	cout << "核载重量是：" << payload << "kg" << endl;
}