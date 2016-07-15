// Doctor.cpp : main project file.
#include "stdafx.h"
#include <iostream>
#include <string>

using namespace System;
using namespace std;

class Date
{
private:
	int day;
	int month;
	int year;
public:
	
	Date(int = 1, int = 1, int = 1990);
	int get_day();
	int get_month();
	int get_year();
	void set_day(int day);
	void set_month(int month);
	void set_year(int year);
};
Date::Date(int day, int  month , int year)
{
	this->day = day;
	this->month = month;
	this->year = year;
}
int Date::get_day()
{
	return day;
}
int Date::get_month()
{
	return month;
}
int Date::get_year()
{
	return year;
}
void Date::set_day(int day)
{
	this->day = day;
}
void Date::set_month(int month)
{
	this->month = month;
}
void Date::set_year(int year)
{
	this->year = year;
}

class Patient
{
private:
	char*name;
	Date birth_date;
	int visits;
public:
	Patient(char*, Date&, int);
	char*get_name();
	int get_visits();
	Date get_date();
	void set_name(char*);
	void set_date(Date&);
	void set_visits(int);
};
Patient::Patient(char*name, Date&birth_date, int visits)
{
	this->name = name;
	this->birth_date = birth_date;
	this->visits = visits;
}
char*Patient::get_name()
{
	return name;
}
int Patient::get_visits()
{
	return visits;
}
Date Patient::get_date()
{
	return birth_date;
}
void Patient::set_name(char*name)
{
	this->name = name;
}
void Patient::set_date(Date&date)
{
	this->birth_date = date;
}
void Patient::set_visits(int visits)
{
	this->visits = visits;
}

class Statistics
{
private:
	Patient*patients;
	int registered_patients;
public:
	Statistics(int = 0);
	void Register(Patient&);
	double average_visits();
	void more_visits_patients(int);
	Patient get_patient();
	int get_registered_patients();
	Patient get_patient_list(int);
};
Patient Statistics::get_patient()
{
	for (int i = 0; i < registered_patients; i++)
		return patients[i];
}
Statistics::Statistics(int registered_patients)
{
	this->registered_patients = registered_patients;
}

void Statistics::Register(Patient& patient)
{
	patients[registered_patients] = patient;
	registered_patients++;
}
double Statistics::average_visits()
{
	int visits=0;
	if (registered_patients == 0) return 0;
	else
	{for (int i = 0; i < registered_patients; i++)
	{
		visits += patients[i].get_visits();
	}
	return visits;
	}
}
void Statistics::more_visits_patients(int max)
{
	for (int i = 0; i < registered_patients; i++)
	{
		if (patients[i].get_visits()>max)
		{
			cout << "Patients:" << patients[i].get_name() << "," << " have more visits." << endl;
		}
	}
}

class Doctor
{
private:
	char*name;
	Statistics statistics;
public:
	Statistics get_statistics();
	Doctor(char*);
	char* get_name();

};
Doctor::Doctor(char*name)
{
	this->name = name;
}
Statistics Doctor::get_statistics()
{
	return statistics;
}
char* Doctor::get_name()
{
	return name;
}

void print(Doctor &d,int maximum)
{
	cout << "Doctor's name:" << d.get_name()<<endl;
	for (int i = 0; i < d.get_statistics().get_registered_patients(); i++)
	{
		cout << "Patient:" << d.get_statistics().get_patient_list(i).get_name() << ",born(" << d.get_statistics().get_patient_list(i).get_date().get_day() << "." << d.get_statistics().get_patient_list(i).get_date().get_month() << "." << d.get_statistics().get_patient_list(i).get_date().get_day() << "),visited doctor " << d.get_name() << " " << d.get_statistics().get_patient_list(i).get_visits() << " times." << endl;
	}
	cout << "Statistics:" << endl;
	cout << "Average visits:" << d.get_statistics().average_visits() << endl;
	d.get_statistics().more_visits_patients(maximum);

}
int main()
{
	
}
