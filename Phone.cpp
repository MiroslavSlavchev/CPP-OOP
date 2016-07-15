// Phone.cpp : main project file.

#include "stdafx.h"
#include <iostream>
#include <string>

using namespace System;
using namespace std;

const int MAX_MEMORY = 112;
const int MAX_INCHES = 7;

class Phone
{
private:
	static char*brand;
	static char*model;
	static int memory;
	static int freememory;
	static bool touchscreen;
	static double size;
	static double weight;
	static int battery_capacity;
	static int battery_now;
public:
	Phone(char* = "",char* = "", int = 0, int =0,bool = false,double = 0.0,double = 0.0,int =0,int =0);
	Phone(const Phone&);
	~Phone();
	Phone operator =(const Phone&);

	void print()const;
	void charging(int,int);
	void loose(int);
};
Phone::Phone(char* brand, char* model, int memory, int freememory, bool touchscreen, double size,
	double weight, int battery_capacity, int battery_now)
{
	this->brand = brand;
	this->model = model;
	if (memory > 0 && memory < MAX_MEMORY)
	{
		this->memory = memory;
	}
	if (freememory >= 0 && freememory <= MAX_MEMORY)
	{
		this->freememory = freememory;
	}
	this->touchscreen = touchscreen;
	if (size > 0 && size< MAX_INCHES)
	{
		this->size = size;
	}
	if (weight > 0)
	{
		this->weight = weight;
	}
	if (battery_capacity > 0)
	{
		this->battery_capacity = battery_capacity;
	}
	if (battery_now > 0)
	{
		this->battery_now = battery_now;
	}
}
Phone::Phone(const Phone&p)
{
	brand = new char[strlen(p.brand) + 1];
	model = new char[strlen(p.model) + 1];
	if (memory > 0 && memory < MAX_MEMORY)
	{
		this->memory = memory;
	}
	if (freememory >= 0 && freememory <= MAX_MEMORY)
	{
		this->freememory = freememory;
	}
	this->touchscreen = touchscreen;
	if (size > 0 && size, MAX_INCHES)
	{
		this->size = size;
	}
	if (weight > 0)
	{
		this->weight = weight;
	}
	if (battery_capacity > 0)
	{
		this->battery_capacity = battery_capacity;
	}
	if (battery_now > 0)
	{
		this->battery_now = battery_now;
	}
}
Phone::~Phone()
{
	delete[]model;
	delete[]brand;
}
Phone Phone::operator =(const Phone&p)
{
	if (this != &p)
	{
		delete[]brand;
		delete[]model;
		brand = new char[strlen(p.brand) + 1];
		model = new char[strlen(p.model) + 1];

		strcpy(brand, p.brand);
		strcpy(model, p.model);
		this->battery_capacity = p.battery_capacity;
		this->battery_now = p.battery_now;
		this->freememory = p.freememory;
		this->memory = p.memory;
		this->size = p.size;
		this->touchscreen = p.touchscreen;
		this->weight = p.weight;
	}
	return *this;
}

void Phone::print()const
{
	cout<<brand<<endl;
	cout<<model<<endl << endl;
	cout << memory << endl;
	cout << freememory << endl;
	if (touchscreen) {
		cout <<" has touchscreen "<< endl;
	}
	else cout << "has no touchscreen" << endl;
	cout << size << endl;
	cout << weight << endl;
	cout << battery_capacity << endl;
	cout << battery_now << endl;
}
void Phone::charging(int minutes, int percent_per_minute)
{
	if (battery_now >= 100)
	{
		cout << "Battery charged!" << endl;
	}
	else {
		do
		{
			battery_now++;
			
		} while (battery_now!=100);
	}
}
void Phone::loose(int one_percent)
{
	double battery;
	if (one_percent == 1)
	{
		battery = battery_capacity / battery_now;
	}

}

class Camera
{
private:
	static int resolution;
	static bool flash_light;
	static double picture_size;
	static double picture_size_flash;

public:
	Camera(int = 0, bool = false, double = 0.0, double = 0.0);
	
	Camera operator =(const Camera&);

	void print()const;
};

Camera::Camera(int resolution, bool flash_light, double picture_size, double picture_size_flash)
{
	this->resolution = resolution;
	this->flash_light = flash_light;
	this->picture_size = picture_size;
	if (flash_light)
	{
		this->picture_size_flash = picture_size_flash;
	}
	else {
		this->picture_size_flash = 0;
	}
}
Camera Camera::operator =(const Camera&c)
{
	if (this != &c)
	{
		this->resolution = resolution;
		this->flash_light = flash_light;
		this->picture_size = picture_size;
		this->picture_size_flash = picture_size_flash;
	}
	return *this;
}

void Camera::print()const
{
	cout<< resolution;
	if (flash_light) {
		cout << "flash_light"<<endl;
	}
	else cout << "no flash ligh" << endl;
	cout << picture_size << endl;
	cout << picture_size_flash << endl;
}
class CameraPhone :Camera, Phone
{
private:
	int min_cam;
	int min_photo_flash;
	int min_photo_without_flash;
public:
	CameraPhone(char* = "", char* = "", int = 0, int = 0, bool = false, double = 0.0,
		double = 0.0, int = 0, int = 0, int = 0, bool = false, double = 0.0, double = 0.0,int =0,int=0,int=0);
	CameraPhone(const CameraPhone&);
	~CameraPhone();
	CameraPhone operator =(const CameraPhone&);

	void print()const;
	int max_photos()const;
	void photo(bool);
};
CameraPhone::CameraPhone(char* brand, char* model, int memory, int freememory, bool touchscreen, double size,double weight, int battery_capacity, int battery_now,
	int resolution, bool flash_light, double picture_size,
	double picture_size_flash,int min_cam,int min_photo_flash,int min_photo_without_flash) : 
	Phone( brand, model, memory,freememory,touchscreen,size, weight, battery_capacity, battery_now), 
	Camera(resolution, flash_light,  picture_size, picture_size_flash)
{
	this->min_cam = min_cam;
	this->min_photo_flash = min_photo_flash;
	this->min_photo_without_flash = min_photo_without_flash;
}
void CameraPhone::print()const
{
	cout<< min_cam<<endl;
	cout << min_photo_flash << endl;
	cout << min_photo_without_flash << endl;
}
int CameraPhone::max_photos()const
{

}
void CameraPhone::photo(bool flash)
{

}

int main()
{

}
