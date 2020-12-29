ALl: ABBGenerica

ABBGenerica: main.o ABB.o
	gcc -o ABBGenerica main.o ABB.o

main.o: main.c ABB.h
	gcc -c main.c -Wall

ABB.o: ABB.c ABB.h
	gcc -c ABB.c -Wall

clean: 
	rm ABBGenerica main.o ABB.o