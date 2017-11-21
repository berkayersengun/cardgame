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

void CardGame::simulateGame(){
	// for(int i = 0; i < gameDeck.size(); i++){
		
	// }
}


void createShuffledDeck(){
	
}


void playGame(){
	int numberSets, numberPlayers;

	cout << "---------------\n";
	cout << "GAME STARTING \n";
	cout << "---------------\n";
	cout <<  "How many sets ?\n";
	cin >> numberSets;

	cout <<  "How many players ?\n";
	cin >> numberPlayers;


	//Create new game
	CardGame game = CardGame(numberPlayers, numberSets);

	//Create shuffled Deck
	game.shuffledDeck = Deck(numberSets);
	game.shuffledDeck.createInitialisedCardDeck(numberSets);
	game.shuffledDeck.shuffleDeck();

	//Create empty deck for played cards.
	game.playedDeck = Deck();


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
			game.playersDeck[i].addCard(game.shuffledDeck.getTopCard());
		}
	}

	game.displayPlayerDecks();

	cout << "Cards left in shuffledDeck : \n";
	game.shuffledDeck.displayDeck();

	game.simulateGame();

	//FINISHED

}

int main(){
	playGame();
}


