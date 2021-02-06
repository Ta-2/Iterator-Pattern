main: main.o
	g++ -Wall -o main main.o

main.o: main.cpp
	g++ -Wall -c main.cpp

all:
	main
clean:
	rm *.o *.exe *.gch
