#pragma once

#include <iostream>
using namespace std;
#include <cstring>
#include <cmath>

class Calculation
{
private:
	int numCount;
	int* numbers;
	double sum, average, variance;
	void Calc();

public:
	Calculation();
	void AddNumber(int num);
	void ShowAverage() const;
	void ShowVariance() const;
	void Reset();
	~Calculation();
};
