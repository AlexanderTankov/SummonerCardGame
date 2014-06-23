#include <iostream>
#include "Card.h"
#include "Deck.h"

using namespace std;

int main()
{	
	/*Card a;
	//test geters (card)
	a.getAttack();
	a.getEnergy();
	a.getLife();
	//a.getSkill();

	//test printCard();
	//a.printCard();

	//test seters (card)
	char str[50] = "Pesho";
	a.setName(str);
	a.setAttack(20);
	a.setLife(100);
	//a.setSkill(str);
	a.CalculateEnergy();
	//a.printCard();

	//test constructor
	char name[30] = "The dark card";
	int attack = 40;
	int life = 200;
	//char* skill = str;
	Card b(name, attack, life);// , skill);
	b.getName();
	//b.printCard();

	//test copy constructor
	Card c (b);
	Card d (a);
	c.printCard();
	//d.printCard();

	//test save card
	ofstream out("Card.txt", ios::out | ios::binary);
	if (!out)
	{
		cout << "The file is not open";
		return 1;
	}
	c.saveCard(out);
	out.close();

	//test load card
	ifstream in("Card.txt", ios::out | ios::binary);
	if (!in)
	{
		cout << "The file is not open";
		return 1;
	}
	a.loadCard(in);
	//a.printCard();
	in.close();

	//test operator
	bool flag=false;
	if(c == d)
		flag=true;

	//test geters(deck)
	Deck Alex;
	Alex.getNumCards();
	Alex.getCards();
	//Alex.printDeck();

	Card y;
	char strname[50] = "Ivo";
	y.setName(strname);
	y.setAttack(200);
	y.setLife(300);
	y.setMaxLife(300);
	y.CalculateEnergy();

	Card brb[5];
	brb[0] = d;
	brb[1] = b;
	brb[2] = a;
	brb[3] = y;
	brb[4] = c;

	//test setter (card)
	Alex.setCards(5,brb);
	//Alex.printDeck();

	//test ordered cards
	Alex.orderedDeck();
	//Alex.printDeck();

	Alex.sortCardsByAttack();
	Alex.printDeck();
	Alex.sortCardsByEnergy();
	Alex.printDeck();
	Alex.sortCardsByLife();
	Alex.printDeck();

	//test easy constructor
	Deck Pesho(2,brb);
	//Pesho.printDeck();
	Pesho.resizeDeck(3);
	//Pesho.printDeck();

	//test copy constructor
	Deck Nikol(Alex);
	//Nikol.printDeck();

	//test clear deck
	Nikol.clearDeck(); 
	Nikol.printDeck();

	//test saveDeck
	ofstream dOut("Deck.txt", ios::out | ios::binary);
	if (!dOut)
	{
		cout << "The file is not open";
		return 1;
	}
	//test change card
	Alex.changeCard(d,c,dOut);

	//test add card 
	Alex.addCard(y,dOut);
	//Alex.printDeck();

	//test delete card
	Alex.deleteCard(y,dOut);
	//Alex.printDeck();

	Alex.saveDeck(dOut);
	dOut.close();

	//test loadDeck
	ifstream din("Deck.txt", ios::out | ios::binary);
	if (!din)
	{
		cout << "The file is not open";
		return 1;
	}
	Alex.loadDeck(din);
	//Alex.printDeck();
	din.close();

	//test IsValid();
	Alex.isValid();

	ofstream bOut("BestCard.txt", ios::out | ios::binary);
	if (!bOut)
	{
		cout << "The file is not open";
		return 1;
	}
	//test best cards
	Alex.bestCards(bOut);
	//Alex.printDeck();
	bOut.close();


	//test operators (Card)
	cout << (c == b) << endl;
	cout << (c == d) << endl;
	cout << (c != b) << endl;
	cout << (c != d) << endl;
	cout << (c < b) << endl;
	cout << (c < d) << endl;
	cout << (c > b) << endl;
	cout << (c > d) << endl;
	cout << (c >= b) << endl;
	cout << (c >= d) << endl;
	cout << (c <= b) << endl;
	cout << (c <= d) << endl;
	Card z;
	Deck test3;
	z = c;
	z.printCard();
	z -= 5;
	z.printCard();
	z += 5;
	z.printCard();
	//test3 = z + Alex;
	//test3.printDeck();
	z--;
	z.printCard();
	z++;
	z.printCard();
	--z;
	z.printCard();
	++z;
	z.printCard();
	cout << z;
	//cin >> z;
	cout << z;


	//test operators (Deck)
	Deck test1, test2;
	Deck w(Alex);
	Deck p(Pesho);
	w.printDeck();
	p.printDeck();
	cout << (w == p) << endl;
	cout << (w == Alex) << endl;
	cout << (w != Alex) << endl;
	cout << (w != p) << endl;
	cout << (w < p) << endl;
	cout << (w < Alex) << endl;
	cout << (w > p) << endl;
	cout << (w > Alex) << endl;
	cout << (w >= p) << endl;
	cout << (w >= Alex) << endl;
	cout << (w <= p) << endl;
	cout << (w <= Alex) << endl;
	//w = p;
	//w.printDeck();
	test1 = w + a;
	test1.printDeck();
	test2 = w + p;
	test2.printDeck();
	w += a;
	w.printDeck();
	w += p;
	w.printDeck();
	w += w;
	w.printDeck();
	cout << w;
	cout << w[4];
	test1 = w - a;
	test1.printDeck();
	test2 = w - p;
	test2.printDeck();
	w -= a;
	w.printDeck();
	w -= p;
	w.printDeck();
	*/
	return 0;
}
