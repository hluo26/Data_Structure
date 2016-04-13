all: Lab1

Lab1: main.o Pokemon.o  Colosseum.o Dice.o
	g++ -g -std=c++11 main.o  Pokemon.o Colosseum.o Dice.o -o Lab10

main.o: main.cpp  Pokemon.h Dice.h Colosseum.h
	g++ -g -std=c++11 -c main.cpp
Colosseum.o:Colosseum.cpp Colosseum.h Pokemon.h Dice.h
	g++ -g -std=c++11 -c Colosseum.cpp
Pokemon.o: Pokemon.cpp Pokemon.h
	g++ -g -std=c++11 -c Pokemon.cpp
clean:
	rm *.o main
	clean done
