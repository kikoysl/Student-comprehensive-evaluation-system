#include "calculator.h"
#include <stdio.h>
#include<stdlib.h>

bool isOperator(char x)
{
	if (x == '(' || x == ')' || x == '+' || x == '-' || x == '*' || x == '/')
		return true;
	else
		return false;
}
int getPriority(char x)
{
	if (x == '+' || x == '-')
		return 1;
	if (x == '*' || x == '/')
		return 2;
	if (x == '(')
		return 0;
}
bool isBracket(char x)
{
	if (x == '(' || x == ')')
		return true;
	else
		return false;
}
int doOperate(int d1, int d2, char t)
{
	//cout<<d1<<" "<<t<<" "<<d2<<endl;
	if (t == '+')
		return (d1 + d2);
	if (t == '-')
		return (d1 - d2);
	if (t == '*')
		return (d1*d2);
	if (t == '/')
		return (d1 / d2);
}