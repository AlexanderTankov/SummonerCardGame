#pragma once
#include "Card.h"

class Deck
{
public:
	Deck();
	~Deck();
	Deck(const Deck& other);
	Deck(const unsigned int numCards, const Card* cards);

	bool			operator == (const Deck& other);
	bool			operator != (const Deck& other);
	bool			operator < (const Deck& other);
	bool			operator > (const Deck& other);
	bool			operator >= (const Deck& other);
	bool			operator <= (const Deck& other);
	Deck&			operator = (const Deck& other);
	Deck			operator + (const Card& other);
	Deck			operator + (const Deck& other);
	Deck&			operator += (const Card& other);
	Deck&			operator += (const Deck& other);
	Card&			operator [] (const int idx);
	Deck			operator - (const Card& other);
	Deck			operator - (const Deck& other);
	Deck&			operator -= (const Card& other);
	Deck&			operator -= (const Deck& other);

	unsigned int	getNumCards() const;
	Card*			getCards() const;

	void			setCards(const unsigned int numCards, const Card* cards);

	void			addCard(Card cardForAdd, std::ofstream& fout);
	void			addCard(Card cardForAdd);
	void			deleteCard(Card cardForDelete, std::ofstream& fout);
	void			deleteCard(Card cardForDelete);
	void			changeCard(Card cardForChange, Card cardForRemove, std::ofstream& fout);
	void			bestCards(std::ofstream& fout);
	void			orderedDeck();
	void			sortCardsByAttack();
	void			sortCardsByLife();
	void			sortCardsByMaxLife();
	void			sortCardsByEnergy();

	bool			isValid() const;
	void			saveDeck(std::ofstream& fout) const;
	void			loadDeck(std::ifstream& fin);
	void			clearDeck();
	void			resizeDeck(unsigned int newSize);
	int				sumAttackAndLife(const Deck other);
	void			printDeck() const;
	


private:
	unsigned int	numCards;
	Card*			cards;
};

std::ostream& operator << (std::ostream& out, const Deck& other);