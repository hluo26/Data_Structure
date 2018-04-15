Lab01:	main.o PreconditionViolationException.o
		g++ -g	-std=c++11 main.o PreconditionViolationException.o -o Lab01

main.o:	main.cpp queue.hpp queue.h node.hpp node.h PreconditionViolationException.cpp PreconditionViolationException.h
		g++ -g	-std=c++11	-c	main.cpp

PreconditionViolationException.o: PreconditionViolationException.cpp PreconditionViolationException.h
		g++ -g	-std=c++11	-c	PreconditionViolationException.cpp
