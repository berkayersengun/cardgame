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

	void getPlayers();

	void displayPlayerDecks();

	void playGame();

	void displayTitle();

	int askNumberOfPlayers();



	vector<Deck> playersDeck;

	Deck shuffledDeck;
	Deck playedDeck;

private: 
	int numberPlayers, numberSets;

};
#endif

