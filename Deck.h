
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
	
	//int setNumber{ 1 };
	int setNumber=1;

	int MIN_SET_CARDS = 1;
	int MAX_SET_CARDS = 10;

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
	void moveAllCards(Deck copyDeck);
	void deleteCardDeck();
	int const getNumberOfCards();
	Card getTopCard();
	Card getACard(int number);
	Card lookAtCard(int number);
	void addCard(Card card);
	vector<Card> getDeck();
	void setDeck(vector<Card> deck);	
};

#endif