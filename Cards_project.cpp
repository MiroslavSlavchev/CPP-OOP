// Cards_project.cpp : main project file.

#include "stdafx.h"
#include <iostream>
#include <string>
#include <random>

using namespace System;
using namespace std;

const int MAX_LIFE = 100;
const int MAX_ATTACK = 100;
const int MAX_CARDS = 80;
const int MAX_SKILL_SIZE = 3;

int setter()
{
	int n;
	cin >> n;
	return n;
}
int coin()
{
	int flip;
	flip = rand() % 2 + 1;
	if (flip == 1)
	{
		cout << "The flip was heads." << endl;
	}
	else
	{
		cout << "The flip was tails." << endl;
	}
	return (flip);
}
int dice()
{
	int roll;
	roll = rand() % 6 + 1;
	if (roll == 1)cout << "You threw 1!" << endl;
	else if (roll == 2)cout << "You threw 2!" << endl;
	else if (roll == 3)cout << "You threw 3!" << endl;
	else if (roll == 4)cout << "You threw 4!" << endl;
	else if (roll == 5)cout << "You threw 5!" << endl;
	else if (roll == 6)cout << "You threw 6!" << endl;
	return(roll);
}

class Card
{
protected:
	int attack;
	int life;
	int energy;
	Skill*skills;
	int skill_size;
public:
	
	Card(int = 1, int = 1, int = 0);
	Card(Card&);
	~Card();

	int get_attack();
	int get_life();
	int get_energy();
	Skill get_skill()
	{
		for (int i = 0; i < skill_size; i++)
		{
			return skills[i];
		}
	}

	void set_attack(int);
	void set_life(int);
	void set_energy(int,int);

	void set_skills(Skill*skills)
	{
		for (int i = 0; i < skill_size; i++)
		{
			this->skills[i] = skills[i];
		}
	}
	void set_skill(Skill&skill)
	{
		skill_size = 1;
		this->skills[0] = skill;
	}

	Card operator = (const Card&); 
	bool operator==(const Card&); 
	bool operator!=(const Card&); 
	ostream& operator<<(ostream& os); 
	istream& operator>>(istream& is); 
	Card operator+=(const int); 
	Card operator-= (const int); 

	void print();
	bool is_Guard();
};

Card::Card(int attack, int life,int size)
{
	if (attack > 0 && attack <MAX_ATTACK)
	{
		this->attack = attack;
	}
	if (life > 0 && life <MAX_LIFE)
	{
		this->life = life;
	}
	if ((attack > 0 && attack < MAX_ATTACK) && (life > 0 && life < MAX_LIFE))
	{
		this->energy = life / 100 + attack / 20;
	}
	if (size > 0 && size < MAX_SKILL_SIZE)
	{
		this->skill_size = size;
	}
}
Card::Card(Card&c)
{
	skills = new Skill[sizeof(c.skills)+1];
	attack = c.attack;
	life = c.life;
	energy = c.energy;
}
Card::~Card()
{
	delete[]skills;
}


int Card::get_attack()
{
	return attack;
}
int Card::get_life()
{
	return life;
}
int Card::get_energy()
{
	return energy;
}

void Card::set_attack(int attack)
{
	if ((attack > 0 && attack <= MAX_ATTACK))
	{
		this->attack = attack;
	}
	else cout << "Error!" << endl;
}
void Card::set_life(int life)
{
	if ((life > 0 && life <= MAX_LIFE))
	{
		this->life = life;
	}
	else cout << "Error!" << endl;
}
void Card::set_energy(int attack, int life)
{
	if ((life > 0 && life <= MAX_LIFE) || (attack > 0 && attack <= MAX_ATTACK))
	{
		this->life = life;
		this->attack = attack;
		this->energy = life / 100 + attack / 20;
	}
	else cout << "Error!" << endl;
}


Card Card::operator = (const Card&c)
{
	if (this != &c)
	{
		delete[]skills;
		skills = new Skill[sizeof(c.skills)+1];

		attack = c.attack;
		life = c.life;
		energy = c.energy;
	}
	return *this;
}
bool Card::operator==(const Card&c)
{
	return (attack == c.attack && life == c.life && energy == c.energy);
}
bool Card::operator!=(const Card&c)
{
	return (attack != c.attack || life != c.life || energy != c.energy);
}

