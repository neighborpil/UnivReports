// HeaderTest01.cpp : 콘솔 응용 프로그램에 대한 진입점을 정의합니다.
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

	//객체 생성시 const 지정하기
	const Counter counter2 = Counter();
	
	cout << counter2.get() << endl; //객체 참조가 const이지만, 
		//메소드가 내부 수정 불가인 const함수이기 때문에 사용 가능
	return 0;
}

