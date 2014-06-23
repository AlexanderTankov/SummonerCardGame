#include <iostream>
#include "Deck.h"

using namespace std;


//Default constructor
Deck::Deck()
{
	this->numCards = 5;
	this->cards = new Card [numCards];
}

//Destructor
Deck::~Deck()
{
	delete [] this->cards;
	this->cards = NULL;
}

//Constructor for copy one deck to other
Deck::Deck(const Deck& other)
{
	this->cards = new Card [other.getNumCards()];
	this->numCards = other.getNumCards();

	if(other.numCards != 0)
	{
		const Card* otherCards = other.getCards();
		for (size_t i = 0; i < this->numCards; i++)
			this->cards[i] = otherCards[i];
	}
}

//Constructor for easy creating a deck
Deck::Deck(const unsigned int numCards, const Card* cards)
{
	if(numCards != 0)
	{
		this->numCards = numCards;
		this->cards = new Card [this->numCards];
		for (size_t i = 0; i < numCards; i++)
			this->cards[i] = cards[i];
	}
	else
		cout << "Number of cards need to be not equal to 0" << endl;
}

//Åquales two decks
Deck& Deck:: operator = (const Deck& other)
{
	if(*this != other && other.numCards != 0)
	{
		delete [] this->cards;
		this->cards = NULL;

		this->cards = new Card [other.getNumCards()];
		this->numCards = other.getNumCards();

		const Card* otherCards = other.getCards();
		for (size_t i = 0; i < this->numCards; i++)
			this->cards[i] = otherCards[i];
	}
	else
		cout << "This deck dont have cards and dont equales or this deck is with 0 cards" << endl;
	return *this;
}

//Compares that two decks are equal(compare cards in deck)
bool Deck::operator == (const Deck& other)
{
	Deck temp1 = *this, temp2 = other;
	bool flag = true;
	temp1.sortCardsByAttack();
	temp2.sortCardsByAttack();
	if (temp1.getNumCards() == temp2.getNumCards())
	{
		for (size_t i = 0; i < temp1.getNumCards(); i++)
		{
			if(temp1.cards[i] != temp2.cards[i])
			{
				flag = false;
			}
		}
	}			
	else
		flag = false;
	
	if(flag)
		return true;
	else
		return false;
}

//Compares that two decks are not equal
bool Deck::operator != (const Deck& other)
{
	return !(*this == other);
}

//Compares sum of attack and life of all cards in deck are less than second sum
bool Deck::operator < (const Deck& other)
{
	if(sumAttackAndLife(*this) < sumAttackAndLife(other))
		return true;
	else
		return false;
}

//Compares sum of attack and life of all cards in deck are larger than second sum
bool Deck::operator > (const Deck& other)
{
	if(sumAttackAndLife(*this) > sumAttackAndLife(other))
		return true;
	else
		return false;
}

//Compares sum of attack and life of all cards in deck are larger or equal than second sum
bool Deck::operator >= (const Deck& other)
{
	if(!(*this < other))
		return true;
	else
		return false;
}

//Compares sum of attack and life of all cards in deck are less or equal than second sum
bool Deck::operator <= (const Deck& other)
{
	if(!(*this > other))
		return true;
	else
		return false;
}

//Add deck to card and return new deck
Deck Deck::operator + (const Card& other)
{
	Deck newDeck(*this);
	newDeck.addCard(other);
	return newDeck;
}

//Add deck to deck and return new deck
Deck Deck::operator + (const Deck& other)
{
	Deck newDeck(*this);
	newDeck.printDeck();
	for (size_t i = 0; i < other.getNumCards(); i++)
		newDeck.addCard(other.getCards()[i]);
	return newDeck;
}

//Add deck to Card
Deck& Deck::operator += (const Card& other)
{
	if(other.isValid() == true)
		addCard(other);
	return *this;
}

//Add deck to deck
Deck& Deck::operator += (const Deck& other)
{
	if(other.isValid() == true)
	{
		size_t temp = other.getNumCards();
		size_t count = 0;
		for (size_t i = 0; i < temp; i++)
		{
			if(other.getCards()[i].isValid() == true)
				count++;
			else
				break;
		}
		for (size_t i = 0; i < count; i++)
				addCard(other.getCards()[i]);
	}
	return *this;
}

//Return card with this index in deck
Card& Deck::operator [] (const int idx)
{
	return this->cards[idx];
}

