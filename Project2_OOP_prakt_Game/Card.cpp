#include <iostream>
#include "Card.h"
#include "All Skills.h"

using namespace std;

//Constructor
Card::Card()
{
	this->Name = new char [3];
	strcpy_s(this->Name, 3, "NU");
	this->Attack = 0;
	this->MaxLife = 100;
	this->Life = this->MaxLife;
	CalculateEnergy();
	this->ownSkill = NULL;
}

//Constructor for copy one card to other
Card::Card(const Card& other)
{
	int nameLen = strlen(other.getName())+1;
	this->Name = new char [nameLen];
	if(this->Name)
		strcpy_s(this->Name,nameLen,other.getName());
	this->Attack = other.getAttack();
	this->MaxLife = other.getMaxLife();
	this->Life = other.getMaxLife();
	CalculateEnergy();
	/*
	int SkillLen = strlen(other.Skill)+1;
	this->Skill = new char [SkillLen];
	if(this->Skill)
		strcpy_s(this->Skill,SkillLen,Skill);*/
}

//Destructor
Card::~Card()
{
	delete [] this->Name;
	this->Name = NULL;
	//delete [] this->Skill;
	//this->Skill = NULL;
}

//Constructor for easy creating a card
Card::Card(const char* Name, const unsigned int Attack, const unsigned int MaxLife, const Skill* ownSkill)
{
	int nameLen = strlen(Name)+1;
	this->Name = new char [nameLen];
	if(this->Name)
		strcpy_s(this->Name,nameLen,Name);
	this->Attack = Attack;
	this->MaxLife = MaxLife;
	this->Life = this->MaxLife;
	CalculateEnergy();
	ownSkill->Clone();
}

//Compares that two cards are equal(compare card attack and card life)
bool Card::operator==(const Card& other)
{
	if(!strcmp(this->Name, other.getName()) && this->Attack == other.getAttack() && this->MaxLife == other.getMaxLife())
		return true;
	else
		return false;
}

//Compares that two cards are not equal(if only one is not true this cards is not equal)
bool Card::operator != (const Card& other)
{
	return !(*this == other);
}

//Compares attack of this card is less than second card
bool Card::operator < (const Card& other)
{
	if(this->Attack < other.getAttack())
		return true;
	else
		return false;
}

//Compares attack of this card is larger than second card
bool Card::operator > (const Card& other)
{
	if(this->Attack > other.getAttack())
		return true;
	else
		return false;
}

//Compares attack of this card is not larger than second card
bool Card::operator >= (const Card& other)
{
	if(!(this->Attack < other.getAttack()))
		return true;
	else
		return false;
}

//Compares attack of this card is not less than second card
bool Card::operator <= (const Card& other)
{
	if(!(this->Attack > other.getAttack()))
		return true;
	else
		return false;
}

//Åquales two cards
Card& Card::operator = (const Card& other)
{
	if(*this != other)
	{
		delete [] this->Name;
		this->Name = NULL;

		int nameLen = strlen(other.getName())+1;
		this->Name = new char [nameLen];
		if(this->Name)
			strcpy_s(this->Name,nameLen,other.getName());
		this->Attack = other.getAttack();
		this->Life = other.getLife();
		this->MaxLife = other.getMaxLife();
		CalculateEnergy();
	}
	return *this;
}

//Add this integer to Card life
Card& Card::operator += (const int other)
{
	if((this->Life + other) <= this->MaxLife)
	{
		setLife(this->Life + other);
		CalculateEnergy();
		return *this;
	}
	else
	{
		cout << "With this integer card life is large than maximum life and this function is not performed" << endl;
		return *this;
	}
}

//Remove this integer from Card life
Card& Card::operator -= (const int other)
{
	if((this->Life - other) >= 0)
	{
		setLife(this->Life - other);
		CalculateEnergy();
		return *this;
	}
	else
	{
		cout << "With this integer card life is less than 0 and this function is not performed" << endl;
		return *this;
	}
}

////Add card to deck and return new deck
//Deck Card::operator + (const Deck& other)
//{
//	Deck newDeck(other.getNumCards(),other.getCards());
//	newDeck.addCard(*this);
//	return newDeck;
//}

//Add one point to Card life
const Card& Card::operator ++ ()
{
	if(this->Life + 1 <= this->MaxLife)
	{
		setLife(this->Life + 1);
		CalculateEnergy();
		return *this;
	}
	else
	{
		cout << "Card life is large than maximum life and this function is not performed" << endl;
		return *this;
	}
}

//Remove one point to Card life
const Card& Card::operator -- ()
{
	if(this->Life - 1 >= 0)
	{
		setLife(this->Life - 1);
		CalculateEnergy();
		return *this;
	}
	else
	{
		cout << "Card life is large than maximum life and this function is not performed" << endl;
		return *this;
	}
}

