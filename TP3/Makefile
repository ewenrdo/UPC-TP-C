CFLAGS=-O -Wall -ffast-math `pkg-config --cflags gtk+-3.0`
LDFLAGS=`pkg-config --libs gtk+-3.0`

.PHONY: all
all: exemple

exemple: exemple.o graphiques.o
		gcc $(CFLAGS) -o exemple exemple.o graphiques.o $(LDFLAGS)

exemple.o: exemple.c
		gcc $(CFLAGS) -c exemple.c

graphiques.o: graphiques.c
		gcc $(CFLAGS) -c graphiques.c

.PHONY: clean
clean:
		rm -f *~ *.o exemple
