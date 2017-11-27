////////////////////////////////////////////////
//
// Authors: Johnson Olayiwola - 17134609, Vasanth Solomon Suresh - 17102332, Berkay Ersengun - 17121264, Luis Willnat - 17105536
// Cardgame.h - function and vraiable  definition
// Group 4 project for ED5021/EE6411 
// Date: 26 November, 2017.
/////////////////////////////////////////////////

#ifndef CARDGAME_H
#define CARDGAME_H
#include <iostream>
using namespace std;

const int MAX_NUMBER_SETS = 10;
const int MAX_NUMBER_PLAYERS = 14;


class CardGame 
{
public:

	// Constructors of CardGame
	CardGame();
	CardGame(int numberPlayers, int numberSets);

	// Destructor of CardGame
	~CardGame();

	// CardGame methods
	void displayPlayerDecks();
	int playGame();
	void dealCards();
	void createPlayersDeck();

	// Different decks during the game
	// Decks of all players in a vector<Deck>
	vector<Deck> playersDeck;

	// The beginning shuffled Deck
	Deck shuffledDeck;

	// the deck with cards already played
	Deck playedDeck;


private: 
	// private members
	int numberPlayers, numberSets;

};
#endif

