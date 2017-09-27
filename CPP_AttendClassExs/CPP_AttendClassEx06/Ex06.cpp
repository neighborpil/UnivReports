#include <iostream>
#include <cstring>
using namespace std;

class Person
{
private:
	char* name;
	int age;
	char* address;
public:
	Person(char* name, int age, char* address);
	void Info();
	void FixAddress(char* newAddress);
	~Person();
};

Person::Person(char* name, int age, char* address)
{
	this->name = new char[strlen(name) + 1];
	if (!this->name)
	{
		cout << "�޸� �Ҵ� ����\n" << endl;
		exit(0);
	}
	strcpy(this->name, name);;

	this->age = age;

	this->address = new char[strlen(address) + 1];
	if (!this->address)
	{
		cout << "�޸� �Ҵ� ����\n" << endl;
	}

	strcpy(this->address, address);
}

void Person::Info()
{
	cout << "Info" << endl;
	cout << "Name : " << name << endl;
	cout << "age : " << age << endl;
	cout << "Address : " << address << endl;
}

void Person::FixAddress(char* newAddress)
{
	//�����ÿ��� ���� �迭�� ��������� �Ѵ�
	delete[] address;
	address = new char[strlen(newAddress) + 1];

	if (!address)
	{
		cout << "�޸� �Ҵ� ����\n" << endl;
		exit(0);
	}
	cout << "address fix";
	strcpy(address, newAddress);
}

Person::~Person() {
	cout << "Person ��ü�� " << name << ", " << address << " ����" << endl;
	delete[] name;
	delete[] address;
}

int main(void)
{
	Person person("kim", 12, "asdfasdfas");
	Person person2("lee", 123, "fefsfesfsf");
	Person* person3 = new Person("ho", 124, "ewwfwefwef");

	person.Info();
	person.FixAddress("kkkkkkkkkkkk");
	person.Info();

	person2.Info();
	person3->Info();


	return 1;
}