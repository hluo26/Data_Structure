leftisttree:	main.o	leftist.o node.o
						g++	-g	-std=c++11	main.o	leftist.o node.o

main.o:	main.cpp leftist.h
				g++	-g -std=c++11	-c	main.cpp

leftist.o:	leftist.cpp leftist.h node.h
				g++ -g -std=c++11 -c leftist.cpp

node.o:	node.cpp node.h
				g++ -g	-std=c++11 -c node.cpp
