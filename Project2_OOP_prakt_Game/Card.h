#pragma once
#include <fstream>

class Skill;
class Assasin;
class Guard;

class Card
{
public:
	Card();
	~Card();
	Card(const Card& other);
	Card(const char* Name, const unsigned int Attack, const unsigned int MaxLife, const Skill* ownSkill);

	friend Assasin;
	friend Guard;

	bool			operator == (const Card& other);
	bool			operator != (const Card& other);
	bool			operator < (const Card& other);
	bool			operator > (const Card& other);
	bool			operator >= (const Card& other);
	bool			operator <= (const Card& other);
	Card&			operator = (const Card& other);
	Card&			operator += (const int other);
	Card&			operator -= (const int other);
	//Deck			operator + (const Deck& other);
	const Card&		operator ++ ();
	const Card&		operator -- ();
	const Card		operator ++ (int);
	const Card		operator -- (int);

	char*			getName() const;
	unsigned int	getAttack() const;
	unsigned int	getLife() const;
	unsigned int	getMaxLife() const;
	double			getEnergy() const;
	Skill*			getOwnSkill() const;//
	
	void			setName(const char* Name);
	void			setAttack(const unsigned int Attack);
	void			setLife(const unsigned int Life);
	void			setMaxLife(const size_t MaxLife); 
	void			setSkill(const Skill* ownSkill);//
	
	bool			isValid() const;
	void			CalculateEnergy();
	void			printCard() const;
	void			saveCard(std::ofstream& fout) const;
	Card			loadCard(std::ifstream& fin);

private:
	char*			Name;
	unsigned int	Attack;
	unsigned int	Life;
	unsigned int	MaxLife; 
	double			Energy;
	Skill*			ownSkill;
};

std::ostream& operator << (std::ostream& out, const Card& other);
std::istream& operator >> (std::istream& in, Card& other);