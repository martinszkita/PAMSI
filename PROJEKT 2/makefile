#mergesort
merge: merge.o film.o
	g++ merge.o film.o -o merge

merge.o:merge.cpp
	g++ -c merge.cpp

#quicksort
quick: quicksort.o film.o
	g++ quicksort.o film.o -o quick

quicksort.o: quicksort.cpp
	g++ -c quicksort.cpp

#common
film.o:film.cpp
	g++ -c film.cpp

clean:
	rm *.o merge
	rm *.o quick
