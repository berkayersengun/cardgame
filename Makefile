
#make the game
game: cardGame
	./cardGame

#linking object files to executable
cardGame: Card.o Deck.o CardGame.o
	g++ -o cardGame Card.o Deck.o CardGame.o -g
	
#compiling card.cpp
Card.o: Card.h Card.cpp
	g++ -Wall -std=c++11 -ggdb -c Card.cpp

#compiling deck.cpp
Deck.o: Deck.h Deck.cpp
	g++ -Wall -std=c++11 -ggdb -c Deck.cpp

#compiling cardgame.cpp
CardGame.o: CardGame.h CardGame.cpp
	g++ -Wall -std=c++11 -ggdb -c CardGame.cpp

# clean up target - no dependencies
clean:
	rm  firstClass *.o *~