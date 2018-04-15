Binarytree:	main.o	bt.o node.o
						g++	-g	-std=c++11	main.o	bt.o node.o

main.o:	main.cpp bt.h
				g++	-g -std=c++11	-c	main.cpp

bt.o:	bt.cpp bt.h node.h
				g++ -g -std=c++11 -c bt.cpp

node.o:	node.cpp node.h
				g++ -g	-std=c++11 -c node.cpp
