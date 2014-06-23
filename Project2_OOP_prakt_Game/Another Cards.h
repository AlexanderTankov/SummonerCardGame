#pragma once
#include "Card.h"
#include "All Skills.h"

class Assasin : public Card
{
public:
	Assasin();
};

Assasin::Assasin() : Card()
{
	this->ownSkill = new RemoveHealthFromHero;
}

class Guard : public Card
{
public:
	Guard();
};
Guard::Guard() : Card()
{
}