ostream& Card::operator<<(ostream& os)
{
	 os<<attack<<endl<<life<<endl<<energy<< endl;
	 return os;
}
istream& Card::operator>>(istream& is)
{
	is >> attack >> life >> energy;
	return is;
}
Card Card::operator+=(const int extra)
{
	if (extra > MAX_LIFE ||extra < 0)
	{
		cout << "Not Possible" << endl;
	}
	else
	{
		life = life + extra;
	}
	return *this;
}

Card Card::operator-= (const int loose)
{
	if (loose > MAX_LIFE || loose < 0)
	{
		cout << "Not Possible" << endl;
	}
	else if (loose == life)
	{
		cout << "You don't have any lifepoints!You loose!" << endl;
	}
	else
	{
		life = life - loose;
	}
	return *this;
}

void Card::print()
{
	cout << "This card has::" << endl;
	cout << "attack:" << attack << endl;
	cout << "life:" << life << endl;
	cout << "energy:" << energy << endl;
}

bool Card::is_Guard()
{
	return true;
}
class Deck
{
private:
	Card*cards;
	int size;
public:
	
	Deck(int = 5,Card* =NULL);
	Deck(Deck&);
	~Deck();

	int get_size();
	Card get_card();
	void set_size(int);

	void add_card(Card&);
	void delete_card(Card&);
	Card change_card(Card&);

	Deck operator=(const Deck&);
	bool operator== (const Deck&);
	bool operator != (const Deck&);
	bool operator <(const Deck&);
	bool operator >(const Deck&);
	bool operator <=(const Deck&);
	bool operator >=(const Deck&);
	ostream& operator<< (ostream& os);
	Deck operator + (Card&);
	Deck operator + (Deck&);
	Deck operator +=(Card&);
	Deck operator +=(Deck&);
	Card operator [](int n);

	Deck operator *(int);
	Deck operator / (int);
	Deck operator - (Card&);
	Deck operator - (int);

	Deck operator () (int,Card*);
};

Deck::Deck(int size,Card*cards)
{
	if (size>=5 || size <= MAX_CARDS)
	{
		this->size = size;
		for (int i = 0; i < size; i++)
		{
			this->cards[i] = cards[i];
		}
	}
	else cout << "Unvalid card number!" << endl;
}
Deck::Deck(Deck&d)
{
	cards = new Card[d.size+1];
	size = d.size;
}
Deck::~Deck()
{
	delete[]cards;
}

int Deck::get_size()
{
	return size;
}
Card Deck::get_card()
{
	for (int i = 0; i < size; i++)
	{
		return cards[size];
	}
}
void Deck::set_size(int size)
{
	this->size = size;
}

