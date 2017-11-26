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

const int MAX_NUMBER_SETS = 2;
const int MAX_NUMBER_PLAYERS = MAX_NUMBER_SETS * 7;


class CardGame 
{
public:
	CardGame();

	CardGame(int numberPlayers, int numberSets);

	~CardGame();

	void displayPlayerDecks();

	void playGame();

	void dealCards();

	void createPlayersDeck();

	vector<Deck> playersDeck;

	Deck shuffledDeck;

	Deck playedDeck;


private: 
	int numberPlayers, numberSets;

};
#endif

