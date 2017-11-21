#include <iostream>
#include <string>
#include "Deck.h"
#include "Card.h"
#include "CardGame.h"

using namespace std;


CardGame::CardGame(int numberPlayers, int numberSets) : 
numberPlayers(numberPlayers), numberSets(numberSets){}

// Destructor
CardGame::~CardGame() {}


void CardGame::setPlayers(int numberPlayers){
	numberPlayers = numberPlayers;
}

void CardGame::setNumberSets(int numberSets){
	numberSets = numberSets;
}

void CardGame::displayPlayerDecks(){
	for(int i = 0; i < numberPlayers; i++){
		cout << "Player " << i + 1 << " : \n";
		playersDeck[i].displayDeck();
	}
}


void CardGame::foobar(){
	cout << " I am in CardGame \n";
}


int main(){

	int numberSets, numberPlayers;
	cout << "---------------\n";
	cout << "GAME STARTING \n";
	cout << "---------------\n";
	cout <<  "How many sets ?\n";
	cin >> numberSets;

	cout <<  "How many players ?\n";
	cin >> numberPlayers;


	CardGame game = CardGame(numberPlayers, numberSets);
	game.foobar();


	// Create whole card game 
	Deck gameDeck = Deck(numberSets);

	gameDeck.createInitialisedCardDeck(numberSets);
	gameDeck.shuffleDeck();



	// Create n decks (where n are number of players) <-- In function as well ?


	for(int i = 0; i < numberPlayers; i++){
		Deck playerDeck = Deck();
		playerDeck.createEmptyCardDeck();

		game.playersDeck.push_back(playerDeck);
	}

	// Card card = Card(Four, SPA);
	// playersDeck[0].addCard(card);
	// playersDeck[0].displayDeck();

	// Give each player 7 cards <-- Put that in function later
	for(int i = 0; i < numberPlayers; i++){
		for(int j = 0; j < 7; j++){
			game.playersDeck[i].addCard(gameDeck.getTopCard());
		}
	}

	game.displayPlayerDecks();

}

