Lab01: main.o list.o node.o
	g++ -g -std=c++11 main.o list.o node.o -o Lab01

main.o: main.cpp list.h
	g++ -g -std=c++11 -c main.cpp

list.o: list.cpp list.h node.h
	g++ -g -std=c++11 -c list.cpp

node.o:	node.cpp node.h
	g++ -g -std=c++11 -c node.cpp

clean:
	rm *.o main
	clean done
