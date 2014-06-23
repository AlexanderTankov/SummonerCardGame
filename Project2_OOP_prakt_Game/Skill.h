#pragma once
#include "Card.h"
class Player;

enum Type
{
	RESTORE_HEALTH_FROM_CARD,
	RESTORE_ENERGY_FROM_HERO,
	REMOVE_HEALTH_FROM_HERO
};

class Skill
{
public:
	virtual ~Skill();

	virtual void useEffect(Card& target, Player& other) = 0;
	virtual bool isUsed() = 0;
	virtual Type GetType() const = 0;
	virtual Skill* Clone() const = 0;
};

Skill::~Skill()
{
}