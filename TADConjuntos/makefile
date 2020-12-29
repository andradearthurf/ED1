ALl: TADConjunto

TADConjunto: main.o TAD.o
	gcc -o TADConjunto main.o TAD.o

main.o: main.c TAD.h
	gcc -c main.c -Wall

TAD.o: TAD.c TAD.h
	gcc -c TAD.c -Wall

clean: 
	rm TADConjunto main.o TAD.o