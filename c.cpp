////////////////////////////////////////////////
//
// Author: Berkay Ersengun
// Date: 26 November,2017.
// c.cpp
/////////////////////////////////////////////////

#include <string>
#include <iostream>
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



void CardGame::displayPlayerDecks(){
	for(int i = 0; i < numberPlayers; i++){
		cout << "Player " << i + 1 << " : \n";
		playersDeck[i].displayDeck();
	}
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
	game.shuffledDeck.createEmptyCardDeck();
	game.shuffledDeck.createInitialisedCardDeck(numberSets);
	game.shuffledDeck.shuffleDeck();

	//Create empty deck for played cards.
	//game.playedDeck = Deck();
	game.playedDeck.createEmptyCardDeck();
	// Create n decks (where n are number of players) <-- In function as well ?
	for(int i = 0; i < numberPlayers; i++){
		Deck playersDeck = Deck();
		playersDeck.createEmptyCardDeck();

		game.playersDeck.push_back(playersDeck);
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
	
	game.playedDeck.addCard(game.shuffledDeck.getTopCard()) ;	



	
	//another for loop needed in here for every hand for(each hand loop)
	while (game.playersDeck[1].getNumberOfCards()!=0 || game.playersDeck[2].getNumberOfCards()!=0){

		game.playedDeck.addCard(game.shuffledDeck.getTopCard()) ;

		int suit1,rank1,suit2,rank2;
		rank2 = game.playedDeck.lookAtCard(1).getRank();
		suit2 = game.playedDeck.lookAtCard(1).getSuit();

		if (game.shuffledDeck.getNumberOfCards() == 0){
			game.shuffledDeck = game.playedDeck;
			game.shuffledDeck.getTopCard();

			//removes 2nd card till one card left. which we will have first card remain in the deck		
			while(game.playedDeck.getNumberOfCards() != 1){
				game.playedDeck.getACard(1);
				
			}
		}
		//loop for each player
		for (int k =0; k<numberPlayers; k++)
		{		
				//loop for all cards in x player's hand 
			for (int x=0; x<game.playersDeck[k].getNumberOfCards(); x++){
				
				rank1 = game.playersDeck[k].lookAtCard(x).getRank();
				suit1 = game.playersDeck[k].lookAtCard(x).getSuit();	
				//cout<<"suit is "<<suit<<" rank is "<<rank<<endl;
				
				if(rank1==rank2 || suit1==suit2)
				{
					game.playedDeck.addCard(game.playersDeck[k].getACard(x));
					break;

				}
				 
				if (x==game.playersDeck[k].getNumberOfCards()-1)
				{
					game.playersDeck[k].addCard(game.shuffledDeck.getTopCard());
					break;
				}

				}
	
	
		}
	}			
	
	// game.displayPlayerDecks();
	// cout << "Cards left in playeddeck : \n";
	// game.playedDeck.displayDeck();
	// cout << "Cards left in shuffledDeck : \n";
	// game.shuffledDeck.displayDeck();
	//game.simulateGame();

	//FINISHED
if (game.playersDeck[0].getNumberOfCards()==0)
cout<<"player 1 wins"<<endl;
else  if (game.playersDeck[1].getNumberOfCards()==0)
cout<< "player 2 wins"<<endl;
else 
cout<<"error"<<endl;
}


int main(){
	cout<<"Hello Welcome to the Game!\n";
	playGame();
}


