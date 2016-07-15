// Kontrolno.cpp : main project file.//
//3 grupa

#include "stdafx.h"
#include <iostream>
#include <string>

using namespace System;
using namespace std;

const int capacity = 1280;

struct Parked
{
	char regno[8];
	int time;

	void set_regno(char arr[8])
	{
		for (int i = 0; i < 8; i++) {
			regno[i] = arr[i];
		}
	}
	void set_time(int Time)
	{
		if (Time > 0 && Time <= 12) {
			time = Time;
		}
		else cout << "UNVALID HOUR!" << endl;
	}
};

class ParkingMachine
{
private:
	float price;
	Parked*parked;
	int size;
	int current;
public:
	ParkingMachine(int = 0, int = 0, float = 0.0, Parked* = NULL);
	ParkingMachine(const ParkingMachine&);
	~ParkingMachine();

	ParkingMachine operator = (const ParkingMachine&);

	void resize();
	void enter(char*, int);
	float leave(char*, int);
	float late(int,int);

	bool operator == (char*);

	void operator ! ();

	ostream& operator <<( ostream&);
};

ParkingMachine::ParkingMachine(int size,int current, float price, Parked* parked)
{
	if (size > 0 && size < capacity) {
		this->size = size;
	}
	if (current < size)
	{
		this->current = current;
	}
	for (int i = 0; i < size; i++)
	{
		this->parked[i] = parked[i];
	}
	if (price > 0) {
		this->price = price;
	}
}
ParkingMachine::ParkingMachine(const ParkingMachine&p)
{
	parked = new Parked[p.size + 1];
}
ParkingMachine::~ParkingMachine()
{
	delete[]parked;
}

ParkingMachine ParkingMachine::operator = (const ParkingMachine&p)
{
	if (this != &p)
	{
		delete[]parked;
		parked = new Parked[p.size + 1];

		this->price = p.price;
		this->size = p.size;
		this->current = p.current;
		for (int i = 0; i < size; i++)
		{
			this->parked[i] = p.parked[i];
		}
	}
	return *this;
}

void ParkingMachine::resize()
{
	if (current + 1 > size && current < capacity) {
		size++;
	}
		
		else cout << "FALSE";
	
}
void ParkingMachine::enter(char*regno,int time)
{
	size++;//new car
	for (int i = 0; i < size; i++)
	{
		parked[size].set_regno(regno);
		parked[size].set_time(time);
	}
}
float ParkingMachine::leave(char*regno, int hour)
{
	int whole_time = 0;
	for (int i = 0; i < size; i++)
	{
		if (parked[i].regno == regno) {
			whole_time = hour - parked[i].time;
		}
	}
	int j;
	for (int i = 0; i < size; i++)
	{
		if (parked[i].regno == regno)
		{
			j = i;
		}
	}
	for (int k = 0; k < j; k++)
	{
		parked[k];
	}
	for (int k = j + 1; k < size; k++)
	{
		parked[k];
	}

	price = price*whole_time;
	return price;
}
float ParkingMachine::late(int hours, int hour)
{
	int whole_time;
	for (int i = 0; i < size; i++)
	{
		whole_time = hour - parked[i].time;;

		if (whole_time > hours)
		{
			price = price*whole_time;
			return price;
		}
	}
}

bool ParkingMachine::operator == (char*regno)
{
	for (int i = 0; i < size; i++)
	{
		if (parked[i].regno == regno)
		{
			return true;
		}
		else return false;
	}
}

ostream& ParkingMachine::operator <<(ostream&os)
{
	for (int i = 0; i < size; i++)
	{
		os << price << endl << parked[i].regno<<endl<<parked[i].time << endl << size << endl << current << endl;
	}
	return os;
}

int main()
{

}
