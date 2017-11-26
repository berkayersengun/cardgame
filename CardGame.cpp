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

// Give each player 7 cards 
void CardGame::dealCards()
{
	for(int j = 0; j < 7; j++){
		for(int i = 0; i < numberPlayers; i++){
			playersDeck[i].addCard(shuffledDeck.getTopCard());
		}
	}
}

// Create a vector to collect store the card decks of all players in the game
void CardGame::createPlayersDeck()
{
	for(int i = 0; i < numberPlayers; i++){
		Deck newPlayerDeck = Deck();
		newPlayerDeck.createEmptyCardDeck();
		playersDeck.push_back(newPlayerDeck);
	}
}
void CardGame::playGame()
{
	//Create shuffled Deck
	shuffledDeck.createEmptyCardDeck();
	shuffledDeck.createInitialisedCardDeck(numberSets);
	shuffledDeck.shuffleDeck();

	//Create empty deck for played cards.
	playedDeck.createEmptyCardDeck();
	// Create n decks (where n are number of players) 
	createPlayersDeck();

	// Give each player 7 cards
	dealCards();
	
	// First card is the one from shuffled deck
	playedDeck.addCard(shuffledDeck.getTopCard()) ;
	Card topPlayedCard = playedDeck.getDeck()[0];

	int turnCounter = 0;
	//another for loop needed in here for every hand for(each hand loop)
	while (turnCounter != 100){

		// Display the top card after all players played.
		cout << "=============\n Turn nº " << turnCounter + 1 << "\n=============" << endl;
		cout << "Top card : ";
		topPlayedCard.displayCard();
		

		//loop for each player
		for (int k = 0; k < numberPlayers; k++){
		
			cout << "Player " <<k+1<<" has " << playersDeck[k].getNumberOfCards() << " card(s) : ";
			playersDeck[k].displayDeck();
					
			//loop for all cards in x player's hand 
			for (int x = 0; x < playersDeck[k].getNumberOfCards(); x++){
				Card playerCard = playersDeck[k].lookAtCard(x);
				// Check if that card can be played
				

				if(playerCard.getSuit() == topPlayedCard.getSuit() || playerCard.getRank() == topPlayedCard.getRank()){
					// Card can be played Add that card to the played Deck and remove the card from player's hand
					playedDeck.addCard(playersDeck[k].getACard(x));
					cout << "Player " << k + 1 << " played ";
					playerCard.displayCard(); 
					cout << "Player " << k + 1<<" has " << playersDeck[k].getNumberOfCards() << " card(s)." << endl;
					// If player plays his card, then refresh the top card of the played deck
					topPlayedCard = playerCard;
					
					// Check if the player[k] now has 0 card and end game if true
					if (playersDeck[k].getNumberOfCards() == 0){
						cout << "••• Player " << k + 1 << " wins •••\nGame Over!\n" << endl;
						exit(1);
					}
					cout << "Top card : ";
					topPlayedCard.displayCard();
										
					break;
				}
				
				// if x is the last card, then it means that there was no match, so player[k] has to pick a new card from the shuffled deck
				if(x == playersDeck[k].getNumberOfCards() - 1){
					// check if the shuffled deck is empty before picking new card
					if (shuffledDeck.getNumberOfCards() == 0){
						
						shuffledDeck.moveAllCards(playedDeck);
						shuffledDeck.getTopCard(); 
						while(playedDeck.getNumberOfCards()!= 1){
									playedDeck.getACard(1);
									
						}
						// Shuffle Cards after swapping
						shuffledDeck.shuffleDeck();
					}
					playersDeck[k].addCard(shuffledDeck.getTopCard());
					cout << "Player " << k + 1 << " picked a card from the shuffled deck."<<endl;

					// Display how many cards remaining			
					//cout << " (Cards remaining : " << game.playersDeck[k].getNumberOfCards() << "). \n";
					cout<< "Player "<< k + 1 <<" has " << playersDeck[k].getNumberOfCards()<<" cards : " ;
					playersDeck[k].displayDeck();
					
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
	int numberSets, numberPlayers;
	cout << "•#•#•#•#•#•#• Hello and welcome to the game ! •#•#•#•#•#•#•\n";
	cout << "---------------\nGAME STARTING\n---------------\n";
	
	cout <<  "How many sets of cards ? (min: 1, max:" << MAX_NUMBER_SETS << ").\n";
	cin >> numberSets;
		
	do {
		if(numberSets<0 || numberSets>10){
		cout << "Number of Sets is outside allowed range, please renter" << endl;
		cin >> numberSets;
		}
		 if(!cin.good())

        {

		cout<<"Invalid input, Please enter a number specified for sets of cards : "<<endl;
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n' );
		cin >> numberSets;

        }

	}
	while(numberSets<0 || numberSets>10 ||!cin.good()); 

	if(numberSets==1)
	{
	cout <<  "How many players in the game ? (min: 2, max:" << 7 << ").\n";
	cin >> numberPlayers;
	}
	else
	{
	cout <<  "How many players in the game ? (min: 2, max:" << MAX_NUMBER_PLAYERS << ").\n";
	cin >> numberPlayers;
	}

	do 
	{
		if (numberSets==1 && numberPlayers>7){
			cout<<"For one set of cards the number of player can be maximum 7, please re-enter: "<<endl;
			cin >> numberPlayers;	
		}
		if(!cin.good())

        {

		cout<<"Invalid input, Please enter a number specified for number of players : "<<endl;
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n' );
		cin >> numberSets;

        }
		
		else if (numberPlayers<2 || numberPlayers> 14){
			cout << "Number of Players is outside allowed range, please re-enter: " << endl;
			cin >> numberPlayers;
		}
		
	}
	while(numberPlayers<2 || numberPlayers> 14 || (numberSets==1 && numberPlayers>7) || !cin.good());
	CardGame game = CardGame(numberPlayers, numberSets);
	game.playGame();
	//game.shuffledDeck.createInitialisedCardDeck(1);
   // game.shuffledDeck.displayDeck();
//	game.shuffledDeck.deleteCardDeck();
//	game.shuffledDeck.displayDeck();
//	cout << game.shuffledDeck.getNumberOfCards() << endl;
}