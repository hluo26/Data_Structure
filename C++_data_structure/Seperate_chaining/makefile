hashtable:	main.o	hash.o	hashnode.o
						g++	-g	-std=c++11	main.o	hash.o	hashnode.o

main.o:	main.cpp	Hash.h
				g++	-g	-std=c++11	-c	main.cpp

hash.o:	Hash.cpp	Hash.h	hashnode.h
				g++	-g	-std=c++11	-c	Hash.cpp

hashnode.o:	hashnode.cpp	hashnode.h
						g++	-g	-std=c++11	-c	hashnode.cpp

clean:
			rm *.o hashtable
			clean done
