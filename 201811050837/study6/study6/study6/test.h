#pragma once
#ifndef TEST_H_
#define TEST_H_

class vehicle  //������
{
protected:
	int wheels, weight;
public:
	vehicle(int whe, int wei);
	~vehicle();
	void Output(); //vehicle�����
};

class car : private vehicle //˽�м̳�
{
private:
	int passenger_load;
public:
	car(int whe, int wei, int pas);
	~car();
	void Output(); //car�����
};

class truck : private vehicle //˽�м̳�
{
public:
	truck(int whe, int wei, int pas, int pay);
	~truck();
	void Output();
private:
	int passenger_load, payload;
};


#endif // !TEST_H_