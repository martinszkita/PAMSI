kik.o: kik.cpp
	g++ -c kik.cpp

board.o: board.cpp	
	g++ -c board.cpp

main.o: main.cpp
	g++ -c main.cpp

clean:
	rm *.o

output: main.o board.o kik.o
	g++ -o output main.o board.o kik.o -g