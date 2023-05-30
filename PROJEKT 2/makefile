#mergesort
merge: mergesort.o film.o
	g++ mergesort.o film.o -o merge

mergesort.o:mergesort.cpp
	g++ -c mergesort.cpp

#quicksort
quick: quicksort.o film.o
	g++ quicksort.o film.o -o quick

quicksort.o: quicksort.cpp
	g++ -c quicksort.cpp

#heapsort
heap: heapsort.o film.o
	g++ heapsort.o film.o -o heap

heapsort.o: heapsort.cpp
	g++ -c heapsort.cpp

#common
film.o:film.cpp
	g++ -c film.cpp

clean:
	rm *.o merge
	rm *.o quick
	rm *.o heap
