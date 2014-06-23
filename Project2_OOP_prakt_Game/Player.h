#pragma once
#include "Deck.h"

class Player
{
public:
	Player();

	int		getHealth() const;
	int		getMaxHealth() const;
	int		getEnergy() const;
	int		getMaxEnergy() const;
	Deck	getDeck() const;
	
	void	setHealth(const int newHealth);
	void	setEnergy(const int newEnergy);
	void	setDeck(const Deck newDeck) const;

private:
	int		ownHealth;
	int		ownMaxHealth;
	int		ownEnergy;
	int		ownMaxEnergy;
	Deck	ownDeck;
};

Player::Player()
{
	this->ownMaxHealth = 1000;
	this->ownHealth = 1000;
	this->ownMaxEnergy = 100;
	this->ownEnergy = 100;
}