//Add one point to Card life 
const Card Card::operator ++ (int)
{
	if(this->Life + 1 <= this->MaxLife)
	{
		Card temp = *this;
		setLife(this->Life + 1);
		CalculateEnergy();
		return temp;
	}
	else
	{
		cout << "Card life is less than 0 and this function is not performed" << endl;
		return *this;
	}
}

//Remove one point to Card life
const Card Card::operator -- (int)
{
	if(this->Life - 1 >= 0)
	{
		Card temp = *this;
		setLife(this->Life - 1);
		CalculateEnergy();
		return temp;
	}
	else
	{
		cout << "Card life is less than 0 and this function is not performed" << endl;
		return *this;
	}
}


//Get card name
char* Card::getName() const
{
	return this->Name;
}

//Get card attack
unsigned int Card::getAttack() const
{
	return this->Attack;
}

//Get card life
unsigned int Card::getLife() const
{
	return this->Life;
}

//Get Her maximum life
size_t Card::getMaxLife() const
{
	return this->MaxLife;
}

//Get card energy
double Card::getEnergy() const
{
	return this->Energy;
}

//Get card skill
Skill* Card::getOwnSkill() const
{
	return this->ownSkill;
}


//Set Name to card
void Card::setName(const char* Name)
{
	if (Name != NULL)
	{	
		int nameLen = strlen(Name)+1;
		this->Name = new char [nameLen];
		if(this->Name)
			strcpy_s(this->Name,nameLen,Name);
	}
	else
		cout << "Dont have name to set! " << endl;
}

//Set Attack to card
void Card::setAttack(const unsigned int Attack)
{
	if (Attack > 0)
		this->Attack = Attack;
	else
		cout << "Attack of this card cant be less than 0" << endl;
}

//Set Life to card
void Card::setLife(const unsigned int Life)
{
	if (Life > 0)
	{
		this->Life =  Life;
	}
	else
		cout << "Life of card cant be less than 0" << endl;
}

//Set maximum life to Hero
void Card::setMaxLife(const size_t MaxLife)
{
	if(MaxLife > 0)
		this->MaxLife =  MaxLife;
	else 
		cout << "Maximum life of card cant be less than 0" << endl;
}


//Set Skill to card
void Card::setSkill(const Skill* ownSkill)
{
	ownSkill->Clone();
}


//Check this card validity
bool Card::isValid() const
{
	if(getAttack() < 1 || getAttack() > 1000 || strlen(getName()) < 3 || strlen(getName()) > 100)
		return false;
	else
		return true;
}

//Calculate energy
void Card::CalculateEnergy()
{
	 this->Energy = getMaxLife()/100 + getAttack()/20;
}

//Print card in console
void Card::printCard() const
{
	cout << "New Card: \nName: " << this->Name << endl;
	cout << "Attack: " << this->Attack << endl;
	cout << "Life: " << this->Life << "/" <<  this->MaxLife << endl;
	cout << "Energy: " << this->Energy << endl;
	/*
	cout << "Skill: ";
	if(this->Skill != NULL)
		cout << this->Skill << endl;
	else
		cout << "This card dont have skill!" << endl;*/
}

//Save card in flow
void Card::saveCard(ofstream& fout) const
{
	fout.write((char*)&this->Attack, sizeof(unsigned int));
	fout.write((char*)&this->Life, sizeof(unsigned int));
	fout.write((char*)&this->MaxLife, sizeof(unsigned int)); 
	fout.write((char*)&this->Energy, sizeof(double));
	fout.write(this->Name, strlen(this->Name));
}

//Load card from flow
Card Card::loadCard(ifstream& fin)
{
	int loadAttack, loadLife, loadMaxLife;
	double loadEnergy;
	Skill* loadSkill;
	fin.read((char*)&loadAttack, sizeof(unsigned int));
	fin.read((char*)&loadLife, sizeof(unsigned int));
	fin.read((char*)&loadMaxLife, sizeof(unsigned int)); 
	fin.read((char*)&loadEnergy, sizeof(double));
	fin.read((char*)&loadSkill, sizeof(Skill*));
	char* loadName = new char [strlen(this->Name)];
	if(loadName)
		fin.read(loadName, strlen(this->Name));
	Card temp(loadName, loadAttack, loadMaxLife, loadSkill);
	temp.setLife(loadLife);
	return temp;
}


//operator <<
ostream& operator << (ostream& out, const Card& other)
{
	out << "New Card: \nName: " << other.getName() << endl
		<< "Attack: " << other.getAttack() << endl
		<< "Life: " << other.getLife() << "/" <<  other.getMaxLife() << endl
		<< "Energy: " << other.getEnergy() << endl;
	return out;
}

//operator >>
istream& operator >> (istream& in, Card& other)
{
	//char* n;
	size_t a, ml;

	//in >> n;
	//other.setName(n);
	
	in >> a;
	other.setAttack(a);
	
	in >> ml;
	other.setMaxLife(ml);
	other.setLife(ml);

	other.CalculateEnergy();

	return in;
}