void Deck::add_card(Card& c)
{
	size++;
	for (int i = 0; i < size; i++)
	{
		c = cards[size-1];
	}

}
void Deck::delete_card(Card&c)
{
	
	for (int i = 0; i < size; i++)
	{
		c = cards[size-1];
		c = NULL;
	}
	size--;
}
Card Deck::change_card(Card&c)
{
	int a;
	int l;
	do {
		cout << "Enter attack:"; cin >> a;
		cout << "Enter lifepoints:"; cin >> l;
	} while ((a < 1 || a > MAX_ATTACK) && (l < 1 || l > MAX_LIFE));
	c.set_attack(a);
	c.set_life(l);
	c.set_energy(a,l);

	return c;
}
Deck Deck::operator=(const Deck&d)
{
	if (this != &d)
	{
		delete[]cards;
		cards = new Card[d.size+1];

		size = d.size;
		for (int i = 0; i < size; i++)
		{
			cards[i] = d.cards[i];
		}
	}
	return *this;
}
bool Deck::operator== (const Deck&d)
{
	for (int i = 0; i < size; i++)
	{
		return (cards[i].get_attack() == d.cards[i].get_attack() &&
			cards[i].get_life() == d.cards[i].get_life() &&
			cards[i].get_energy() == d.cards[i].get_energy());
	} 
}
bool Deck::operator != (const Deck&d)
{
	for (int i = 0; i < size; i++)
	{
		return  (cards[i].get_attack() != d.cards[i].get_attack() ||
			cards[i].get_life() != d.cards[i].get_life() ||
			cards[i].get_energy() != d.cards[i].get_energy());
	}
}
bool Deck::operator <(const Deck&d)
{
	for (int i = 0; i < size; i++)
	{
		return (cards[i].get_attack() < d.cards[i].get_attack() &&
			cards[i].get_life() < d.cards[i].get_life() &&
			cards[i].get_energy() < d.cards[i].get_energy());
	}
}
bool Deck::operator >(const Deck&d)
{
	for (int i = 0; i < size; i++)
	{
		return (cards[i].get_attack() > d.cards[i].get_attack() &&
			cards[i].get_life() > d.cards[i].get_life() &&
			cards[i].get_energy() > d.cards[i].get_energy());
	}
}
bool Deck::operator <=(const Deck&d)
{
	for (int i = 0; i < size; i++)
	{
		return (cards[i].get_attack() <= d.cards[i].get_attack() &&
			cards[i].get_life() <= d.cards[i].get_life() &&
			cards[i].get_energy() <= d.cards[i].get_energy());
	}
}
bool Deck::operator >=(const Deck&d)
{
	for (int i = 0; i < size; i++)
	{
		return (cards[i].get_attack() >= d.cards[i].get_attack() &&
			cards[i].get_life() >= d.cards[i].get_life() &&
			cards[i].get_energy() >= d.cards[i].get_energy());
	}
}

ostream& Deck::operator << (ostream& os)
{
	for (int i = 0; i < size; i++)
	{
		os << cards[i].get_attack() << "," << cards[i].get_life() << "," << cards[i].get_energy() << endl;
		return os;
	}
}
Deck Deck::operator + (Deck&d)
{
	size = size + d.size;
	for (int i = 0; i < size + d.size; i++)
	{
		cards[i++] = d.cards[i];
	}
	return *this;
}
Deck Deck::operator + (Card&c)
{
	size = size++;
	for (int i = 0; i < size; i++)
	{
		cards[i++] = c;
	}
	return *this;
}
Deck Deck::operator +=(Card&c)
{
	size++;
	for (int i = 0; i < size; i++)
	{
		cards[i++] = c;
	}
	return *this;
}
Deck Deck::operator +=(Deck&d)
{
	size = size + d.size;
	for (int k = 0; k < size + d.size; k++)
	{
		d += cards[k];
	}
	return *this;
}
Card Deck::operator [](int n)
{
	for (int i = 0; i < size; i++)
	{
		return cards[n];
	}
}

Deck Deck::operator * (int k)
{
	if (k * size == MAX_CARDS && k < size)
	{
		size = size * k;
	}
	return *this;
}
Deck Deck::operator / (int k)
{
	if (k % 2 == 0 && k < size)
	{
		size = size / k;
	}
	return *this;
}
Deck Deck::operator - (Card&c)
{
	for (int i = 0; i < size; i++)
	{
		delete_card(c);
	}
	return *this;
}
Deck Deck::operator - (int k)
{
	size = size - k;
	return *this;
}


Deck Deck::operator () (int size, Card*cards)
{
	if (size >= 5 || size <= MAX_CARDS)
	{
		this->size = size;
		for (int i = 0; i < size; i++)
		{
			this->cards[i] = cards[i];
		}
	}
	else cout << "Unvalid card number!" << endl;
	return *this;
}

class BattleField
{
private:
	Player player1;
	Player opponent;
protected:
	Deck deck;

	Card*hand_cards;
	int hand_cards_size;

	Card*field_cards;
	int field_cards_size;

	Card*opponent_cards;
	int opponent_cards_size;

	Card*Graveyard;
	int Graveyard_cards_size;
public:
	BattleField();
	BattleField(const BattleField&);
	~BattleField();

	Card*get_hand()const;
	Card*get_fields_cards()const;
	Card*get_opponent_cards()const;
	Card*get_Graveyard()const;

	void draw();
	void Summond(Card&);
	void attack(Card&,Card&);
	void Die(Card&);
	void choose_skill(Card&,int,Card&);
};

