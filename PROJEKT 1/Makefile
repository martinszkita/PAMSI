#target: dependencies
#	action

#output to nazwa zmiennej

#kiedy projekt1.o lub lista.o sie zmienia
output:projekt1.o lista.o klient.o test.o
#rekompiluj wtedy i zapisz wynik pod nazwa output
	clear
	g++ projekt1.o lista.o klient.o test.o -o output
#robi plik projekt1.o
projekt1.o:projekt1.cpp
	g++ -c projekt1.cpp

#robi plik lista.o
lista.o: lista.cpp lista.h
	g++ -c lista.cpp

#robi plik klient.o
klient.o: klient.cpp klient.h
	g++ -c klient.cpp

#robi plik test.o
test.o: test.cpp test.h
	g++ -c test.cpp

#usuwa
clean:
	rm *.o output