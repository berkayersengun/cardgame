////////////////////////////////////////////////
//
// Authors: Johnson Olayiwola - 17134609, Vasanth Solomon Suresh - 17102332, Berkay Ersengun - 17121264, Luis Willnat - 17105536
// Group 4 project for ED5021/EE6411 
// Date: 26 November,2017.
// Deck.cpp - class modelling a a deck of 52 excluding joker card
/////////////////////////////////////////////////

#include <iostream>
#include <cstdlib>
#include <vector>
#include <string>
#include "Deck.h"
#include <random>
#include <algorithm>
#include <ctime>
#include "Card.h"
#include <typeinfo>

using namespace std;


// int randomFunc()
// returns a andom number for the method shuffleDeck().
// param: int i - seed for random function
// return: int - Random number
int randomFunc(int i) {
	srand(unsigned(std::time(0)));
	return rand() % i;
}

// Constructors of Deck
Deck::Deck() = default;

Deck::Deck(int setNumber) : 
setNumber(setNumber) {}

// Destructor of Deck
Deck::~Deck() {}

// copy constructor of Deck
Deck::Deck( const Deck& otherDeck ) : deck(otherDeck.deck), setNumber(otherDeck.setNumber) {}


// void createEmptyCardDeck()
// Creates an empty CardDeck
// param: none
// return: void
void Deck::createEmptyCardDeck()
{
    vector<Card> deck; 
}

// createInitialisedCardDeck(int setNumber)
// Lead initilised deck set up to create a single 52 card deck for now
// param: int setNumber - Number of sets of cards for the game
// return: void
void Deck::createInitialisedCardDeck(int setNumber)
{
    //check if setNumber is correct.
    if(setNumber >= MIN_SET_CARDS && setNumber <= MAX_SET_CARDS){
        // add standard 52 cards to deck PP
        for (int i = 0; i < setNumber; i++) {
            for (int suit = Suit::SPA; suit <= Suit::DIA; ++suit) {
                for (int rank = Rank::Ace; rank >= Rank::Two; rank--) {
                    
                    deck.push_back(Card(static_cast<Rank>(rank), static_cast<Suit>(suit)));
                    //Card(static_cast<Rank>(rank), static_cast<Suit>(suit))
                }
            }
        }

    }else{
        cout << "Please use between " << MIN_SET_CARDS << " and " << MAX_SET_CARDS << " set of cards. \n";
    }
	
}

// initialiseCardDeck(int setNumber, Deck deckToInitialise)
//initialises the deck created in the Deck::createInitialisedCardDeck(int setNumber)
// param: int setNumber - Number of set of cards for the game
// param: Deck deckToInitialise - Takes a  deck already created
// return: void
void Deck::initialiseCardDeck(int setNumber, Deck deckToInitialise)
{   
    if((setNumber * deckSize) == static_cast<int>(deckToInitialise.deck.size()))
    {   
        deckToInitialise.displayDeck();
        //this might be for only checking purposes cause we have the same shit above
        //Post: deck contains setNum ordered sets of cards or an error is indicated if sufficient resources not available.
    }
    else 
    cout<<"not enough cards ?";
    
}
// getNumberOfCards()
// returns the number of cards in the deck
// param: none
// return: int - number of cards in the deck
int const Deck::getNumberOfCards()
{
	return deck.size();
};

// displayDeck()
// Prints out the current deck of cards
// param: none
// return: void
void Deck::displayDeck()
{
    if (deck.size() != 0){
        auto iter=deck.begin();
        for ( iter = deck.begin(); iter != deck.cend()-1; ++iter) {
            cout << *iter ;
            cout<<",";
        }
        cout<<*iter<<endl;
    } else cout << "Card Deck is empty\n";
}

// getTopCard()
// Return and remove the top card of the deck
// param: none
// return: Card - instance (top card of the deck) 
Card Deck::getTopCard() 
{
    Card topCard;
    if(!deck.empty()) {
        topCard = deck.front();
        deck.erase(deck.begin());
    }
    return topCard;
}

// getACard(int number)
// Return and remove the number n-th card of the deck
// param: int number - position of the card in the deck
// return: Card - instance of the position indicated
Card Deck::getACard(int number) {
    Card nthCard;
    if(!deck.empty()) {
        nthCard = deck[number];
        deck.erase((deck.begin() + number));
    }
    return nthCard;
}

// lookAtCard(int number)
// Return a card at position number without removing it from the deck
// param: int number - position of the card in the deck
// return: Card - instance of the position indicated
Card Deck::lookAtCard(int number) {
    Card nthCard;
    if(!deck.empty()) {
        nthCard = deck[number];
    }
    return nthCard;
}

// addCard(Card card)
// Add Card to the deck
// param: Card card - add an instance of Card to the deck
// return: void
void Deck::addCard(Card card) {
    if (typeid(card).name() == typeid(Card).name()) 
    deck.insert(deck.begin(),card);
}

// shuffleDeck()
// Method to shuffle the deck
// param: none
// return: void
void Deck::shuffleDeck(){ 
    random_shuffle(deck.begin(), deck.end(), randomFunc); 
}

// moveAllCards(Deck copyDeck)
// Method to move all cards from one deck to another
// param: Deck copyDeck - Deck to copy from
// return: none
void Deck::moveAllCards(Deck copyDeck){
    deck.swap(copyDeck.deck);
    copyDeck.setNumber = setNumber;
 }
// deleteCardDeck()
// Method to delete the deck from the memory.
// param: none
// return: none
void Deck:: deleteCardDeck() {
    deck.clear();
    deck.shrink_to_fit();
}

// Accessors
// Accessor for deck
// param: none
// return: vector<Card> of the deck
vector<Card> Deck::getDeck(){
    return deck;
}

// Mutators
// Mutator for deck
// param: vector<Card> deck - new deck of cards for the instance
void Deck::setDeck(vector<Card> deck){
    deck = deck;
}





