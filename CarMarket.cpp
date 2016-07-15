// CarMarket.cpp : main project file.

#include "stdafx.h"
#include <iostream>
#include <string>

const int THIS_YEAR = 2016;
using namespace System;
using namespace std;

char* enter()
{
	char*n;
	cin >> n;
	return n;
}
class Car
{
private:
	char*brand;
	char*model;
	char*colour;
	int year;
public:
	Car(char* = "", char* = "", char* = "", int = 1960);
	Car(Car&);
	~Car();

	char* get_brand();
	char* get_model();
	char* get_colour();
	int get_year();
	void set_brand(char*);
	void set_model(char*);
	void set_colour(char*);
	void set_year(int);
};
Car::Car(char* brand1, char* model1, char* colour1, int year)
{
	this->year = year;
	strcpy(brand, brand1);
	strcpy(model,model1);
	strcpy(colour, colour1);
}
Car::Car(Car&c)
{
	brand = new char[strlen(c.brand)];
	model = new char[strlen(c.model)];
	colour = new char[strlen(c.colour)];
}
Car::~Car()
{
	delete[]brand;
	delete[]model;
	delete[]colour;
}
char* Car::get_brand()
{
	return brand;
}
char* Car::get_model()
{
	return model;
}
char* Car::get_colour()
{
	return colour;
}
int Car::get_year()
{
	return year;
}
void Car::set_brand(char*brand)
{
	this->brand = brand;
}
void Car::set_model(char*model)
{
	this->model = model;
}
void Car::set_colour(char*colour)
{
	this->colour = colour;
}
void Car::set_year(int year)
{
	this->year = year;
}

class CarMarketItem
{
private:
	Car car;
	double price;
	char*ID;
public:
	CarMarketItem(Car = NULL, double = 0.0, char* = "");
	Car get_car();
	double get_price();
	char* get_ID();
	void set_car(Car);
	void set_price(double);
	void set_ID(char*);
	int find_time();
};
CarMarketItem::CarMarketItem(Car car, double price, char* ID)
{
	this->car = car;
	this->price = price;
	this->ID = ID;
}
Car CarMarketItem::get_car()
{
	return car;
}
double CarMarketItem::get_price()
{
	return price;
}
char* CarMarketItem::get_ID()
{
	return ID;
}
void CarMarketItem::set_car(Car car)
{
	this->car = car;
}
void CarMarketItem::set_price(double price)
{
	this->price = price;
}
void CarMarketItem::set_ID(char*)
{
	this->ID = ID;
}
int CarMarketItem::find_time()
{
	return THIS_YEAR-car.get_year();
}

class CarMarket
{
private:
	CarMarketItem*CarmarketItems;
	int capacity;
	int car_num;
	double cap;
public:
	CarMarket(CarMarketItem* = NULL, int = 0, int = 0, double = 0.0);
	CarMarket(CarMarket&);
	~CarMarket();

	void add_car(Car, int);
	void sell_car(char*);
	char* lowest_price();
	char* new_car();
};
CarMarket::CarMarket(CarMarketItem*carmarketitems, int capacity, int car_num, double cap)
{
	this->CarmarketItems = carmarketitems;
	this->capacity = capacity;
	this->car_num = car_num;
	this->cap = cap;
}
CarMarket::CarMarket(CarMarket&c)
{
	CarmarketItems = new CarMarketItem[c.capacity];
}
CarMarket::~CarMarket()
{
	delete[]CarmarketItems;
}
void CarMarket::add_car(Car car, int price)
{
	if (price > cap)
	{
		cout << "You can't buy this car!" << endl;
	}
	else
	{
		CarMarketItem c;
		capacity++;
		c.set_car(car);
		c.set_price(price);
		c.set_ID(enter());
		cap = cap - price;
		cout << "Congratolations,you bought a new car!" << endl;
	}
}
void CarMarket::sell_car(char*ID)
{
	car_num--;
	for (int i = 0; i < car_num; i++)
	{
		if (ID = CarmarketItems[i].get_ID())
		{
			cap = cap-CarmarketItems[i].get_price();
		}
	}

}
char* CarMarket::lowest_price()
{
	for (int i = 0; i < capacity; i++)
	{
		for (int j = capacity-1; j > 0; j--)
		{
			int min;
			min = CarmarketItems[i].get_price();
			if (CarmarketItems[i].get_price() < CarmarketItems[j].get_price())
			{
				return CarmarketItems[i].get_ID();
			}
			else return CarmarketItems[j].get_ID();
		}
		
	}
}
char* CarMarket::new_car()
{
	for (int i = 0; i < capacity; i++)
	{
		for (int j = capacity - 1; j > 0; j--)
		{
			int max;
			max = CarmarketItems[i].get_car().get_year();
			if (CarmarketItems[i].get_car().get_year() > CarmarketItems[j].get_car().get_year())
			{
				return CarmarketItems[i].get_ID();
			}
			else return CarmarketItems[j].get_ID();
		}
	}
}

int main()
{

}
