// Exam_Preparation_OOP.cpp : main project file.

#include "stdafx.h"
#include <iostream>
#include <string>

using namespace System;
using namespace std;

class C
{
private:
	int*data;
	int size;
	int current;
public:
	void delete_element(int);
};
void C::delete_element(int n)
{
	int this_el = data[current - 1]
		;	for (int i = 0; i < current; i++)
	{
		if ( data[i]==n)
		{
			data[i] = this_el;
		}
	}
	current--;
}

int main()
{

}
