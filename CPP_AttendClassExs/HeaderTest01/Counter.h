#pragma once

class Counter
{
	int count;
public:
	Counter();
	void reset();
	void add();
	int get() const;
};