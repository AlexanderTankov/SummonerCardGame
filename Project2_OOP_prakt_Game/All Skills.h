#pragma once
#include "Player.h"
#include "Skill.h"

class RestoreHealthFromCard : public Skill
{
public:
	RestoreHealthFromCard() {this->used = false;}
	virtual ~RestoreHealthFromCard() {}

	virtual void useEffect(Card& target, Player& other) {target.setLife(target.getMaxLife()); this->used = true;}
	virtual bool isUsed() {return this->used;}
	virtual Type GetType() const {return RESTORE_HEALTH_FROM_CARD;}
	virtual Skill* Clone() const {return new RestoreHealthFromCard(*this);}
private:
	bool used;
};

class RestoreEnergyFromHero : public Skill
{
public:
	RestoreEnergyFromHero() {this->used = false;}
	virtual ~RestoreEnergyFromHero() {}

	virtual void useEffect(Card& target, Player& other) {other.setEnergy(other.getMaxEnergy()); this->used = true;}
	virtual bool isUsed() {return this->used;}
	virtual Type GetType() const {return RESTORE_ENERGY_FROM_HERO;}
	virtual Skill* Clone() const {return new RestoreEnergyFromHero(*this);}
private:
	bool used;
};


class RemoveHealthFromHero : public Skill
{
public:
	RemoveHealthFromHero() {this->used = false;}
	~RemoveHealthFromHero() {}

	virtual void useEffect(Card& target, Player& other) {other.setHealth(other.getHealth() - target.getAttack()); this->used = true;}
	virtual bool isUsed() {return this->used;}
	virtual Type GetType() const {return REMOVE_HEALTH_FROM_HERO;}
	virtual Skill* Clone() const {return new RemoveHealthFromHero(*this);}
private:
	bool used;
};