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


void CardGame::swapDecks(vector<Card> deck1, vector<Card> deck2){
	deck1.swap(deck2);
}

void playGame(){
	int numberSets=1, numberPlayers=2;

	cout << "---------------\n";
	cout << "GAME STARTING \n";
	cout << "---------------\n";
	cout <<  "How many sets ?\n";
	//cin >> numberSets;

	cout <<  "How many players ?\n";
	//cin >> numberPlayers;


	//Create new game
	CardGame game = CardGame(numberPlayers, numberSets);
	
	//Create shuffled Deck
	//game.shuffledDeck = Deck(numberSets);
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
	//game.getPlayers.moveAllCards(playersDeck[1],playersDeck[2]);
	
	//game.playersDeck[1].displayDeck();
	//cout << "After : \n";
	//game.swapDecks(game.playersDeck[1].getDeck(), game.playersDeck[2].getDeck());
	//game.playersDeck[1].displayDeck();

	game.playedDeck.addCard(game.shuffledDeck.getTopCard()) ;

	// First card is the one from shuffled deck
	Card topPlayedCard = game.playedDeck.getDeck()[0];
	

	int i = 0;
	//another for loop needed in here for every hand for(each hand loop)
	while (game.playersDeck[0].getNumberOfCards() != 0 || game.playersDeck[1].getNumberOfCards()!=0){
		// new turn
		i++;



		if(i == 30){
			break;
		}
		// Display the top card after all players played.
		cout << "Top card : " << topPlayedCard.getRank() << "|" << topPlayedCard.getSuit() << ".\n";


		
		if (game.shuffledDeck.getNumberOfCards() == 0){
			
			/* vector<Card> dtemp = game.shuffledDeck.getDeck();
			
			dtemp.swap(dtemp1);
			game.shuffledDeck.getDeck() = dtemp;
			game.playedDeck.getDeck() = dtemp1; */

			game.shuffledDeck = game.playedDeck;
			//game.playedDeck.createEmptyCardDeck();
			
			
			//auto iter = game.shuffledDeck.lookAtCard(0);
			while(game.playedDeck.getNumberOfCards() != 0){
				game.playedDeck.getTopCard();
				//iter++;
			}
		
			//game.shuffledDeck.moveAllCards(game.shuffledDeck, game);
		}


		//loop for each player
		for (int k = 0; k < numberPlayers; k++){		

			//loop for all cards in x player's hand 
			for (int x = 0; x < game.playersDeck[k].getNumberOfCards(); x++){
				//cout<<"suit is "<<suit<<" rank is "<<rank<<endl;
				Card playerCard = game.playersDeck[k].lookAtCard(x);

				// Check if that card can be played
				if(playerCard.getSuit() == topPlayedCard.getSuit() || playerCard.getRank() == topPlayedCard.getRank()){
					// Card can be played
					//Add that card to the played Deck and remove the card from player's hand
					game.playedDeck.addCard(game.playersDeck[k].getACard(x));

					cout << "Player " << k + 1 << " played " << playerCard.getRank() << "|" << playerCard.getSuit(); 


					// If player plays the card, then refresh the top card of the deck
					topPlayedCard = playerCard;

					// Display how many cards remaining			
					cout << " (Cards remaining : " << game.playersDeck[k].getNumberOfCards() << "). \n";


					// break for because we don't need to check the other cards of the players
					break;
				}

				// if x is the last card, then it means that there was no match, so he has to pick a new one
				if(x == game.playersDeck[k].getNumberOfCards() - 1){
					cout << "Player " << k + 1 << " picked a card";
					game.playersDeck[k].addCard(game.shuffledDeck.getTopCard());

					// Display how many cards remaining			
					cout << " (Cards remaining : " << game.playersDeck[k].getNumberOfCards() << "). \n";

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
if (game.playersDeck[1].getNumberOfCards()==0)
cout<<"player 1 wins"<<endl;
else  if (game.playersDeck[2].getNumberOfCards()==0)
cout<< "player 2 wins"<<endl;
else 
cout<<"error"<<endl;
}


int main(){
	cout<<"Hello Welcome to the Game!\n";
	playGame();
}


