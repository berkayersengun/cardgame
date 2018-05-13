////////////////////////////////////////////////
//
// Author: Berkay Ersengun
// Date: 26 November,2017.
// Card.cpp - class modelling a single card defined by suit and rank
/////////////////////////////////////////////////


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

	enum { deckSize = 52 }; // Size of cards which never changes.
	vector<Card> deck; // deck of cards
	
	int setNumber = 1;

	int MIN_SET_CARDS = 1; // Arbitrary number of minimum set of cards
	int MAX_SET_CARDS = 10; // Arbitrary number of maximum set of cards

public:
	// member methods

	// Constructor of deck
	Deck();
	Deck(int setNumber);
	Deck( const Deck& otherDeck ); // copy constructor

	//destructor of deck
	~Deck();


	// methods to manipulate the deck
	void shuffleDeck();
	void displayDeck();
	void createEmptyCardDeck();
	void createInitialisedCardDeck(int setNumber);
	void initialiseCardDeck(int setNumber,Deck duck);
	void moveAllCards(Deck &mainDeck, Deck &copyDeck);
	void deleteCardDeck();
	int const getNumberOfCards();
	Card getTopCard();
	Card getACard(int number);
	Card lookAtCard(int number);
	void addCard(Card card);

	// accessor methods
	// accessor for deck
	vector<Card> getDeck();

	// mutator methods
	// mutator for deck
	void setDeck(vector<Card> deck);	
};

#endif