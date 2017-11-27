////////////////////////////////////////////////
//
// Authors: Johnson Olayiwola - 17134609, Vasanth Solomon Suresh - 17102332, Berkay Ersengun - 17121264, Luis Willnat - 17105536
// Group 4 project for ED5021/EE6411 
// Date: 26 November,2017.
// Card.cpp - class modelling a single card defined by suit and rank
/////////////////////////////////////////////////

#include <iostream> 
#include <cstdlib>	//Including standard general utilities libraries. Particularly for using srand function to shuffle cards
#include <vector>	//Dynamic memmory allocation is implemented through vector as the data structure 
#include "Card.h"	//Including header files with class card
using namespace std;
// create a “blank” card
Card::Card() = default;

// constructor to create a card, setting the suit and rank
// param: Rank rank - rank of the new card
// param: Suit suit - suit of the new card
// return: none - Creates an instance of the class Card
Card::Card(Rank rank, Suit suit) : rank(rank), suit(suit) {}

// destructor to create a card, setting the suit and rank
// param: none
// return: none - Deletes the card from memory
Card::~Card() {}


// Function Definition of getRank() returns rank two=2 through to Ace
// param: none;
// return: integer rank of the card
int Card::getRank(){
	return rank;
}

// Function Definition of getSuit() return suit SPA, HRT, CLB, DIA
// param: none
// return: integer suit of the card
int Card::getSuit(){
	return suit;
}

// Mutator for rank of the card
// param: int rank - New rank of the card
// return: void
void Card::setRank(int rank){
	rank = rank;
}

// Mutator for suit of the card
// param: int suit - New suit of the card
void Card::setSuit(int suit){
	suit = suit;
}

//Stream Extraction Overloading operator function definition follows
ostream& operator<<(ostream& os, const Card& c)
{
	Rank r = c.rank;
	Suit s = c.suit;
	//os << "Rank : ";
	switch (r) {
	case Two:
		os << "Two-";
		break;
	case Three:
		os << "Three-";
		break;
	case Four:
		os << "Four-";
		break;
	case Five:
		os << "Five-";
		break;
	case Six:
		os << "Six-";
		break;
	case Seven:
		os << "Seven-";
		break;
	case Eight:
		os << "Eight-";
		break;
	case Nine:
		os << "Nine-";
		break;
	case Ten:
		os << "Ten-";
		break;
	case Jack:
		os << "Jack-";
		break;
	case Queen:
		os << "Queen-";
		break;
	case King:
		os << "King-";
		break;
	case Ace:
		os << "Ace-";
		break;
	}

	//os << " Suit : ";
	switch (s) {
	case SPA:
		os << "Spades";
		break;
	case HRT:
		os << "Heart";
		break;
	case CLB:
		os << "Club";
		break;
	case DIA:
		os << "Diamond";
		break;
	}

	return os;
}

// void displayCard()
// Prints out a string representation of the card object
// called by reference of the data structure "vector"
// param: none
// return: void
void Card::displayCard()					
{
	//Using this pointer to display sequentially the cards in the deck
	cout << *this << endl; 
}