BattleField::BattleField()
{
	for (int i = 0; i < field_cards_size; i++)
	{
		field_cards[i] = NULL;
	}
	
	do
		{
			draw();
	} while (hand_cards_size==6);
	hand_cards_size = 6;

	Graveyard_cards_size = 0;
}
BattleField::BattleField(const BattleField&b)
{
	hand_cards = new Card[(b.field_cards_size) + 1];
	field_cards = new Card[(b.field_cards_size) + 1];
	opponent_cards = new Card[(b.opponent_cards_size) + 1];
	Graveyard = new Card[(b.Graveyard_cards_size) + 1];
}
BattleField::~BattleField()
{
	delete[]hand_cards;
	delete[]field_cards;
	delete[]opponent_cards;
	delete[]Graveyard;
}

Card* BattleField::get_hand()const
{
		return hand_cards;
}
Card* BattleField::get_fields_cards()const
{
	return field_cards;
}
Card* BattleField::get_opponent_cards()const
{
	return opponent_cards;
}
Card* BattleField::get_Graveyard()const
{
	return Graveyard;
}

void BattleField::draw() 
{
	hand_cards_size++;
	for (int i = 0; i < hand_cards_size; i++)
	{
		hand_cards[hand_cards_size-1]=deck.get_card();
	}
	deck.set_size(deck.get_size()-1);
}
void BattleField::Summond(Card&c)
{
	if (player1.get_life()>=c.get_energy()*2) {
		Card card;
		card = c;
		for (int i = 0; i < hand_cards_size; i++)
		{
			if (hand_cards[i] == c)
			{
				c = hand_cards[hand_cards_size - 1];
				hand_cards[i] = card;
			}
		}
		hand_cards_size--;

		field_cards_size++;

		for (int i = 0; i < field_cards_size; i++)
		{
			if (field_cards[0] == NULL)
			{
				field_cards[0] = c;
			}
			else if (field_cards[1] == NULL)
			{
				field_cards[1] = c;
			}
			else if (field_cards[2] == NULL)
			{
				field_cards[2] = c;
			}
			else if (field_cards[3] == NULL)
			{
				field_cards[3] = c;
			}
			else if (field_cards[4] == NULL)
			{
				field_cards[4] = c;
			}
		}
	}
	else cout << "You can't summond this card!You don't have enough eneryg!" << endl;
}
void BattleField::Die(Card&c)
{
	for (int i = field_cards_size; i >= 0; i--)
	{

	}
	Graveyard_cards_size++;
	for (int i = 0; i < Graveyard_cards_size; i++)
	{
		Graveyard[Graveyard_cards_size-1] = c;
	}
}
void BattleField::attack(Card&attacker,Card&target)
{
	for (int i = 0; i > opponent_cards_size; i++) {
		if (opponent_cards[i].is_Guard) {
			if (attacker.get_attack() > target.get_attack())
			{
				int difference = attacker.get_attack() - target.get_attack();
				Die(target);
				opponent.set_LifePoints(opponent.get_life() - difference);
			}
			else {
				int difference = target.get_attack() -attacker.get_attack() ;
				Die(attacker);
				player1.set_LifePoints(player1.get_life() - difference);
			}
		}
		else
		{
			if (attacker.get_attack() > target.get_attack())
			{
				int difference = attacker.get_attack() - target.get_attack();
				Die(target);
				opponent.set_LifePoints(opponent.get_life() - difference);
			}
			else {
				int difference = target.get_attack() - attacker.get_attack();
				Die(attacker);
				player1.set_LifePoints(player1.get_life() - difference);
			}
		}
	}
}
void BattleField::choose_skill(Card&c,int skill,Card&target)
{
	/*heal;increase;create;polimerize;decrease;destroy;reflect;remove*/

	cout << "You choosed optian " << skill<<"! This option allows you to:"<< endl;
	if (skill == 1)cout << "to heal the targeted card!" << endl;
	else if (skill == 2)cout << "to increase te points of the target!" << endl;
	else if (skill == 3)cout << "to create a new Card!" << endl;
	else if (skill == 4)cout << "to polimerize this card with the targeted Card!" << endl;
	else if (skill = 5)cout << "to decrease the points of the targeted Card!" << endl;
	else if (skill == 6)cout << "to destroy the targeted Card!" << endl;
	else if (skill == 7)cout << "to copy the targeted Card parameters!" << endl;
	else if (skill == 8)cout << "to remove the targeted Card!" << endl;
	else cout << "Unvalid number!" << endl;
	
	switch (skill)
	{
	case 1:c.get_skill().heal(target); break;
	case 2:c.get_skill().increase(target); break;

	case 3:c.get_skill().create(); break;
	case 4:c.get_skill().polimerize(c,target); break;

	case 5:c.get_skill().decrease(target); break;
	case 6:c.get_skill().destroy(target); break;

	case 7:c.get_skill().reflect(target); break;
	case 8:c.get_skill().remove(target); break;
	}
}

