#include <iostream>
using namespace std;

class Box
{
private:
	int height, width, depth;
public:
	void init(int h, int w, int d)
	{
		height = h;
		width = w;
		depth = d;
	}
	int volumn() const //�Ű����� ���� const�� �ǹ�
	{				   // - �Լ� �ڿ��� ��� ������ ������ �Ұ���������
		return height * width * depth;
	}
};

int main()
{
	Box b;
	b.init(5, 10, 10);
	cout << b.volumn() << endl;

	return 0;
}