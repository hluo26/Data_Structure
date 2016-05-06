Lab01: main.o BST.o node.o queue.o
				g++ -g -std=c++11 main.o BST.o node.o queue.o -o Lab01

main.o: main.cpp BST.h
				g++ -g -std=c++11 -c main.cpp

BST.o: BST.cpp BST.h node.h queue.h
				g++ -g -std=c++11 -c BST.cpp

node.o: node.cpp node.h
				g++ -g -std=c++11 -c node.cpp

queue.o: queue.cpp queue.h node.h
				g++ -g -std=c++11 -c queue.cpp

clean:
				rm * .o main
				clean done
