//#pragma once
#ifndef PERSON_H_INCLUDED
#define PERSON_H_INCLUDED

class Copycat
{
	char* name;
public:
	Copycat(const char* name);
	Copycat(const Copycat& cc);
	~Copycat() { delete[] name; }
	void whoRU() const;

};

#endif