maze: main.o mazebuilder.o mazewalker.o
				g++ -g -std=c++11 main.o mazebuilder.o mazewalker.o

main.o: main.cpp mazebuilder.h
				g++ -g -std=c++11 -c main.cpp

mazebuilder.o: mazebuilder.cpp mazebuilder.h
				g++ -g -std=c++11 -c mazebuilder.cpp

mazewalker.o: mazewalker.cpp mazewalker.h mazebuilder.h
				g++ -g -std=c++11 -c mazewalker.cpp
