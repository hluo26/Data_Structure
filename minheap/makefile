Lab01: main.o heap.o 
	g++ -g -std=c++11 main.o heap.o -o Lab01

main.o: main.cpp heap.h
	g++ -g -std=c++11 -c main.cpp

heap.o: heap.cpp heap.h
	g++ -g -std=c++11 -c heap.cpp

clean:
	rm *.o main
	clean done
