// OOP_PRAKT_EXAM.cpp : main project file.

#include "stdafx.h"
#include <iostream>
#include <String>

using namespace System;
using namespace std;

/*
Реализирайте подходящ клас, описващ полином от n­та степен. Всеки полином
от степен n се представя като масив с дължина n от коефициентите пред
степените на променливата. Да се осигури правилното функциониране на
голямата четворка за този клас. Всеки полином трябва да може да бъде
умножаван с число и да бъде събиран и изваждан с други полиноми (за целта
да се използват подходящи оператори).
Бонус: Напишете метод, връщащ производнaта на полином.
*/

class Polynom
{
private:
	int n;
	double *coef;
public:
	Polynom(double* = NULL, int = 0);
	Polynom(const Polynom&);
	Polynom operator = (const Polynom&);
	~Polynom();

	Polynom operator * (double);
	Polynom operator + (const Polynom&);
	Polynom operator - (const Polynom&);

};
Polynom::Polynom(double* coef, int n)
{
	this->n = n;
	for (int i = 0; i < n; i++)
	{
		this->coef[i] = coef[i];
	}
}
Polynom::Polynom(const Polynom&p)
{
	coef = new double[p.n + 1];
}
Polynom Polynom::operator = (const Polynom&p)
{
	if (this !=&p)
	{
		delete[]coef;
		coef = new double[p.n + 1];

		this->n = p.n;
		for (int i = 0; i < p.n; i++)
		{
			this->coef[i] = p.coef[i];
		}
	}
	return *this;
}
Polynom::~Polynom()
{
	delete[]coef;
}

Polynom Polynom::operator * (double k)
{
	for (int i = 0; i < n; i++)
	{
		coef[i] *= k;
	}
	return *this;
}
Polynom Polynom::operator + (const Polynom&p)
{
	Polynom new_polynom;
	for (int i = 0; i < n; i++)
	{
		new_polynom.coef[i] = this->coef[i] + p.coef[i];
	}
	return new_polynom;
}
Polynom Polynom::operator - (const Polynom&p)
{
	Polynom new_polynom;
	for (int i = 0; i < n; i++)
	{
		new_polynom.coef[i] = this->coef[i] - p.coef[i];
	}
	return new_polynom;
}

int main()
{
	double arr[100];
	int n; cout << "size="; cin >> n;
	
	for (int i = 0; i < n; i++)
	{
		cout << "arr[" << i << "]="; cin >> arr[i]; cout << endl;
	}
	double arrr[100];

	for (int i = 0; i < n; i++)
	{
		cout << "arrr[" << i << "]="; cin >> arrr[i]; cout << endl;
	}
	Polynom p1(arr, n);
	Polynom p2(arrr, n);
	Polynom p;
	p = p1 + p2;
	p = p * 3;
	p = p - p1;
}
