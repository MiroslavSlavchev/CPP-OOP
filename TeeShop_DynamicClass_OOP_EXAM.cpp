// OOP_EXAM.cpp : main project file.

#include "stdafx.h"
#include <iostream>
#include <string>

using namespace System;
using namespace std;


enum teeType{ male, female };
class Tshirt
{
private:
	char*brand;
	double price;
	int size;//1-4
	teeType type;
public:
	Tshirt(char* = "", double = 0.0, int = 1, teeType = male);
	Tshirt(const Tshirt&);
	Tshirt operator =(const Tshirt&);
	~Tshirt();

	char*get_brand()const;
	double get_price()const;
	int get_size()const;
	teeType get_type()const;

	void set_brand(char*);
	void set_price(double);
	void set_size(int);
	void set_type(teeType);

	bool is_male();
	bool is_female();
};
Tshirt::Tshirt(char*brand, double price, int size, teeType type)
{
	this->brand = brand;
	if (price > 0){
		this->price = price;
	}
	if (size > 0 && size < 5){
		this->size = size;
	}
	this->type = type;
}
Tshirt::Tshirt(const Tshirt&t)
{
	brand = new char[strlen(t.brand) + 1];
}
Tshirt Tshirt::operator =(const Tshirt&t)
{
	if (this != &t)
	{
		delete[]brand;
		brand = new char[strlen(t.brand) + 1];

		this->brand = t.brand;
		if (t.price > 0){
			this->price = t.price;
		}
		if (t.size > 0 && t.size < 5){
			this->size = t.size;
		}
		this->type = t.type;
	}
	return *this;
}
Tshirt::~Tshirt()
{
	delete[]brand;
}

char*Tshirt::get_brand()const
{
	return brand;
}
double Tshirt::get_price()const
{
	return price;
}
int Tshirt::get_size()const
{
	return size;
}
teeType Tshirt::get_type()const
{
	return type;
}

void Tshirt::set_brand(char*brand)
{
	this->brand = brand;
}
void Tshirt::set_price(double price)
{
	this->price = price;
}
void Tshirt::set_size(int size)
{
	this->size = size;
}
void Tshirt::set_type(teeType type)
{
	this->type = type;
}
bool Tshirt::is_male()
{
	return type == male;
}
bool Tshirt::is_female()
{
	return type == female;
}


class TeeShop
{
private:
	Tshirt*tees;
	int size;
	int capacity;
public:
	TeeShop(Tshirt* = NULL, int = 0, int = 0);
	TeeShop(const TeeShop&);
	TeeShop operator =(const TeeShop&);
	~TeeShop();

	void brand_search(char*);
	void t_size_search(teeType, int);
	void price_search(double);
	bool if_exist(char*, double, teeType);

	void resize();
};
TeeShop::TeeShop(Tshirt* tees, int size, int capacity)
{
	if (capacity >= 0){
		this->capacity = capacity;
	}
	if (size >= 0 && size <= capacity){
		this->size = size;
	}
	for (int i = 0; i < size; i++)
	{
		this->tees[i] = tees[i];
	}
}
TeeShop::TeeShop(const TeeShop&t)
{
	tees = new Tshirt[t.capacity + 1];
}
TeeShop TeeShop::operator =(const TeeShop&t)
{
	if (this != &t)
	{
		delete[]tees;
		tees = new Tshirt[t.capacity + 1];
		this->capacity = capacity;

		this->size = t.size;
		for (int i = 0; i < t.size; i++)
		{
			this->tees[i] = t.tees[i];
		}
	}
	return *this;
}
TeeShop::~TeeShop()
{
	delete[]tees;
}

void TeeShop::resize()
{
	if (capacity == size - 1)
	{
		Tshirt* tees = new Tshirt[capacity * 2];
		capacity = capacity * 2;
		for (int i = 0; i < capacity; i++)
		{
			tees[i] = this->tees[i];
		}
		delete[] this->tees;
		this->tees = tees;
	}

}

void TeeShop::brand_search(char*brand)
{
	for (int i = 0; i < size; i++)
	{
		if (this->tees[i].get_brand() == brand)
		{
			cout << "We have tees on this brand!" << endl;

			cout << "number:" << i + 1 << ",";
			cout << i + 1 << "." << "size-" << tees[i].get_size() << endl
				<< "on price-" << tees[i].get_price() << endl;
		}
		cout << "no tees on this brand" << endl;
		if (tees[i].is_male())cout << "male tshirt ";
		else cout << " female tshirt ";
	}
}
void TeeShop::t_size_search(teeType t, int size)
{
	for (int i = 0; i < size; i++)
	{
		if (t == male &&this->tees[i].get_size() == size)
		{
			cout << "We have tees with this size!" << endl;

			cout << "number:" << i + 1 << ",";
			cout << i + 1 << "." << "size-" << tees[i].get_size() << endl
				<< "on brand-" << tees[i].get_brand() << endl;
		}
		else if (t == female &&this->tees[i].get_size() == size)
		{
			cout << "We have tees with this size!" << endl;
			cout << "They are female tees ";

			cout << "number:" << i + 1 << ",";
			cout << i + 1 << "." << "size-" << tees[i].get_size() << endl
				<< "on brand-" << tees[i].get_brand() << endl;
			if (tees[i].is_male())cout << "male tshirt ";
			else cout << " female tshirt ";
		}
		else cout << "no tees with this size ant type" << endl;

	}
}
void TeeShop::price_search(double price)
{
	for (int i = 0; i < size; i++)
	{
		if (tees[i].get_price() == price)
		{

			cout << "We have tees on this price!" << endl;
			cout << "number:" << i + 1 << ",";


			cout << i + 1 << "." << "size-" << tees[i].get_size() << endl
				<< "on brand-" << tees[i].get_brand() << endl;
			if (tees[i].is_male())cout << "male tshirt ";
			else cout << " female tshirt ";
		}
	}
}
bool TeeShop::if_exist(char*brand, double price, teeType t)
{
	for (int i = 0; i < size; i++)
	{
		if (tees[i].get_brand() == brand && tees[i].get_price() == price && tees[i].get_type() == t)
		{
			return true;
		}
		else return false;

	}

}

int main()
{

}
