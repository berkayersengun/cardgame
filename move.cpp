

#include <iostream>
#include <string>
#include <iterator>
#include <vector>
using namespace std;
void deck(vector<int> *deck, vector<int> *deckDest);


int main    ()
{
    vector<int> deck1;
     vector<int> deckDest1;
   
 deck(&deck1, &deckDest1);
    
    

cout<<deck1.size()<<endl;
cout<<deckDest1.size()<<endl;
cout<<deckDest1[0]<<endl;
cout<<deckDest1[1]<<endl;
cout<<deckDest1[2]<<endl;
}


void deck(vector<int> *deck, vector<int> *deckDest)
{
    
    // A loop to copy elements of
	// old vector into new vector
	// by Iterative method
    deck->push_back(1);
    deck->push_back(2);
    deck->push_back(3);
    auto iter = deck->begin();
    while(iter!=deck->end())
    {
        deckDest->push_back(*iter);
       
        iter=deck->erase(iter);
         //iter++;
    }

}
