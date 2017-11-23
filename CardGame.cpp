#include <iostream>
#include <string>
#include "Deck.h"
#include "Card.h"
#include "CardGame.h"
#include <iterator>
#include <vector>

using namespace std;


CardGame::CardGame(int numberPlayers, int numberSets) : 
numberPlayers(numberPlayers), numberSets(numberSets){}

// Destructor
CardGame::~CardGame() {}


void CardGame::setPlayers(int numberPlayers){
	//numberPlayers = numberPlayers;
}

void CardGame::setNumberSets(int numberSets){
	//numberSets = numberSets;
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

	displayCard();


	//Create new game
	CardGame game = CardGame(numberPlayers, numberSets);
	
	//Create shuffled Deck
	game.shuffledDeck = Deck(numberSets);
	game.shuffledDeck.createInitialisedCardDeck(numberSets);
	//game.shuffledDeck.shuffleDeck();

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
	for(int j = 0; j < 7; j++){
		for(int i = 0; i < numberPlayers; i++){
		
			game.playersDeck[i].addCard(game.shuffledDeck.getTopCard());
		}
	}

	//another for loop needed in here for every hand for(each hand loop)
	game.playedDeck.addCard(game.shuffledDeck.getTopCard()) ;
	int suit1,rank1,suit2,rank2;
	rank2 = game.playedDeck.lookAtCard(1).getRank();
	suit2 = game.playedDeck.lookAtCard(1).getSuit();
	for (int k =0; k<numberPlayers; k++)
	{		
			//loop for all players 
		for (int x=0; x<game.playersDeck[k].getNumberOfCards(); x++){
			 //auto card1 = game.playersDeck[k].lookAtCard(x);
			rank1 = game.playersDeck[k].lookAtCard(x).getRank();
			suit1 = game.playersDeck[k].lookAtCard(x).getSuit();	
			//cout<<"suit is "<<suit<<" rank is "<<rank<<endl;
			
			if(rank1==rank2 || suit1==suit2)
			{
				game.playedDeck.addCard(game.playersDeck[k].getACard(x));
				break;
			}
			else 
			{
				game.playersDeck[k].addCard(game.shuffledDeck.getTopCard());
				break;
			}

			}
	}	
	

	
	game.displayPlayerDecks();
	cout << "Cards left in shuffledDeck : \n";
	game.playedDeck.displayDeck();
	//game.simulateGame();

	//FINISHED

}

int main(){
	cout<<"Hello Welcome to the Game!\n";
	playGame();
}


