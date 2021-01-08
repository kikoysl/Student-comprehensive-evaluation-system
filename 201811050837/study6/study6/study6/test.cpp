#include<iostream>
#include"test.h"
using namespace std;

int main()
{
	vehicle v(4, 2000);
	car v1(2, 500,2);
	truck v2(4,4000,2,300);
	cout << "vehicle:" << endl;
	v.Output();
	cout << endl << "car:" << endl;
	v1.Output();
	cout << endl << "truck:" << endl;
	v2.Output();

	system("pause");
    return 0;
}