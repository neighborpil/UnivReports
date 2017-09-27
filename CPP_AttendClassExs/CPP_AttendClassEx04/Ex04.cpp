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
	int volumn() const //매개변수 뒤의 const의 의미
	{				   // - 함수 뒤에선 모든 변수의 변경이 불가능해진다
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