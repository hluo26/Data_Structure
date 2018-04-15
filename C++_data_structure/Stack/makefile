Lab01: main.o stack.o box.o
	g++ -g -std=c++11 main.o stack.o box.o -o Lab01

main.o: main.cpp stack.h
	g++ -g -std=c++11 -c main.cpp

stack.o: stack.cpp stack.h box.h
	g++ -g -std=c++11 -c stack.cpp

box.o:	box.cpp box.h
	g++ -g -std=c++11 -c box.cpp

clean:
	rm *.o main
	clean done
