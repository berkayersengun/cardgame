
game: Card.o Deck.o CardGame.o
	g++ -o game Card.o Deck.o CardGame.o -g

Card.o: Card.h Card.cpp
	g++ -Wall -std=c++11 -ggdb -c Card.cpp

Deck.o: Deck.h Deck.cpp
	g++ -Wall -std=c++11 -ggdb -c Deck.cpp

CardGame.o: CardGame.h CardGame.cpp
	g++ -Wall -std=c++11 -ggdb -c CardGame.cpp

# clean up target - no dependencies
clean:
	rm firstClass *.o *~