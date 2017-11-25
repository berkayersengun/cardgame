////////////////////////////////////////////////
//
// Cardgame 
// Authors: Johnson Olayiwola - 17134609, Vasanth Solomon Suresh - 17102332, Berkay Ersengun - 17121264, Luis Willnat - 17105536
// Group 4 project for Ed5021/EE6411 
// Date: November,2017.
/////////////////////////////////////////////////

#include <iostream> //Including standard libraries for input and output functions
#include <cstdlib>	//Including standard general utilities libraries. Particularly for using srand function to shuffle cards
#include <vector>	//Dynamic memmory allocation is implemented through vector as the data structure 
#include "Card.h"	//Including header files with class card
using namespace std;
// create a “blank” card
Card::Card() = default;

// constructor to create a card, setting the suit and rank
Card::Card(Rank rank, Suit suit) : rank(rank), suit(suit) {}

// destructor to create a card, setting the suit and rank
Card::~Card() {}

// set an existing card to a particular value
void Card::setCard(Rank rank, Suit suit)
{
	rank = rank;
	suit = suit;
}
// Function Definition of getRank() returns rank two=2 through to Ace
int Card::getRank()
{
	return rank;
}
// Function Definition of getSuit() return suit SPA, HRT, CLB, DIA
int Card::getSuit()
{
	return suit;
}
//Stream Extraction Overloading operator function definition follows
ostream& operator<<(ostream& os, const Card& c)
{
	Rank r = c.rank;
	Suit s = c.suit;
	os << "Rank : ";
	switch (r) {
	case Two:
		os << c.rank;
		break;
	case Three:
		os << c.rank;
		break;
	case Four:
		os << c.rank;
		break;
	case Five:
		os << c.rank;
		break;
	case Six:
		os << c.rank;
		break;
	case Seven:
		os << c.rank;
		break;
	case Eight:
		os << c.rank;
		break;
	case Nine:
		os << c.rank;
		break;
	case Ten:
		os << c.rank;
		break;
	case Jack:
		os << 'J';
		break;
	case Queen:
		os << 'Q';
		break;
	case King:
		os << 'K';
		break;
	case Ace:
		os << 'A';
		break;
	}

	os << " Suit : ";
	switch (s) {
	case SPA:
		os << 'S';
		break;
	case HRT:
		os << 'H';
		break;
	case CLB:
		os << 'C';
		break;
	case DIA:
		os << 'D';
		break;
	}

	return os;
}

//Funtion to display the card using this pointer
//called by reference of the data structure "vector"
void Card::displayCard() 
						
{
	//Using this pointer to display sequentially the cards in the deck
	cout << *this << endl; 
}


