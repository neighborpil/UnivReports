#include "Calculation.h"

//생성자
Calculation::Calculation()
{
	numCount = 0;
	numbers = new int[numCount];
	sum = 0.0;
	average = 0.0;
	variance = 0.0;
}

//숫자 받기
void Calculation::AddNumber(int num)
{
	numCount++;
	int* _numbers = new int[numCount];

	for (int i = 0; i < numCount; i++)
	{
		_numbers[i] = numbers[i];
	}

	_numbers[numCount - 1] = num;

	delete[] numbers;
	numbers = _numbers;

	Calc(); //계산
}

//계산
void Calculation::Calc()
{
	sum = 0;
	for (int i = 0; i < numCount; i++)
	{
		sum += numbers[i];
	}

	average = sum / numCount;

	variance = 0;
	for (int i = 0; i < numCount; i++)
	{
		variance += pow(numbers[i], 2);
	}
	variance /= numCount;

	variance -= pow(average, 2);
}

//평균 표시
void Calculation::ShowAverage() const
{
	cout << "Average : " << average << endl;
}

//분산 표시
void Calculation::ShowVariance() const
{
	cout << "Variance : " << variance << endl;
}

//리셋
void Calculation::Reset()
{
	numCount = 0;
	sum = 0;
	average = 0;
	variance = 0;
}

//소멸자
Calculation::~Calculation()
{
	delete[] numbers;
}