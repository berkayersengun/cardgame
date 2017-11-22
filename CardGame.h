#ifndef CARDGAME_H
#define CARDGAME_H
#include <iostream>
using namespace std;


class CardGame {
public:
	CardGame();

	CardGame(int numberPlayers, int numberSets);

	~CardGame();

	void setPlayers(int numberPlayers);
	void setNumberSets(int numberSets);

	void getPlayers();

	void displayPlayerDecks();

	void simulateGame();

	void createShuffledDeck();

	void playGame();

	vector<Deck> playersDeck;

	Deck shuffledDeck;
	Deck playedDeck;

private: 
	int numberPlayers, numberSets;

};
#endif
