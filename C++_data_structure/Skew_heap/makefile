skewtree:	main.o	skew.o node.o
						g++	-g	-std=c++11	main.o	skew.o node.o

main.o:	main.cpp skew.h
				g++	-g -std=c++11	-c	main.cpp

skew.o:	skew.cpp skew.h node.h
				g++ -g -std=c++11 -c skew.cpp

node.o:	node.cpp node.h
				g++ -g	-std=c++11 -c node.cpp
