
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
	//int setNumber{ 1 };
	int setNumber=1;

	int MIN_SET_CARDS = 1;
	int MAX_SET_CARDS = 2;

public:

	Deck();
	Deck(int setNumber);
	Deck( const Deck& otherDeck ); // copy constructor
	~Deck();
	void shuffleDeck();
	void displayDeck();
	void createEmptyCardDeck();
	void createInitialisedCardDeck(int setNumber);
	void initialiseCardDeck(int setNumber,Deck duck);
	void deleteCardDeck(Deck duck);
	int const getNumberOfCards();
	Card getTopCard();
	Card getACard(int number);
	Card lookAtCard(int number);
	void moveAllCards();
	void addCard(Card card);
	
};

#endif