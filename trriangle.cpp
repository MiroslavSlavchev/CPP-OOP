// trriangle.cpp : main project file.


#include "stdafx.h"
#include <iostream>
#include <string>

using namespace System;
using namespace std;

struct triangle
{
double a, b, c;

void create(double x, double y, double z)
{
a = x;
b = y;
c = z;
}
double perimeter()
{
return a + b + c;
}
double surface()
{
double p = (a + b + c) / 2;
return sqrt(p*(p - a)*(p - b)*(p - c));
}

triangle mult_k(int k)
{
triangle t;
t.create(a*k, b*k, c*k);
return t;
}
void show_triangle()
{
	cout << "triangle" << endl;
	cout << "a=" << a << endl;
	cout << "b=" << b << endl;
	cout << "c=" << c << endl;
}
};

void enter_triangle(triangle& t)
{
bool flag1;
do
{
cin >> t.a >> t.b >> t.c;
flag1 = (t.a + t.b > t.c && t.a + t.c > t.b && t.b + t.c > t.a && t.a > 0 && t.b > 0 && t.c > 0);
} while (!flag1);
}

triangle min_surface(triangle *arr,int size)
{
int index=0;
double sur = arr[0].surface();
for (int i = 0; i < size; i++)
{
	if (arr[i].surface < sur)
	{
	sur = arr[i].surface;
	index = i;
	}
}
return arr[index];
}

triangle max_perimeter(int n, triangle arr[])
{
	int k = 0;
	double Max = arr[0].perimeter();
	for (int i = 1; i < n; i++)
	{
		if (arr[i].perimeter() > Max)
		{
			Max = arr[i].perimeter();
			k = i;
		}
	}
	return arr[k];
}

void new_sequence(int n, triangle * arr, triangle * new_arr)
{
	for (int i = 0; i < n; i++)
		new_arr[i] = arr[i].mult_k(i + 1);
}

int main()
{
	int n;
	do
	{
		cout << "n= "; cin >> n;
	} while (n < 1 || n > 20);

	triangle arr[20];

	int i;
	for (i = 0; i < n; i++)
	{
		double x, y, z;
		arr[i].create(x, y, z);
		enter_triangle(arr[i]);
		
	}


	cout << "Triangles:" << endl;
	for (i = 0; i < n; i++)
	{
		arr[i].show_triangle;

		cout << "Triangle with minimum surface"; min_surface(arr, n);


		cout << "Triangle with max perimeter" << endl;
		max_perimeter(n, arr);


		triangle newarr[20];
		cout << "New sequence of triangles:" << endl;
		new_sequence(n, arr, newarr);


		for (i = 0; i < n; i++)
		{
			newarr[i].show_triangle;
		}
	}
}


