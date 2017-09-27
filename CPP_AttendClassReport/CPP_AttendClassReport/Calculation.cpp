#include "Calculation.h"

//������
Calculation::Calculation()
{
	numCount = 0;
	numbers = new int[numCount];
	sum = 0.0;
	average = 0.0;
	variance = 0.0;
}

//���� �ޱ�
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

	Calc(); //���
}

//���
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

//��� ǥ��
void Calculation::ShowAverage() const
{
	cout << "Average : " << average << endl;
}

//�л� ǥ��
void Calculation::ShowVariance() const
{
	cout << "Variance : " << variance << endl;
}

//����
void Calculation::Reset()
{
	numCount = 0;
	sum = 0;
	average = 0;
	variance = 0;
}

//�Ҹ���
Calculation::~Calculation()
{
	delete[] numbers;
}