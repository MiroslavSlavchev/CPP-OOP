// OOP_PRAKT_EXAM_2.cpp : main project file.

#include "stdafx.h"
#include <iostream>
#include <string>

using namespace System;
using namespace std;

class Package
{
protected:
	double weight;
	char*destination;
public:
	Package(double = 0.0, char* = "");
	Package(const Package&);
	
	virtual~Package(){ delete[]destination; }

	virtual void print()const=0;
	virtual double calculatePrice()=0;
};
Package::Package(double weight, char* destination)
{
	this->weight = weight;
	this->destination = destination;
}
Package::Package(const Package&p)
{
	destination = new char[strlen(p.destination) + 1];
}

class Enveloper : public Package
{
public:
	Enveloper(int = 0, char* = "");
	void print()const; 
	double calculatePrice();
};
Enveloper::Enveloper(int weight, char*destination) : Package(weight, destination){}

void Enveloper::print()const
{
	cout << "weight:" << weight << endl
		<< "destination:" << destination << endl;
}
double Enveloper::calculatePrice()
{
	double price = 2.0;
	price += (weight/100);
	return price;
}

class Volume
{
private:
	double a;
	double b;
	double h;
public:
	Volume()
	{
	
		a = 0;
		b = 0;
		h = 0;
	}
	double get_a()const
	{
		return a;
	}
	double get_b()const
	{
		return b;
	}
	double get_h()const
	{
		return  h;
	}

	void set_a(double a)
	{
		this->a = a;
	}
	void set_b(double b)
	{
		this->b = b;
	}
	void set_h(double h)
	{
		this->h = h;
	}
};

class Box :public Package
{
	Volume volume;
	bool if_br;
public:
	Box(int=0, char* = "", bool= false);
	void set_volume(double, double, double);
	void print()const;
	double calculatePrice();
};
Box::Box(int weight, char*destination,bool if_br) : Package(weight, destination)
{
	
	this->if_br = if_br;
}
void Box::print()const
{
	cout << "destination:" << destination << endl
		<< "weight:" << weight << endl
		<< "volume parameters:" << volume.get_a() << "," << volume.get_b() << "," << volume.get_h() << endl;
	if (if_br){
		cout << "easy to broke" << endl;
	}
	else cout << "not brokenable" << endl;
}
double Box::calculatePrice()
{
	double price = 5.0;
	double vol = 0;
	vol += (volume.get_a()*volume.get_b())*volume.get_h() / 3;
	price += ((vol / 1000)*20);
	return price;
}
void  Box::set_volume(double a, double b, double h)
{
	volume.set_a(a);
	volume.set_a(b);
	volume.set_a(h);
}

class Truck
{
private:
	Package*capacity;
	int size;
public:
	Truck(Package*packages = NULL, int = 1);
	double get_price();
	void print();
	~Truck();
};
Truck::Truck(Package*packages, int size)
{
	if (size > 0 && size < 200)this->size = size;
	for (int i = 0; i < size; i++)
	{
		this->capacity[i] = packages[i];
	}

}

double Truck::get_price()
{
	double total;
	for (int i = 0; i < size; i++)
	{
		total+=this->capacity[i].calculatePrice(); 
	}
	return total; 
}
void Truck::print()
{
	for (int i = 0; i < size; i++)
	{
		this->capacity[i].print();
		cout << endl;
	}
}
Truck::~Truck()
{
	delete[]capacity;
}

int main()
{
	Enveloper enveloper[5];
	enveloper[0] = Enveloper(1,"env1");
	enveloper[1] = Enveloper(2, "env2");
	enveloper[2] = Enveloper(3, "env3");
	enveloper[3] = Enveloper(4, "env4");
	enveloper[4] = Enveloper(5, "env5");

	Box box[5];
	box[0] = Box(1, "box1", true); box[0].set_volume(1, 2, 3);
	box[1] = Box(2, "box2", false); box[1].set_volume(4, 5, 6);
	box[2] = Box(3, "box3", false); box[2].set_volume(7, 8, 9);
	box[3] = Box(4, "box4", false); box[3].set_volume(10, 11, 12);
	box[4] = Box(5, "box5", true); box[4].set_volume(13, 14, 15);

	Package *package[10];
	package[0] = &enveloper[0];
	package[1] = &enveloper[1];
	package[2] = &enveloper[2];
	package[3] = &enveloper[3];
	package[4] = &enveloper[4];

	package[5] = &box[0];
	package[6] = &box[1];
	package[7] = &box[2];
	package[8] = &box[3];
	package[9] = &box[4];

	for (int i = 0; i < 10; i++)
	{
		package[i]->print();
	}
	
	Truck truck(package[10], 10);

	cout<<"total price:"<<truck.get_price()<<endl;
	truck.print();

}
