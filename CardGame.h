#ifndef CARDGAME_H
#define CARDGAME_H
#include <iostream>
using namespace std;


class CardGame {
public:
	CardGame();

	CardGame(int numberPlayers, int numberSets);

	~CardGame();

	void getPlayers();

	void displayPlayerDecks();

	void playGame();

	void terminateGame();

	vector<Deck> playersDeck;

	Deck shuffledDeck;
	Deck playedDeck;
private: 
	int numberPlayers, numberSets;

};
#endif

