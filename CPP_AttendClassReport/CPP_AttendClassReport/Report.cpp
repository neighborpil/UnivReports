#include <iostream>	
using namespace std;
#include "Calculation.h"

int main()
{
	Calculation* calc = new Calculation();
	int inValue;
	while (true)
	{
		cout << "Insert integer value(Press any other key to do other job) : ";
		cin >> inValue;

		if (cin.fail()) 
		{
			cin.clear();
			cin.ignore(256, '\n');

			int tmp;
			cout << "What do u want to do? 1 : finish, 2 : reset, 3: Insert value again\n";
			cin >> tmp;

			if (tmp == 1)
				exit(0);
			else if (tmp == 2)
			{
				calc->Reset();
			}
			else if (tmp == 3)
			{
				cin.clear();
				cin.ignore(256, '\n');
				continue;
			}
			
		}
		else 
		{
			calc->AddNumber(inValue);
			calc->ShowAverage();
			calc->ShowVariance();
		}

	}

	return 1;
}