#include <iostream>
#include <cstdlib>
#include <vector>
#include <string>

using namespace std;

void createInitialisedCardDeck(int set);

int main()
{
    int set;
    cout<<"enter the number of the sets of cards: "<<endl;
    //createEmptyCardDeck();
    cin>>set;

    createInitialisedCardDeck(set);

}


/*
void createEmptyCardDeck (void)
{
    vector<string> duck;
}
*/
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



/*
    vector<int> duck;
    for (int i=0; i<set; i++)
    {
        for(int j=0; j<13; j++)
        cout<<arrRank[j]<<endl;
       

        //for(int j=0; j<13; j++)
        // cout<<Suit[i]()<<endl;
    }
}   

*/