//Remove card from deck and return new deck
Deck Deck::operator - (const Card& other)
{
	Deck newDeck(getNumCards(),getCards());
	newDeck.deleteCard(other);
	newDeck.orderedDeck();
	return newDeck;
}

//Remove deck from deck and return new deck
Deck Deck::operator - (const Deck& other)
{
	Deck newDeck;

	if(getNumCards() > other.getNumCards())
	{
		newDeck.setCards(getNumCards(), getCards());
		for (size_t i = 0; i < other.getNumCards(); i++)
			newDeck.deleteCard(other.getCards()[i]);
		newDeck.orderedDeck();
		return newDeck;
	}
	else
	{
		cout << "This deck is empty" << endl;
		return newDeck;
	}
}

//Remove card from deck
Deck& Deck::operator -= (const Card& other)
{
	deleteCard(other);
	orderedDeck();
	return *this;
}

//Remove deck from deck
Deck& Deck::operator -= (const Deck& other)
{
	if(getNumCards() > other.getNumCards())
	{
		for (size_t i = 0; i < other.getNumCards(); i++)
			deleteCard(other.getCards()[i]);
		orderedDeck();
		return *this;
	}
	else
	{
		cout << "Other deck is with more cards than this deck and this operation is not complete !" << endl;
		return *this;
	}
}



//Get number of cards for deck
unsigned int Deck::getNumCards() const
{
	return this->numCards;
}

//Get cards for deck
Card* Deck::getCards() const
{
	return this->cards;
}

//Set cards in deck
void Deck::setCards(const unsigned int numCards, const Card* cards)
{
	if(this->numCards > 5)
	{
		clearDeck();
	}

	if(numCards > 0)
	{
		this->cards = new Card [numCards];
		this->numCards = numCards;

		for (size_t i = 0; i < numCards; i++)
			this->cards[i] = cards[i];
	}
	else
		cout << "Cant set cards because number of cards is 0 or less!" << endl;

}


//Add card in deck and save in fiil
void Deck::addCard(Card cardForAdd, ofstream& fout)
{
	addCard(cardForAdd);
	saveDeck(fout);
}

//Add card in deck
void Deck::addCard(Card cardForAdd)
{
	bool flag = true;
	int validCards = 0;

	for (size_t i = 0; i < getNumCards(); i++)
	{
		if(!(this->cards[i].isValid()))
		{
			flag = false;
			break;
		}
		else
			validCards++;
	}

	if(flag)
	{
		const size_t temp = this->numCards;
		this->numCards *= 2;
		Card* pcards = this->cards;
		this->cards = new Card [this->numCards];
		for(size_t i = 0; i < temp; i++)
			this->cards[i] = pcards[i];
		resizeDeck(this->numCards);
		cards[temp] = cardForAdd;
	}
	else
		this->cards[validCards] = cardForAdd;
	
}

//Delete any card in deck and save in file
void Deck::deleteCard(Card cardForDelete, ofstream& fout)
{
	bool timeflag = false;
	for (size_t i = 0; i < this->numCards; i++)
	{
		if (this->cards[i] == cardForDelete)
		{
			timeflag = true;
			cards[i] = cards[this->numCards - 1];
			this->numCards -= 1;
			resizeDeck(this->numCards);
			saveDeck(fout);
		}
	}
	if(!timeflag)
		cout << "Dont have this card in this deck ! " << endl;

	if(getNumCards() < 6)
		cout << "Now this deck is not valid" << endl; 
}

//Delete any card in deck
void Deck::deleteCard(Card cardForDelete)
{
	bool timeflag = false;
	for (size_t i = 0; i < this->numCards; i++)
	{
		if (this->cards[i] == cardForDelete)
		{
			timeflag = true;
			cards[i] = cards[this->numCards - 1];
			this->numCards -= 1;
			resizeDeck(this->numCards);
			break;
		}
	}
	if(!timeflag)
		cout << "Dont have this card in this deck ! " << endl;
}


//Change any card with another card in deck
void Deck::changeCard(Card cardForChange, Card cardForRemove, ofstream& fout)
{
	bool timeflag = false;
	for (size_t i = 0; i < this->numCards; i++)
	{
		if (this->cards[i] == cardForRemove)
		{
			timeflag = true;
			this->cards[i] = cardForChange;
			saveDeck(fout);
			break;
		}
	}
	if(!timeflag)
		cout << "Dont have this card in this deck and cant do change! " << endl;
}

