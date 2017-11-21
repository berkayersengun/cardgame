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
	// add standard 52 cards to deck PP
	for (int i = 0; i < setNumber; i++) {
		for (int suit = Suit::SPA; suit <= Suit::DIA; ++suit) {
			for (int rank = Rank::Ace; rank >= Rank::Two; rank--) {
				deck.push_back(Card(static_cast<Rank>(rank), static_cast<Suit>(suit)));
                //Card(static_cast<Rank>(rank), static_cast<Suit>(suit))
			}
		}
	}
}


//initialises the deck created in the Deck::createInitialisedCardDeck(int setNumber)
void Deck::initialiseCardDeck(int setNumber,Deck duck)
{   
    
    if(setNumber*52==deck.size())
    {   duck.displayDeck();
        cout<<"This is a bullshit method."<<endl;
        //this might be for only checking purposes cause we have the same shit above
        //Post: deck contains setNum ordered sets of cards or an error is indicated if sufficient resources not available.
    }
    else 
    cout<<"not enough data ?";
    
}

void Deck::deleteCardDeck(Deck duck){
	 
      duck.~Deck();


}

int const Deck::getNumberOfCards()
{
	//return deckTemp.size(); ;
	return deck.size(); ;
};

void Deck::moveAllCards()
{
    // A loop to copy elements of
	// old vector into new vector
	// by Iterative method
	 cout << deck.size()<<endl;
    
    auto iter = deck.begin();
    auto enditer = deck.back(); // !!defining the iterator for last element
    
    while(iter!=deck.end())
    {
        deckTemp.push_back(*iter);
        iter++;
        //iter=deck.erase(iter);

    }
    auto it= deck.begin();
    while(it!=deck.end())
    it = deck.erase(it);
    
   
/*
	cout << "Old vector elements are : "<<endl;
	for (int i=0; i<deck.size(); i++){
		cout << deck[i] << " ";
	cout << endl;
    }
	cout << "New vector elements are : "<<endl;
	for (int i=0; i<deckTemp.size(); i++){
		cout << deckTemp[i] << " ";
    cout<< endl;
    }
    */
}


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
        
        nthCard = deck[number-1];
        deck.erase((deck.begin() + number-1));
    }
    return nthCard;
}

Card Deck::lookAtCard(int number) 
{
    
    Card nthCard;
    if(!deck.empty()) {
        
        nthCard = deck[number-1];
    }
    return nthCard;
}

// Add Card method
void Deck::addCard(Card card) 
{
    if (typeid(card).name() == typeid(Card).name()) deck.insert(deck.begin(),card);
}

// Method to shuffle the deck - now working
void Deck::shuffleDeck() { random_shuffle(deck.begin(), deck.end(), randomFunc); }

int main() {
	Deck newDeck(1);
    newDeck.createEmptyCardDeck();
    int setno=1; //how many sets
	newDeck.createInitialisedCardDeck(setno);
    newDeck.initialiseCardDeck(setno,newDeck);
    newDeck.deleteCardDeck(newDeck);
    //newDeck.shuffleDeck();
    newDeck.moveAllCards();
	// newDeck.displayDeck();
	
	Deck copyDeck = newDeck;
    int deckSize = copyDeck.getNumberOfCards();
    cout << "The number of cards in the deck is " << deckSize << endl;
    int number = 5;
    Card nthCard ;
    nthCard =  copyDeck.lookAtCard(number);
    cout << nthCard << endl;
    Card anewCard (Two, SPA);
    copyDeck.addCard(anewCard);
    cout << copyDeck.getTopCard() << endl;
}










