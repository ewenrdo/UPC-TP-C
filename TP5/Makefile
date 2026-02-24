program: notes.o exo2.o
	gcc -Wall -o program notes.o exo2.o -lm

exo2.o: exo2.c notes.h
	gcc -Wall -c exo2.c

notes.o: notes.c notes.h
	gcc -Wall -c notes.c