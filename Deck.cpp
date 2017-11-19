#include <iostream>
#include <cstdlib>
#include <vector>
#include <string>
#include "Deck.h"
#include <random>
#include <algorithm>
#include <ctime>
#include "Card.h"

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

// Lead initilised deck set up to create a single 52 card deck for now
void Deck::initialiseCardDeck()
{
	// add standard 52 cards to deck PP
	for (int i = 0; i < this->setNumber; i++) {
		for (int suit = Suit::SPA; suit <= Suit::DIA; ++suit) {
			for (int rank = Rank::Ace; rank >= Rank::Two; rank--) {
				deck.push_back(Card(static_cast<Rank>(rank), static_cast<Suit>(suit)));
                //Card(static_cast<Rank>(rank), static_cast<Suit>(suit))
			}
		}
	}
}
int const Deck::getNumberOfCards()
{
	return deck.size(); ;
}
;

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


// Method to shuffle the deck - now working
void Deck::shuffleDeck() { random_shuffle(deck.begin(), deck.end(), randomFunc); }

int main() {
	Deck newDeck(1);
	newDeck.initialiseCardDeck();
    newDeck.shuffleDeck();
	// newDeck.displayDeck();
	int deckSize = newDeck.getNumberOfCards();
	
    cout << "The number of cards in the deck is " << deckSize << endl;
    int number = 5;
    Card nthCard = newDeck.lookAtCard(number);
    cout << nthCard << endl;
  
}










/*
//void createInitialisedCardDeck(int set);

int main()
{
    int set;
    cout<<"enter the number of the sets of cards: "<<endl;
    //createEmptyCardDeck();
    cin>>set;
    DeckOfCards obj;
    obj.createInitialisedCardDeck();
    obj.initialiseCardDeck();
    //createInitialisedCardDeck(set);

}



class Card{

public:
    Card();
    Card(int cardSuit=1, int cardRank=1);
     ~Card();


private:
    int Rank;
    int Suit;
    int RankNumber;
    int SuitNumber;
    int rs;
};

class DeckOfCards
{
	public:
		DeckOfCards(); // constructor initializes deck
		void createInitialisedCardDeck(int setNum);
        void initialiseCardDeck (int setNum, int deck);
	
	private:
		vector< int > deck(52,0); // represents deck of cards and values initialised 0
	
}; 

Card::Card (int cardSuit, int cardRank)
{
    Rank=cardSuit;
    Suit=cardRank; 
    rs=Rank*Suit;

}

DeckOfCards::DeckOfCards()
{
    vector<int> newDeck; // create new deck vector

   // populate the deck
    for (int i = 0; i < Card::SuitNumber; i++)
    {
        for (int j = 0; j < Card::RankNumber; j++)
        {
            newDeck.push_back(Card(i,j));
            
        }
    } 

	// assign the new deck to the deck vector
	deck() = newDeck;


}

void DeckOfCards::initialiseCardDeck ()
{
    for (int i = 0; i < 52; i++)
	{
		cout<<deck(i∏);

	
		
	}



}
*/



/*
void createEmptyCardDeck (void)
{
    vector<string> duck;
}

void createInitialisedCardDeck(int set)
{
    enum Rank {Ace=1, Two, Three, Four, Five, Six, Seven, Eight, Nine, Ten, Jack, Queen, King};
    enum Suit { Spades, Hearts, Clubs, Diamonds};
    
    vector<string> arrRank(13, "Ace","Two","Three","Four","Five","Six","Seven","Eight","Nine","Ten","Jack","Queen","King");
    vector<string> arrSuit(4, "Spades", "Hearts", "Clubs", "Diamonds");

    
    //vector<int> ;
    for (int k=0; k<set; k++)
    {
        for (int i=0; i<4; i++){
            for(int j=0; j<13; j++){
             

            cout<<arrRank;
            }
            cout<<endl;
        }
    }

}




    vector<int> duck;
    for (int i=0; i<set; i++)
    {
        for(int j=0; j<13; j++)
        cout<<arrRank[j]<<endl;
       

        //for(int j=0; j<13; j++)
        // cout<<Suit[i]()<<endl;
    }
}   


const string Card::faceNames[ RankNumber ] = {"Ace", "Two", "Three", "Four", "Five", "Six", "Seven", "Eight", "Nine", "Ten", "Jack", "Queen", "King"};
const string Card::suitNames[ SuitNumber ] = {"Hearts", "Clubs", "Diamonds", "Spades"};
*/
