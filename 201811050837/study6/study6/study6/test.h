#pragma once
#ifndef TEST_H_
#define TEST_H_

class vehicle  //汽车类
{
protected:
	int wheels, weight;
public:
	vehicle(int whe, int wei);
	~vehicle();
	void Output(); //vehicle类输出
};

class car : private vehicle //私有继承
{
private:
	int passenger_load;
public:
	car(int whe, int wei, int pas);
	~car();
	void Output(); //car类输出
};

class truck : private vehicle //私有继承
{
public:
	truck(int whe, int wei, int pas, int pay);
	~truck();
	void Output();
private:
	int passenger_load, payload;
};


#endif // !TEST_H_