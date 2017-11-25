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

int randomFunc(int i) {
	srand(unsigned(std::time(0)));
	return rand() % i;
}

// Constructors
Deck::Deck() = default;

Deck::Deck(int setNumber) : 
setNumber(setNumber) {}

// Destructor
Deck::~Deck() {}

// copy constructor
Deck::Deck( const Deck& otherDeck ) : deck(otherDeck.deck), setNumber(otherDeck.setNumber) {}

void Deck::createEmptyCardDeck()
{
    vector<Card> deck; 
}

// Lead initilised deck set up to create a single 52 card deck for now
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

//initialises the deck created in the Deck::createInitialisedCardDeck(int setNumber)
void Deck::initialiseCardDeck(int setNumber, Deck deckToInitialise)
{   
    if((setNumber * deckSize) == static_cast<int>(deckToInitialise.deck.size()))
    {   
        deckToInitialise.displayDeck();
        cout<<"This is a bullshit method." << endl;
        //this might be for only checking purposes cause we have the same shit above
        //Post: deck contains setNum ordered sets of cards or an error is indicated if sufficient resources not available.
    }
    else 
    cout<<"not enough cards ?";
    
}

int const Deck::getNumberOfCards()
{
	return deck.size();
};

// Prints of the current deck of cards
void Deck::displayDeck()
{
        //auto=vector<Card>::iterator
	for (auto iter = deck.begin(); iter != deck.cend(); ++iter) {
		cout << *iter << "\n";
	}
}

// Return and remove the top card of the deck
Card Deck::getTopCard() 
{
    Card topCard;
    if(!deck.empty()) {
        topCard = deck.front();
        deck.erase(deck.begin());
    }
    return topCard;
}
// Return and remove the number n-th card of the deck
Card Deck::getACard(int number) 
{
    Card nthCard;
    if(!deck.empty()) {
        nthCard = deck[number];
        deck.erase((deck.begin() + number));
    }
    return nthCard;
}

Card Deck::lookAtCard(int number) 
{
    
    Card nthCard;
    if(!deck.empty()) {
        
        nthCard = deck[number];
    }
    return nthCard;
}

// Add Card method
void Deck::addCard(Card card) 
{
    if (typeid(card).name() == typeid(Card).name()) 
    deck.insert(deck.begin(),card);
}


vector<Card> Deck::getDeck(){
    return deck;
}

void Deck::setDeck(vector<Card> deck){
    deck = deck;
}

// Method to shuffle the deck - now working
void Deck::shuffleDeck() 
{ 
    random_shuffle(deck.begin(), deck.end(), randomFunc); 
}

void Deck::moveAllCards(Deck copyDeck)
{
    deck.swap(copyDeck.deck);
    copyDeck.setNumber = setNumber;
}







