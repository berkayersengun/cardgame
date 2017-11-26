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
	int getSuit();// member methods of class Card
	int getRank();// member methods of class Card

	

	// display the card
	void displayCard();

	friend ostream& operator<<(ostream&, const Card &); // Stream extraction overloading function prototype
private:
	Rank rank;
	Suit suit;

};
#endif 