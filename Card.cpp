#include <iostream>
#include <cstdlib>
#include <vector>
#include "Card.h"

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

// return rank two=2 through to Ace
int Card::getRank()
{
	return rank;
}
// return suit SPA, HRT, CLB, DIA
int Card::getSuit()
{
	return rank;
}

std::ostream& operator<<(std::ostream& os, const Card& c)
{
	Rank r = c.rank;
	Suit s = c.suit;
	os << "Rank : ";
	switch (r) {
	case Two:
		os << '2';
		break;
	case Three:
		os << '3';
		break;
	case Four:
		os << '4';
		break;
	case Five:
		os << '5';
		break;
	case Six:
		os << '6';
		break;
	case Seven:
		os << '7';
		break;
	case Eight:
		os << '8';
		break;
	case Nine:
		os << '9';
		break;
	case Ten:
		os << '10';
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

void Card::displayCard()
{
   cout << *this << endl;
}

int main() 
{
	Rank r(Ace);
	cout  << "The card rank is " << r << endl;
	vector<Card> deck;
	// add standard 52 cards to deck
	for (int suit = Suit::SPA; suit <= Suit::DIA; ++suit) {
    	for ( int rank = Rank::Ace; rank >= Rank::Two; rank--) {
            deck.push_back(Card(static_cast<Rank>(rank), static_cast<Suit>(suit)));
        }
	}
	for (vector<Card>::iterator i = deck.begin(); i != deck.end(); ++i) i->displayCard();
	return EXIT_SUCCESS;
}