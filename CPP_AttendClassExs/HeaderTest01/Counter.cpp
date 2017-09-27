#pragma once
#include <iostream>
using namespace std;
#include "Counter.h"

Counter::Counter() : count(0) { } //초기화 리스트
//Counter::Counter() { count = 0; } //이거와 같다
void Counter::reset() { count = 0; }
void Counter::add() { count++; }
int Counter::get() const { return count; }