enum skill_type { NONE, Spell_Skill, Fusion_Skill, Effect_Skill, Trap_Skill };
class Skill 
{
private:	
	
	//Spell
	bool if_heal;
	bool if_increase;
	//Fusion
	bool if_create;
	bool if_polimerize;
	//Trap
	bool if_decrease;
	bool if_destroy;
	//Effect
	bool if_reflect;
	bool if_remove;
protected:
	void heal(Card&);
	void increase(Card&);

	Card create();
	Card polimerize(Card&,Card&);

	void decrease(Card&);
	void destroy(Card&);

	void reflect(Card&,Card&);
	void remove(Card&, Card*);
public:
	Skill(skill_type=NONE ,bool = false,bool = false);
	Skill& operator =(const Skill&);

};

Skill::Skill(skill_type Property,bool property1,bool property2) 
{
	if (Property==NONE)
	{
		cout << "This card, doesn't have any special skills." << endl;
	}
	else if (Property == Spell_Skill)
	{
		this->if_heal = property1;
		this->if_increase = property2;
	}
	else if (Property == Fusion_Skill)
	{
		this->if_polimerize = property1;
		this->if_create = property2;
	}
	else if (Property == Effect_Skill)
	{
		this->if_reflect = property1;
		this->if_remove = property2;
	}
	else if(Property==Trap_Skill)
	{
		this->if_decrease = property1;
		this->if_destroy = property2;
	}
}

void  Skill::heal(Card&c)
{
	if (if_heal)
	{
		c.set_life(c.get_life() * 2);
		c.set_energy(c.get_attack(), c.get_life());
	}
	else cout << "This Card can't heal!" << endl;
}
void  Skill::increase(Card&c)
{
	if (if_increase) {
		c.set_attack(c.get_attack() * 2);
		c.set_energy(c.get_attack(), c.get_life());
	}
	else cout << "This Card can't encrese the point's!" << endl;
}
Card  Skill::create()
{
	if (if_create) {
		dice();
		if (dice() == 1)
		{
			Card c(10, 10);
			return c;
		}
		else if (dice() == 2)
		{
			Card c(20, 0);
			return c;
		}
		else if (dice() == 3)
		{
			Card c(40, 40);
			return c;
		}
		else if (dice() == 4)
		{
			Card c(60, 60);
			return c;
		}
		else if (dice() == 5)
		{
			Card c(80, 80);
			return c;
		}
		else if (dice() == 6)
		{
			Card c(100, 100);
			return c;
		}
	}
	else cout << "You can't create a new Card!" << endl;
}
Card Skill::polimerize(Card&card1, Card&card2)
{
	Card FUSION(card1.get_attack() + card2.get_attack(), card1.get_life() + card2.get_life());
	return FUSION;
}
void  Skill::decrease(Card&c)
{
	if (if_decrease) {
		c.set_attack(c.get_attack() / 2);
		c.set_energy(c.get_attack(), c.get_life());
	}
	else cout << "You can't decrease the points!" << endl;
}
void  Skill::destroy(Card&c)
{
	if (if_destroy) {
		c = NULL;
	}
	else cout << "You can't destroy this Card!" << endl;
}
void  Skill::reflect(Card&r,Card&c)
{
	if (if_reflect) {
		if (r.get_attack() < c.get_attack() && r.get_life() < c.get_life())
		{
			r.set_attack(c.get_attack());
			r.set_life(c.get_life());
			r.set_energy(c.get_attack(), c.get_life());
		}
		else
		{
			c.set_attack(r.get_attack());
			c.set_life(r.get_life());
			c.set_energy(r.get_attack(), r.get_life());
		}
	}
	else cout << "You can't copy the parameters of this Card!" << endl;
}
void Skill::remove(Card&c, Card*Choosed_area)
{
	if (if_remove) {
		for (int i = 0; i < sizeof(Choosed_area); i++)
		{
			c = Choosed_area[sizeof(Choosed_area) - 1];
			c = NULL;
		}
		sizeof(Choosed_area)--;
	}
	else cout << "You can't remove this Card!" << endl;
}

