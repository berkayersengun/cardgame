
#ifndef __DECK_H
#define __DECK_H

#include "Card.h"
#include <vector>
#include <iostream>
#include <cstdlib>

using namespace std;

class Deck
{
private:

	enum { deckSize = 52 };
	vector<Card> deck;
	vector<Card> deckTemp;
	int setNumber{ 1 };

public:

	Deck();
	Deck(int setNumber);
	Deck( const Deck& otherDeck ); // copy constructor
	~Deck();
	void shuffleDeck();
	void displayDeck();
	void initialiseCardDeck();
	int const getNumberOfCards();
	Card getTopCard();
	Card getACard(int number);
	Card lookAtCard(int number);
	void moveAllCards();
	void addCard(Card card);

};

#endif