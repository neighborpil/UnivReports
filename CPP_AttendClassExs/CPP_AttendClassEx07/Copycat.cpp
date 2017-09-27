#include <iostream>
using namespace std;
#include "Copycat.h"

Copycat::Copycat(const char* name)
{
	this->name = new char[strlen(name) + 1];
	if (!this->name)
	{
		cout << "�޸� �Ҵ� ����\n" << endl;
		exit(0);
	}
	strcpy(this->name, name);
}

Copycat::Copycat(const Copycat& cc)
{
	name = new char[strlen(cc.name) + 1];
	if (!this->name)
	{
		cout << "�޸� �Ҵ� ����\n" << endl;
		exit(0);
	}
	strcpy(this->name, cc.name);
}

void Copycat::whoRU() const
{
	cout << "���� " << name << "�Դϴ�." << endl;
}