//Sort card in deck (initially dont have NULL cards)
void Deck::orderedDeck()
{
	for (size_t p = 0; p < getNumCards(); p++)
	{
		for (size_t i = 0; i < getNumCards() - 1 - p; i++)
		{
			if (this->cards[i].isValid() == false)
			{
					swap(this->cards[i],this->cards[i+1]);
			}
		}
	}
}

//Sort cards in deck (bigest attack)
void Deck::sortCardsByAttack()
{
	for (size_t p = 0; p < numCards; p++)
	{
		for (size_t i = 0; i < this->numCards - 1 - p; i++)
		{
			if (this->cards[i].getAttack() < this->cards[i+1].getAttack())
				swap(this->cards[i],this->cards[i+1]);
		}
	}
}

//Sort cards in deck (bigest life)
void Deck::sortCardsByLife()
{
	for (size_t p = 0; p < numCards; p++)
	{
		for (size_t i = 0; i < this->numCards - 1 - p; i++)
		{
			if (this->cards[i].getLife() < this->cards[i+1].getLife())
				swap(this->cards[i],this->cards[i+1]);
		}
	}
}

//Sort cards in deck (bigest maximum life)
void Deck::sortCardsByMaxLife()
{
	for (size_t p = 0; p < numCards; p++)
	{
		for (size_t i = 0; i < this->numCards - 1 - p; i++)
		{
			if (this->cards[i].getMaxLife() < this->cards[i+1].getMaxLife())
				swap(this->cards[i],this->cards[i+1]);
		}
	}
}

//Sort cards in deck (bigest energy)
void Deck::sortCardsByEnergy()
{
	for (size_t p = 0; p < numCards; p++)
	{
		for (size_t i = 0; i < this->numCards - 1 - p; i++)
		{
			if (this->cards[i].getEnergy() < this->cards[i+1].getEnergy())
				swap(this->cards[i],this->cards[i+1]);
		}
	}
}


//Save first 5 cards in fail
void Deck::bestCards(ofstream& fout)
{
	Deck timedeck;
	timedeck.setCards(this->numCards, this->cards);
	timedeck.orderedDeck();
	for (int i = 0; i < 5; i++)
		timedeck.cards[i].saveCard(fout);
}

//Check this deck is valid
bool Deck::isValid() const
{
	if (this->numCards < 5)
	{
		cout << "This deck is not valid because have less than 5 cards" << endl;
		return false;
	}
	else
		return true;
}

//Save deck in flow
void Deck::saveDeck(ofstream& fout) const
{
		for (size_t i = 0; i < this->numCards; i++)
		{
			this->cards[i].saveCard(fout);
		}
}

//Load deck from flow
void Deck::loadDeck(ifstream& fin)
{
		for (size_t i = 0; i < this->numCards; i++)
		{
			this->cards[i].loadCard(fin);
		}
}


//Delete all cards in deck
void Deck::clearDeck()
{
	delete [] this->cards;
	this->numCards = 0;
	this->cards = NULL;
}

//Resize this deck
void Deck::resizeDeck(unsigned int newNumCards)
{
	if(newNumCards < this->numCards)
		cout << " You delete all cards after this number" << endl;
	if(newNumCards == 0)
		clearDeck();
	else
	{
		Card* pcards = new Card [newNumCards];
		if(pcards)
		{
			for (size_t i = 0; i < this->numCards ; i++)
				pcards[i] = this->cards[i];
			delete [] this->cards;
			this->cards = pcards;
			this->numCards = newNumCards;
		}
	}
}

//Sum Attack and life of all cards in deck
int Deck::sumAttackAndLife(const Deck other)
{
	size_t sum = 0;
	for (size_t i = 0; i < numCards; i++)
	{
		sum += (other.cards[i].getAttack() + other.cards[i].getLife());
	}
	return sum;
}

//Print deck
void Deck::printDeck() const
{
	if(this->numCards != 0)
	{
		cout << "--------------------------------------------------------------------" << endl;
		cout << "New Deck:" << endl << endl;
		for (size_t i = 0; i < getNumCards(); i++)
		{
			cout << " Card " << i + 1 << endl;
			this->cards[i].printCard();
		}
	}
	else
		cout << "This deck dont have cards" << endl;
}



//Operator <<
ostream& operator << (ostream& out, const Deck& other)
{
	out << "--------------------------------------------------------------------" << endl;
	out << "New Deck:" << endl << endl;
	for (size_t i = 0; i < other.getNumCards(); i++)
	{
		out << " Card " << i + 1 << endl;
		other.getCards()[i].printCard();
	}
	return out;
}