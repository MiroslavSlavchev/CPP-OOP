// SportArena.cpp : main project file.

#include "stdafx.h"
#include <iostream>
#include <string>

using namespace System;
using namespace std;

const int Standart_golf_area = 90;
const int Standart_tack_size = 200;
const int Standart_ski_players = 10;

enum SportType{Individual,Team,
	Special_Equipment_Individual, Special_Equipment_Team};

class Sport
{
protected:
	int players_number;
	SportType type;
public:
	Sport(SportType = Individual, int = 0);
	virtual void print()const;

	void set_players_number(int);
	void set_type(SportType);

	bool operator == (const Sport&);
};
Sport::Sport(SportType type, int players_number)
{
	this->type = type;
	this->players_number = players_number;
}
void Sport::print()const
{
	cout << "players number:" << players_number << endl;
	cout << "Type:";
	if (type == Individual)
	{
		cout << "Individual" << endl;
	}
	else if (type == Team)
	{
		cout << "Team" << endl;
	}
	else if (type == Special_Equipment_Individual)
	{
		cout << "Special_Equipment_Individual" << endl;
	}
	else if (type == Special_Equipment_Team)
	{
		cout << "Special_Equipment_Team" << endl;
	}
}

void Sport::set_players_number(int number)
{
	this->players_number = number;
}
void Sport::set_type(SportType s)
{
	this->type = s;
}
bool Sport::operator == (const Sport&s)
{
	return (players_number == s.players_number && type == s.type);
}

class Football : public Sport
{
private:
	int time;
public:
	Football();
	void print()const;
};
Football::Football() : Sport(Team, 2*11)
{
	this->time = 90;
}
void Football::print()const
{
	cout << "Football:" << endl << "Team Sport;doesnt need a special equipment"<< endl << 2*11 << endl;
}
class Skiing : public Sport
{
private:
	int track_size;
public:
	Skiing(int = 0, int = 0);
	void print()const;
};
Skiing::Skiing(int track_size,int players) : Sport(Special_Equipment_Individual,players)
{
	this->track_size = track_size;
}
void Skiing::print()const
{
	cout << "Skiing:" << endl << "Individual Sport;needs special equipment"<<endl<<"track size:"<<track_size<< endl << players_number << endl;
}

class Golf : public Sport
{
private:
	int course_size;
public:
	Golf(int = 0);
	void print()const;
};
Golf::Golf(int size) : Sport(Individual, 2)
{
	this->course_size = size;
}
void Golf::print()const
{
	cout << "Golf:" << endl << "Individual Sport;doesent need a special equipment" << endl<<"area size:"<<course_size << players_number << endl;
}

class Hockey : public Sport
{
public:
	Hockey();
	void print()const;
};
Hockey::Hockey() : Sport(Special_Equipment_Team,5*2)
{
}
void Hockey::print()const
{
	cout << "Hockey:" << endl << "Team Sport;needs special equipment" << endl << players_number << endl;
}

class SportArena
{
private:
	Sport*sports;
	int arena_sports_capacity;
public:
	SportArena(Sport* =NULL);
	SportArena(const SportArena&);
	~SportArena();
	SportArena operator = (const SportArena&);

	void Search_Sport(Sport&);
	void Add_Sport(SportType, int);
	void Delete_Sport(Sport&);
	void Print();
};

SportArena::SportArena(Sport* sports)
{
	for (int i = 0; i < arena_sports_capacity; i++)
	{
		this->sports[i] = sports[i];
	}
	this->arena_sports_capacity = sizeof(sports);
}
SportArena::SportArena(const SportArena&s)
{
	sports = new Sport[s.arena_sports_capacity+1];
}
SportArena::~SportArena()
{
	delete[]sports;
}
SportArena SportArena::operator = (const SportArena&s)
{
	if (this != &s)
	{
		delete[]sports;
		sports = new Sport[s.arena_sports_capacity + 1];
		for (int i = 0; i < arena_sports_capacity; i++)
		{
			this->sports[i] = sports[i];
		}
	}
	return *this;
}

void SportArena::Search_Sport(Sport&s)
{
	for (int i = 0; i < arena_sports_capacity; i++)
	{
		if (sports[i] == s)
		{
			cout << "Sport found!" << endl; sports[i].print();
		}
		else cout << "There isn't such a sport in this arena!" << endl;
	}
}
void SportArena::Add_Sport(SportType s,int n)
{
	arena_sports_capacity++;
	for (int i = 0; i < arena_sports_capacity; i++)
	{
		sports[arena_sports_capacity - 1].set_type(s);
		if (n >= 2 && n <= 22) {
			sports[arena_sports_capacity - 1].set_players_number(n);
		}

		if (s == Individual && n == 2)
		{
		
			Golf g(Standart_golf_area);
			sports[arena_sports_capacity - 1] = g;
		}
		if (s == Team && n == 22)
		{
			Football f;
			sports[arena_sports_capacity - 1] = f;
		}
		if (s == Special_Equipment_Team && n == 10)
		{
			Hockey h;
			sports[arena_sports_capacity - 1] = h;
		}
		if (s == Special_Equipment_Individual)
		{
			Skiing ski(Standart_tack_size, Standart_ski_players);
			sports[arena_sports_capacity - 1] = ski;
		}
	}
}
void SportArena::Delete_Sport(Sport&s)
{
	Sport this_sport;
	for (int i = 0; i < arena_sports_capacity; i++)
	{
		this_sport = sports[arena_sports_capacity - 1];
		if(sports[i]==s)
		{
			sports[arena_sports_capacity - 1] = s;
			sports[i] = this_sport;
		}
	}
	arena_sports_capacity--;
}
void SportArena::Print()
{
	cout << "This arema suggests " << arena_sports_capacity << " kind of sports.";
	for (int i = 0; i < arena_sports_capacity; i++)
	{
		sports[i].print();
	}
}

int main()
{

}
