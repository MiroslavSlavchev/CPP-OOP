// Vector.cpp : main project file.

#include "stdafx.h"
#include <iostream>
#include <string>
#include <cmath>

using namespace System;
using namespace std;

double modul(double x)
{
	if (x > 0) return x;
	else return -x;
}

class Vector
{
private:
	char*vector;
	double x;
	double y;
public:
	Vector();
	Vector( double = 0.0, double = 0.0);
	Vector(Vector&);
	~Vector();

	double get_x();
	double get_y();
	void set_x(int);
	void set_y(int);
	void enter();
	void print();

	Vector operator + (const Vector&);
	Vector operator - (const Vector&);
	Vector operator += (const Vector&);
	Vector operator -= (const Vector&);

	Vector operator +(double);
	Vector operator +=(double);
	Vector operator -(double);
	Vector operator -=(double);
	Vector operator *(double);
	Vector operator *=(double);
	Vector operator /(double);
	Vector operator /=(double);

	void operator [] (Vector&);

	double operator *(Vector&);
	double operator *=(Vector&);
	Vector operator ! ();
};

Vector::Vector( double x, double y)
{
	this->x = x;
	this->y = y;
}
Vector::Vector(Vector&v)
{
	vector = new char[strlen(v.vector)];
}
Vector::~Vector()
{
	delete[]vector;
}

double Vector::get_x()
{
	return x;
}
double Vector::get_y()
{
	return y;
}
void Vector::set_x(int x)
{
	this->x = x;
}
void Vector::set_y(int y)
{
	this->y = y;
}
void Vector::enter()
{
	cout << "x="; cin >> x; set_x(x);
	cout << "y="; cin >> y; set_y(y);
}
void Vector::print()
{
	cout << "x=" << x << endl;
	cout << "y=" << y << endl;
}

Vector Vector::operator + (const Vector&v)
{
	Vector n(v.x + x, v.y + y);
	return n;
}
Vector Vector::operator - (const Vector&v)
{
	Vector n(v.x - x, v.y - y);
	return n;
}
Vector Vector::operator += (const Vector&v)
{
	Vector n(v.x + v.x, v.y + v.y);
	return n;
}
Vector Vector::operator -= (const Vector&v)
{
	Vector n(v.x - v.x, v.y - v.y);
	return n;
}

Vector Vector::operator +(double k)
{
	Vector n(k + x, k + y);
	return n;
}
Vector Vector::operator +=(double k)
{
	Vector n((k + x)*2, (k + y)*2);
	return n;
}
Vector Vector::operator -(double k)
{
	Vector n(k - x, k - y);
	return n;
}
Vector Vector::operator -=(double k)
{
	Vector n(0, 0);
	return n;
}
Vector Vector::operator *(double k)
{
	Vector n(k*x, k*y);
	return n;
}
Vector Vector::operator *=(double k)
{
	Vector n(k*x * k*x, k*y * k*y);
	return n;
}
Vector Vector::operator /(double k)
{
	Vector n(k/x, k/y);
	return n;
}
Vector Vector::operator /=(double k)
{
	Vector n(1, 1);
	return n;
}

void Vector::operator [] (Vector&v)
{
	v.get_x();
	v.get_y();
}

double Vector::operator *(Vector&v)
{
	return (x*v.x + y*v.y);
}
double Vector::operator *= (Vector&v)
{
	return (x*v.x + y*v.y)*2;
}



int main()
{


}
