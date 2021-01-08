#include <iostream>
#include<string>
#include "calculator.h"
#include <stack>
using namespace std;

int main()
{
	stack<int> Q;
	stack<char> S;
	string str;
	scanf("%s", str);
	char x;
	int opnum;
	string temp = "";//��ʱ��Ų�����
	int d2, d1;
	char t;
	//cout<<str.size()<<endl;
	//cout<<str[str.size()-1]<<endl;
	for (int i = 0; i < str.size(); i++)
	{
		x = str[i];
		//cout<<x<<endl;
	}
	for (int i = 0; i < str.size(); i++)
	{
		x = str[i];
		//cout<<x<<endl;
		//����ǲ�����

		if (x >= 48 && x <= 57)
		{
			temp.append(1, x);
		}
		if (isOperator(x))
		{
			if (temp != "")
			{
				opnum = stoi(temp);
				//cout<<opnum<<endl;
				Q.push(opnum);
				temp = "";
			}
			if (S.empty())
				S.push(x);
			else {//ջ����һ������Ȼ��ѹ��һ��+�����ڣ������ȼ�δ֪������
				if (x == '(' ||
					((!isBracket(x)) &&
					(getPriority(x) > getPriority(S.top()))))
					S.push(x);
				else
					if (x == ')')
					{
						while (S.top() != '(')
						{
							d2 = Q.top();
							Q.pop();
							d1 = Q.top();
							Q.pop();
							t = S.top();
							S.pop();
							Q.push(doOperate(d1, d2, t));
						}
						S.pop();//������
					}
					else
					{
						while (!S.empty() &&
							((getPriority(S.top()) > getPriority(x)) || (getPriority(x) == getPriority(S.top()))))
						{
							d2 = Q.top();
							Q.pop();
							d1 = Q.top();
							Q.pop();
							t = S.top();
							S.pop();
							Q.push(doOperate(d1, d2, t));
						}
						S.push(x);
					}
			}
		}
		if (!isOperator(x) && i == str.sDize() - 1)
			Q.push(stoi(temp));

	}
	while (!S.empty())
	{
		d2 = Q.top();
		Q.pop();
		d1 = Q.top();
		Q.pop();
		t = S.top();
		S.pop();
		Q.push(doOperate(d1, d2, t));
	}
	cout << Q.top();
    return 0;
	/*
	if(Q.size()==2)
	{
		d2=Q.top();
		Q.pop();
		d1=Q.top();
		Q.pop();
		t=S.top();
		S.pop();
		Q.push(doOperate(d1,d2,t));
	}
	*/
	
}