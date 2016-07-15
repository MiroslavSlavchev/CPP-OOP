// UPR_9.3.2016.cpp : main project file.

#include "stdafx.h"
#include <iostream>
#include <string>

using namespace System;
using namespace std;

const int sun_speed = 299792;

struct planet
{
	string name;
	double sun_distance;
	double diameter;
	double mass;
	void enter_planet();
	void print_planet();
	long need_seconds();
};
void planet::enter_planet()
{
	cout << "enter planet name:"; cin >> name;
	cout << "enter distance from planet " << name << " to the sun:"; cin >> sun_distance;
	cout << "enter planet " << name << " diameter:"; cin >> diameter;
	cout << "enter mass of the planet " << name << ":"; cin >> mass;
}
void planet::print_planet()
{
	cout << "planet:" << name << endl;
	cout << "distance from the planet " << name << " to the sum is" << sun_distance << endl;
	cout << "planet " << name << " diameter:" << diameter << endl;
	cout << "mass of the planet " << name << ": " << mass << endl;
}
long planet::need_seconds()
{
	long time = sun_speed;
	long seconds = (sun_distance / time)*3600;
	
	return seconds;
}

int main()
{
	planet p;
	planet arr[100];
	int n;
	cout << "enter number of planets:"; cin >> n;
	int i;
	for (i = 0; i < n; i++)
	{
		arr[i].enter_planet();
	}
	for (i = 0; i < n; i++)
	{
		arr[i].print_planet();
	}
	int min;
	for (i = 0; i < n; i++)
	{
		for (int j = n - 1; j > i; j--)
		{
			min = arr[i].mass;
			if (min > arr[j].mass)
			{
				min = arr[j].mass;
			}
		}
	}
	cout << "planet with lolest mass has mass:" << min << endl;


	for (i = 0; i < n; i++)
	{
		cout << i + 1 << "." << "planet:" << arr[i].name << arr[i].need_seconds() << endl;
	}

	int fast;
	string fast_light;
	for (i = 0; i < n; i++)
	{
		for (int j = n - 1; j > i; j--)
		{
			fast = arr[i].need_seconds();
			fast_light = arr[i].name;
			if (fast < arr[j].need_seconds())
			{
				fast = arr[j].need_seconds();
				fast_light = arr[j].name;
			}
		}
	}
	cout << "The first planet that receives light is: " << fast_light << "(" << fast << ")" << endl;

	int last;
	string last_light;
	for (i = 0; i < n; i++)
	{
		for (int j = n - 1; j > i; j--)
		{
			last = arr[i].need_seconds();
			fast_light = arr[i].name;
			if (last > arr[j].need_seconds())
			{
				last = arr[j].need_seconds();
				last_light = arr[j].name;
			}
		}
	}
	cout << "The last planet that receives light is: " << last_light << "(" << last << ")" << endl;

}

