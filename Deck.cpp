#include <iostream>
#include <cstdlib>
#include <vector>
#include <string>

using namespace std;

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