Skill&  Skill::operator =(const Skill&s)
{
	if (this != &s)
	{
		this->if_create = s.if_create;
		this->if_decrease = s.if_decrease;
		this->if_destroy = s.if_destroy;
		this->if_heal = s.if_heal;
		this->if_increase = s.if_increase;
		this->if_polimerize = s.polimerize;
		this->if_reflect = s.if_reflect;
		this->if_remove = s.if_remove;
	}
	return *this;
}

class Spell_GOD : public Skill
{
private:
	bool if_healing;
	bool if_increasing;
public:
	Spell_GOD(bool = false, bool = false);
	void special_attack(Card&);
};
Spell_GOD::Spell_GOD(bool if_heal, bool if_increase) : Skill(Spell_Skill, if_heal, if_increase)
{
	if (if_increase && if_heal)
	{
		this->if_healing = if_heal;
		this->if_increasing = if_increase;
	}
	else
	{
		cout << "This card doesn't have  Spell powers.";
	}
}
void Spell_GOD::special_attack(Card&c)
{
	coin();
	if (coin() == 1)
	{
		c.set_life(c.get_life() * 10);
		c.set_energy(c.get_attack(), c.get_life());
	}
}
 
class Fusion_GOD : public Skill
{
private:
	bool if_create;
	bool if_polimerize;
public:
	Fusion_GOD(bool=false,bool=false);
	Card special_attack(Card&, Card&);
};
Fusion_GOD::Fusion_GOD(bool if_create, bool if_polimerize) : Skill(Fusion_Skill, if_create, if_polimerize)
{
	if (if_create && if_polimerize)
	{
		this->if_create = if_create;
		this->if_polimerize = if_polimerize;
	}
	else
	{
		cout << "This card doesn't have  Fusion powers.";
	}
	
}
Card Fusion_GOD::special_attack(Card&card1,Card&card2)
{
	Card FUSION((card1.get_attack() + card2.get_attack())*2, (card1.get_life() + card2.get_life())*2);
	return FUSION;
}

class Effect_GOD : public Skill
{
private:
	bool if_reflect;
	bool if_remove;
public:
	Effect_GOD(bool = false, bool = false);
	void special_attack(Card&,Card&,Card*);
};
Effect_GOD::Effect_GOD(bool if_reflect, bool if_remove)
{
	if (if_reflect && if_remove)
		{
			this->if_reflect = if_reflect;
			this->if_remove = if_remove;
		}
		else
		{
			cout << "This card doesn't have  Effect powers.";
		}
}
void Effect_GOD::special_attack(Card&r,Card&c,Card*cards)
{
		
			if (r.get_attack() < c.get_attack() && r.get_life() < c.get_life())
			{
				r.set_attack(c.get_attack());
				r.set_life(c.get_life());
				r.set_energy(c.get_attack(), c.get_life());
			}
			else
			{
				c.set_attack(r.get_attack());
				c.set_life(r.get_life());
				c.set_energy(r.get_attack(), r.get_life());
			}
			
			Card last_card0;
			Card this_card;
			this_card = c;
			for (int i = 0; i < sizeof(cards); i++)
			{
				if (cards[i] == c)
				{
					last_card0 = cards[sizeof(cards) - 1];
					this_card = cards[i];

					cards[i] = last_card0;

					cards[sizeof(cards) - 1] = c;
				}
			}
			sizeof(cards)--;

			Card last_card;
			Card rand_card;
			dice();
			for (int i = 0; i < sizeof(cards); i++)
			{
				last_card = cards[sizeof(cards - 1)];
				rand_card = cards[dice()];

				cards[sizeof(cards - 1)] = cards[dice()];

				cards[dice()] = rand_card;
			}
			sizeof(cards)--;
}

