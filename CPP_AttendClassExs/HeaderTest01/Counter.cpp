#pragma once
#include <iostream>
using namespace std;
#include "Counter.h"

Counter::Counter() : count(0) { } //�ʱ�ȭ ����Ʈ
//Counter::Counter() { count = 0; } //�̰ſ� ����
void Counter::reset() { count = 0; }
void Counter::add() { count++; }
int Counter::get() const { return count; }