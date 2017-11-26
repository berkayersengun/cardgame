////////////////////////////////////////////////
//
// Authors: Johnson Olayiwola - 17134609, Vasanth Solomon Suresh - 17102332, Berkay Ersengun - 17121264, Luis Willnat - 17105536
// Cardgame.cpp - class to simulate the actually card game
// Group 4 project for ED5021/EE6411 
// Date: 26 November, 2017.
/////////////////////////////////////////////////

#include <string>
#include <iostream>
#include "Deck.h"
#include "Card.h"
#include "CardGame.h"
#include <iterator>
#include <vector>

using namespace std;

// Constructor
CardGame::CardGame(int numberPlayers, int numberSets) : 
numberPlayers(numberPlayers), numberSets(numberSets){}

// Destructor
CardGame::~CardGame() {}

// Displays the card for each player
void CardGame::displayPlayerDecks()
{
	for(int i = 0; i < numberPlayers; i++){
		cout << "Player " << i + 1 << " : \n";
		playersDeck[i].displayDeck();
	}
}

void displayTitle()
{
	cout << "•#•#•#•#•#•#• Hello and welcome to the game ! •#•#•#•#•#•#•\n";

	cout << "---------------\n";
	cout << "GAME STARTING \n";
	cout << "---------------\n";
}
// Input number of player
int askNumberOfPlayers()
{
	int players = -1;
	while(players <= 0 || players > MAX_NUMBER_PLAYERS){
		cout <<  "How many players for the game ? (min: 0, max: " << MAX_NUMBER_PLAYERS << ").\n";
		cin >> players;
		if(!cin){
			//Check if input is string not working yet
			cout << "WTf";
			players = -1;
			cin.clear();
		}
	}
	return players;
}
// input number of sets to use in the game
int askNumberOfSets()
{
	int sets = -1;

	while(sets <= 0 || sets > MAX_NUMBER_SETS){
		cout <<  "How many sets of cards ? (min: 1, max:" << MAX_NUMBER_SETS << ").\n";
		cin >> sets;
		if(!cin){
			//Check if input is string not working yet
			cout << "WTf";
			sets = -1;
			cin.clear();
		}
	}
	return sets;
}

void playGame()
{
	int numberSets, numberPlayers;

	displayTitle();

	numberSets = askNumberOfSets();
	
	numberPlayers = askNumberOfPlayers();

	//Create new game
	CardGame game = CardGame(numberPlayers, numberSets);

	//Create shuffled Deck
	game.shuffledDeck.createEmptyCardDeck();
	game.shuffledDeck.createInitialisedCardDeck(numberSets);
	game.shuffledDeck.shuffleDeck();

	//Create empty deck for played cards.
	game.playedDeck.createEmptyCardDeck();
	// Create n decks (where n are number of players) 
	for(int i = 0; i < numberPlayers; i++){
		Deck playersDeck = Deck();
		playersDeck.createEmptyCardDeck();

		game.playersDeck.push_back(playersDeck);
	}

	// Give each player 7 cards <-- Put that in function later
	for(int j = 0; j < 7; j++){
		for(int i = 0; i < numberPlayers; i++){
			game.playersDeck[i].addCard(game.shuffledDeck.getTopCard());
		}
	}
	
	// First card is the one from shuffled deck
	game.playedDeck.addCard(game.shuffledDeck.getTopCard()) ;
	Card topPlayedCard = game.playedDeck.getDeck()[0];

	int turnCounter = 0;
	//another for loop needed in here for every hand for(each hand loop)
	while (turnCounter != 100){

		// Display the top card after all players played.
		cout << "=============\n Turn nº " << turnCounter + 1 << "\n=============" << endl;
		cout << "Top card : ";
		topPlayedCard.displayCard();
		

		//loop for each player
		for (int k = 0; k < numberPlayers; k++){
		
			cout << "Player " <<k+1<<" has " << game.playersDeck[k].getNumberOfCards() << " cards : ";
			game.playersDeck[k].displayDeck();
					
			//loop for all cards in x player's hand 
			for (int x = 0; x < game.playersDeck[k].getNumberOfCards(); x++){
				Card playerCard = game.playersDeck[k].lookAtCard(x);
				// Check if that card can be played
				

				if(playerCard.getSuit() == topPlayedCard.getSuit() || playerCard.getRank() == topPlayedCard.getRank()){
					// Card can be played Add that card to the played Deck and remove the card from player's hand
					game.playedDeck.addCard(game.playersDeck[k].getACard(x));
					cout << "Player " << k + 1 << " played ";
					playerCard.displayCard(); 
					cout << "Player " << k + 1<<" has " << game.playersDeck[k].getNumberOfCards() << " cards." << endl;
					// If player plays his card, then refresh the top card of the played deck
					topPlayedCard = playerCard;
					
					// Check if the player[k] now has 0 card and end game if true
					if (game.playersDeck[k].getNumberOfCards() == 0){
						cout << "••• Player " << k + 1 << " wins •••\nGame Over!\n" << endl;
						exit(1);
					}
					cout << "Top card : ";
					topPlayedCard.displayCard();
										
					break;
				}
				
				// if x is the last card, then it means that there was no match, so player[k] has to pick a new card from the shuffled deck
				if(x == game.playersDeck[k].getNumberOfCards() - 1){
					// check if the shuffled deck is empty before picking new card
					if (game.shuffledDeck.getNumberOfCards() == 0){
						
						game.shuffledDeck.moveAllCards(game.playedDeck);
						game.shuffledDeck.getTopCard(); 
						while(game.playedDeck.getNumberOfCards()!= 1){
									game.playedDeck.getACard(1);
									
						}
						// Shuffle Cards after swapping
						game.shuffledDeck.shuffleDeck();
					}
					game.playersDeck[k].addCard(game.shuffledDeck.getTopCard());
					cout << "Player " << k + 1 << " picked a card from the shuffled deck."<<endl;

					// Display how many cards remaining			
					//cout << " (Cards remaining : " << game.playersDeck[k].getNumberOfCards() << "). \n";
					cout<< "Player "<< k + 1 <<" has " << game.playersDeck[k].getNumberOfCards()<<" cards : " ;
					game.playersDeck[k].displayDeck();
					
					break;
				}
			}
		}
	turnCounter++;
	cout << endl;
	}		
	cout << "Game ends as a draw, there was no winner." << endl;
}

int main()
{
	playGame();
}


