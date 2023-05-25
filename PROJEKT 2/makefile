output: merge.o film.o
	clear
	g++ merge.o film.o -o output

merge.o:merge.cpp
	g++ -c merge.cpp

film.o:film.cpp
	g++ -c film.cpp

clear:
	rm *.o output
