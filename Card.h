#ifndef CARD_H
#define CARD_H
#include <iostream>
using namespace std;

enum Rank {Two=2, Three, Four, Five, Six, Seven, Eight, Nine, Ten, Jack, Queen, King, Ace};
enum Suit {SPA, HRT, CLB, DIA};

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
	int getSuit();
	int getRank();

	// set an existing card to a particular value
	void setCard(Rank rank, Suit suit);

	// display the card
	void displayCard();

	// Overload the "==" and "!=" conparison operators to compare cards
	//friend bool operator==(const Card& a, const Card& b);

	//friend bool operator!=(const Card& a, const Card& b);

	// overload output stream operator
	friend ostream& operator<<(ostream&, const Card &);
	

private:
	Rank rank;
	Suit suit;

};

#endif 