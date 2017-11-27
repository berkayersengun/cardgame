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
#include <algorithm>
#include <limits>

using namespace std;

// Constructor of CardGame
CardGame::CardGame(int numberPlayers, int numberSets) : 
numberPlayers(numberPlayers), numberSets(numberSets){}

// Destructor of CardGame
CardGame::~CardGame() {}

// displayPlayerDecks()
// Displays the card for each player
// param: none
// return: void
void CardGame::displayPlayerDecks(){
	for(int i = 0; i < numberPlayers; i++){
		cout << "Player " << i + 1 << " : \n";
		playersDeck[i].displayDeck();
	}
}

// dealCards()
// Give each player 7 cards 
// param: none
// return: void
void CardGame::dealCards(){
	for(int j = 0; j < 7; j++){
		for(int i = 0; i < numberPlayers; i++){
			playersDeck[i].addCard(shuffledDeck.getTopCard());
		}
	}
}

// createPlayersDeck()
// Create a vector to collect store the card decks of all players in the game
// param: none
// return: void
void CardGame::createPlayersDeck(){
	for(int i = 0; i < numberPlayers; i++){
		Deck newPlayerDeck = Deck();
		newPlayerDeck.createEmptyCardDeck();
		playersDeck.push_back(newPlayerDeck);
	}
}

// playGame()
// Plays the actual game
// param: none
// return: void
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
						//with moveallcards method all card copied from playeddeck to shuffled deck 
						shuffledDeck.
						moveAllCards(playedDeck);
						//deletion of playeddeck 
						playedDeck.deleteCardDeck();
						//get the top card and erase from shuffleddeck then move it to playeddeck
						playedDeck.addCard(shuffledDeck.getTopCard());

						// Shuffle Cards after swapping
						shuffledDeck.shuffleDeck();
					}
					playersDeck[k].addCard(shuffledDeck.getTopCard());
					cout << "Player " << k + 1 << " picked a card from the shuffled deck." << endl;

					// Display how many cards remaining			
					//cout << " (Cards remaining : " << game.playersDeck[k].getNumberOfCards() << "). \n";
					cout<< "Player "<< k + 1 <<" has " << playersDeck[k].getNumberOfCards() << " cards : " ;
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


// main()
// Main function of the game
// param: none
// return: int - if error or not
int main(){
	int numberSets, numberPlayers;

	// Display intro
	cout << "•#•#•#•#•#•#• Hello and welcome to the game ! •#•#•#•#•#•#•\n";
	cout << "---------------\nGAME STARTING\n---------------\n";
	

	// ask user how many set of cards
	cout <<  "How many sets of cards ? (min: 1, max:" << MAX_NUMBER_SETS << ").\n";
	cin >> numberSets;
		
	do {

		if(numberSets<0 || numberSets>10){
		cout << "Number of Sets is outside allowed range, please renter" << endl;
		cin >> numberSets;
		}

		// checks the input if it is an integer
		// 'cin>>numberSets' and 'cin.good()' are the same expressions
		// if there is an invalid input, flag is setted to false in good() function
		if(!cin.good())

        {
		//ask user to enter a valid input in this case an integer
		cout<<"Invalid input, Please enter a number specified for sets of cards : "<<endl;
		// cin.clear function clears the false flag and with this cin can exit the loop 
        cin.clear();
		// cin.ignore: ignores the amount of streamsize input characters entered by user until it sees a newline (/n)
		// 'numeric_limits<streamsize>::max()' is the maximum value of the number of characters transferred in the I/O operation
		cin.ignore(numeric_limits<streamsize>::max(), '\n' );
		//prompts user to get another input
		cin >> numberSets;

        }

	}

	// While the user doesn't give a valid input
	while(numberSets<0 || numberSets>10 || !cin.good()); 

	if(numberSets==1){
		cout <<  "How many players in the game ? (min: 2, max:" << 7 << ").\n";
		cin >> numberPlayers;
	}
	else{
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
	

	// Create an instance of the CardGame class
	CardGame game = CardGame(numberPlayers, numberSets);

	// Play the game
	game.playGame();

}