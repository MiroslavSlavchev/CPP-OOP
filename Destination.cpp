// Destination.cpp : main project file.

#include "stdafx.h"
#include <iostream>
#include <string>

using namespace System;
using namespace std;

struct Destination
{
	string city;
	int kilometers;
};

int main()
{
	Destination first_destination = { "Plovdiv",165 };
	Destination second_destination = { "Varna",469 };
	cout << " _______________ " << endl <<"| "<< first_destination.city << " | " << first_destination.kilometers<<" |"<< endl;
	cout << "|_________|_____|" << endl <<"| "<< second_destination.city << "   | " << second_destination.kilometers << " |" << endl << "|_________|_____|" << endl;
	cout << endl;
	Destination arr[30];
	int i;
	for (i = 0; i < 30; i++)
	{
		arr[i].city;
		arr[i].kilometers;
	}
	/*
	for (i = 0; i < 30; i++)
	{
		cout<<i+1<<".city:"; cin >> arr[i].city;
		cout << "kilometers:"; cin >> arr[i].kilometers;
	}*/
	Destination arr1[5];
	
	arr1[0] = { "Plovdiv",165 };
	arr1[1] = { "Varna",469 };
	arr1[2] = { "Burgas",393 };
	arr1[3] = { "Vidin",199 };
	arr1[4] = { "Dobrich",512 };

	int j;
	for (j = 0; j < 5; j++)
	{
		
		cout<< "| " << arr1[j].city << " | " << arr1[j].kilometers << " |" << endl;
	}
}
