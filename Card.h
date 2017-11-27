////////////////////////////////////////////////
//
// Authors: Johnson Olayiwola - 17134609, Vasanth Solomon Suresh - 17102332, Berkay Ersengun - 17121264, Luis Willnat - 17105536
// Group 4 project for ED5021/EE6411 
// Date: 26 November,2017.
// Card.cpp - class modelling a single card defined by suit and rank
/////////////////////////////////////////////////


#ifndef CARD_H //Creating Header file for class card
#define CARD_H
#include <iostream>
using namespace std;

enum Rank {Two=2, Three, Four, Five, Six, Seven, Eight, Nine, Ten, Jack, Queen, King, Ace}; //Declaring variable Rank of type ENUM
enum Suit {SPA, HRT, CLB, DIA}; //Declaring variable Suit of type ENUM

class Card {
public:
	// create a “blank” card
	Card();
	// constructor to create a card, setting the suit and rank
	Card(Rank rank, Suit suit);
	// destructor
	~Card();

	// return rank two=2 through to Ace 
	// return suit SPA, HRT, CLB, DIA


	// Accessor methods
	// accessor for suit
	int getSuit();
	// accessor for rank
	int getRank();

	// Mutator methods
	// mutator for suit
	void setSuit(int suit);

	// mutator for rank
	void setRank(int rank);
	

	// display the card
	void displayCard();

	friend ostream& operator<<(ostream&, const Card &); // Stream extraction overloading function prototype
private:
	// private attributes
	Rank rank; // rank of the card
	Suit suit; // suit of the card

};
#endif 