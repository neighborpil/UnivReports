// HeaderTest01.cpp : �ܼ� ���� ���α׷��� ���� �������� �����մϴ�.
//

#include "stdafx.h"
#include <iostream>
using namespace std;
#include "Counter.h"

int main()
{
	Counter counter;
	counter.reset();
	counter.add();
	cout << counter.get() << endl;
	counter.add();
	cout << counter.get() << endl;
	counter.add();
	cout << counter.get() << endl;
	counter.reset();
	cout << counter.get() << endl;

	//��ü ������ const �����ϱ�
	const Counter counter2 = Counter();
	
	cout << counter2.get() << endl; //��ü ������ const������, 
		//�޼ҵ尡 ���� ���� �Ұ��� const�Լ��̱� ������ ��� ����
	return 0;
}

