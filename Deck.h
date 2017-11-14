
#ifndef __DECK_H
#define __DECK_H

#include "Card.h"
#include <iostream>
#include <cstdlib>

using namespace std;

class Deck
{
private:
  
	// enum { HEARTS = 1, SPADES, DIAMONDS, CLUBS, ERR };
	// enum { ACE = 1, TEN = 10, JACK = 11, QUEEN = 12, KING = 13 };
	// enum { DECK_SZ = 52 };

	int deckSize;
	
public:
	
	Deck();
	~Deck();
	void shuffleDeck();
	void printDeck();

};

#endif