#include <iostream>
#include "Card.h"
#include <string>

using namespace std;
// create a “blank” card
Card::Card() : rank(0), suit(0)
{

}

// constructor to create a card, setting the suit and rank
Card::Card(int s, int r)
{
	rank = r;
	suit = s;
}

// destructor to create a card, setting the suit and rank
Card::~Card()
{
}

// set an existing card to a particular value
void Card::setCard(int s, int r)
{
	rank = r;
	suit = s;
}

// return the point value of the card. Ace = 1, 2 thru 10, face cards can be 11, 12, 
int Card::getValue()
{
	return rank;
}

void Card::printCard()
{
   cout << "Card is rank : " << suit << " and suit : " << rank << endl;
}