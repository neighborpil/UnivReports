#include <iostream>
using namespace std;

class Counter
{
private:
	int count;
public:
	Counter();
	int GetCount() const;
	void AddCount();
	void ResetCount();
}; //����Ŭ�� ���� ���� ����

Counter::Counter()
{
	count = 0;
}

int Counter::GetCount() const
{
	return count;
}

void Counter::AddCount()
{
	count++;
}

void Counter::ResetCount()
{
	count = 0;
}

int main()
{
	Counter counter;

	cout << counter.GetCount() << endl;

	counter.AddCount();
	cout << counter.GetCount() << endl;

	counter.AddCount();
	cout << counter.GetCount() << endl;
	counter.AddCount();
	cout << counter.GetCount() << endl;

	counter.ResetCount();
	cout << counter.GetCount() << endl;
	
	counter.AddCount();
	cout << counter.GetCount() << endl;



	return 0;
}