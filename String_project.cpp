// String_project.cpp : main project file.

#include "stdafx.h"
#include <iostream>
#include <string>
#include <cstring>

using namespace System;
using namespace std;

class Stringg
{
private:
	char* data;
public:
	Stringg();
	Stringg(char* data);
	~Stringg();
	Stringg& operator=(const Stringg&);
	char at(size_t idx);
	const char*get_data() const;
	size_t size() const;

	char operator[](size_t idx);

	Stringg& operator+=( Stringg& rhs);
	bool operator<(const Stringg& rhs);
	bool operator>(const Stringg& rhs);
	bool operator<=(const Stringg& rhs);
	bool operator>=(const Stringg& rhs);

	bool operator==(const Stringg& rhs);
	bool operator!=(const Stringg& rhs);

	friend Stringg operator+ (Stringg lhs, const Stringg& rhs);
	friend ostream& operator<<(ostream& os, const Stringg& obj);
	friend istream& operator>>(istream& is, Stringg& obj);
};

Stringg::Stringg(char* data)
{
	this->data = data;
	this->data = new char[strlen(data)];
}
Stringg::~Stringg()
{
	delete[]data;
}
Stringg& Stringg::operator=(const Stringg& r)
{
	if (r.data)
	{
		if (r.data != data)
		{
			if (data) delete[] data;
			data = new char[strlen(r.data) + 1];
			if (!data)
			{
				cout << "ERROR!" << endl;
			}
			strcpy(data, r.data);
		}
	}
	else if (data)
	{
		delete[] data;
		data = NULL;
	}
	return *this;
}
const char*Stringg::get_data() const
{
	return data;
}

size_t Stringg::size() const
{
	return strlen(data);
}
char Stringg::at(size_t idx)
{
	
	for (int i = 0; i < strlen(data); i++)
	{
		return data[idx];
	}
}

Stringg& Stringg::operator+=( Stringg& rhs)
{
	*rhs.data = *rhs.data + *rhs.data;
	return *this;
}
bool Stringg::operator<(const Stringg& rhs)
{
	return strcmp(data, rhs.get_data()) < 0;
}
bool Stringg::operator>(const Stringg& rhs)
{
	return strcmp(data, rhs.get_data()) > 0;
}
bool Stringg::operator<=(const Stringg& rhs)
{
	return strcmp(data, rhs.get_data()) <= 0;
}
bool Stringg::operator>=(const Stringg& rhs)
{
	return strcmp(data, rhs.get_data()) >= 0;
}
bool Stringg::operator==(const Stringg& rhs)
{
	return !strcmp(data, rhs.get_data());
}
bool Stringg::operator!=(const Stringg& rhs)
{
	return strcmp(data, rhs.get_data()) != 0;
}

Stringg operator + (Stringg lhs, const Stringg& rhs)
{
	return lhs.data + *rhs.data;
}
ostream& operator<<(ostream& os, const Stringg& obj)
{
	os << obj.data << endl;
	return os;
}
istream& operator>>(istream& is, Stringg& obj)
{
	is >> obj.data;
	return is;
}

int main()
{
}