class Trap_GOD : public Skill, public BattleField, public Card
{
private:
	bool if_decrease;
	bool if_destroy;
public:
	Trap_GOD(bool = false, bool = false);
	void special_attack(Card&,Card*);
};
Trap_GOD::Trap_GOD(bool if_decrease, bool if_destroy) : Skill(Trap_Skill, if_decrease, if_destroy)
{
	if (if_decrease && if_destroy)
	{
		this->if_decrease = if_decrease;
		this->if_destroy = if_destroy;
	}
	else
	{
		cout << "This card doesn't have  Effect powers.";
	}
}
void Trap_GOD::special_attack(Card&c, Card*cards)
{
	c.set_attack(c.get_attack() / 2);
	c.set_energy(c.get_attack(), c.get_life());

	Card last_card;
	Card rand_card;
	coin();
		if (coin() != 1) {
			dice();
			for (int i = 0; i < sizeof(cards); i++)
			{
				last_card = cards[sizeof(cards - 1)];
				rand_card = cards[dice()];

				cards[sizeof(cards - 1)] = cards[dice()];

				cards[dice()] = rand_card;
			}
			sizeof(cards)--;
		}
}

class GOD : public Card,public Spell_GOD,public Effect_GOD,public Trap_GOD
{
public:
	GOD(Skill* =NULL,int=0,int=0);

};
GOD::GOD(Skill*skillss, int attack, int life) : Card(attack, life)
{
	
}

class MonsterReborn :public BattleField
{
private:
	Card card;
public:
	MonsterReborn(Card&);
	Card get_card(int)const;
};
MonsterReborn::MonsterReborn(Card&c)
{
	for (int i = 0; i < Graveyard_cards_size; i++)
	{
		if (c == Graveyard[i])
		{
			c = Graveyard[i];
		}
	}
	field_cards_size++;
	for (int i = 0; i < field_cards_size; i++)
	{
		field_cards[field_cards_size-1] = c;
	}
}
Card MonsterReborn::get_card(int n)const
{
	for (int i = 0; i < Graveyard_cards_size; i++)
	{
		return Graveyard[n];
	}
}

class Guard : public Card
{
public:
	Guard(int=0,int=0);
	bool is_Guard();
};
Guard::Guard(int attack,int life) : Card( attack,  life)
{}
bool Guard::is_Guard()
{
	return true;
}

class Assasin : public Card
{
public:
	Assasin(int = 0, int = 0);
	bool is_Assasin();
};
bool Assasin::is_Assasin()
{
	return true;
}
Assasin::Assasin(int attack,int life) : Card(attack,life)
{}

class Player
{
private:
	Deck deck;
	int LifePoints;
	int EnergyPoints;
public:
	Player(Deck, int, int);

	void set_LifePoints(int);
	void set_Energypoints(int);
	int get_life()const;
	int get_energy()const;

};

Player::Player(Deck deck, int life, int energy)
{
	this->deck = deck;
	this->EnergyPoints = energy;
	this->LifePoints = life;
}
void Player::set_LifePoints(int life)
{
	this->LifePoints = life;
}
void Player::set_Energypoints(int energy)
{
	this->EnergyPoints = energy;
}
int Player::get_life()const
{
	return LifePoints;
}
int Player::get_energy()const
{
	return EnergyPoints;
}

Deck create_deck(int size)
{
	Card*c;
	Deck d;

	if (size > 5 && size < MAX_CARDS)
	{
		for (int i = 0; i < size; i++)
		{
			cout << "set attack:"; c[i].set_attack(setter());
			c[i].set_energy(c[i].get_attack(), c[i].get_life());
			cout << "set life:"; c[i].set_life(setter());
		}
		for (int i = 0; i < size; i++)
		{
			cout << i + 1 << "."; c[i].print();
			d(size, c);
		}
	}
	else cout << "unvalid size" << endl;
	return d;
}

int main()
{

}