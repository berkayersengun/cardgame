#ifndef CARD_H
#define CARD_H

enum Rank {Ace=1, Two, Three, Four, Five, Six, Seven, Eight, Nine, Ten, Jack, Queen, King};
enum Suit { Spades, Hearts, Clubs, Diamonds};

class Card {
public:
	// create a “blank” card
	Card();
	// constructor to create a card, setting the suit and rank
	Card(int suit, int rank);
	// destructor
	~Card();

	// return the point value of the card. Ace = 1, 2 thru 10, face cards can be 11, 12, 
	int getValue();
	// set an existing card to a particular value
	void setCard(int suit, int rank);

	// display the card
	void printCard();

private:
	int rank;
	int suit;

};

#endif 