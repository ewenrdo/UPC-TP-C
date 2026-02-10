CFLAGS=-O -Wall -ffast-math `pkg-config --cflags gtk+-3.0`
LDFLAGS=`pkg-config --libs gtk+-3.0`

.PHONY: all
all: exemple

exemple: exemple.o graphiques.o
		gcc $(CFLAGS) -o exemple exemple.o graphiques.o $(LDFLAGS)

exemple.o: exemple.c
		gcc $(CFLAGS) -c exemple.c

exo2: exo2.o graphiques.o
	gcc $(CFLAGS) -o exo2 exo2.o graphiques.o $(LDFLAGS)

exo2.o: exo2.c
	gcc $(CFLAGS) -c exo2.c

exo3: exo3.o graphiques.o
	gcc $(CFLAGS) -o exo3 exo3.o graphiques.o $(LDFLAGS)

exo3.o: exo3.c
	gcc $(CFLAGS) -c exo3.c

exo4: exo4.o graphiques.o
	gcc $(CFLAGS) -o exo4 exo4.o graphiques.o $(LDFLAGS)

exo4.o: exo4.c
	gcc $(CFLAGS) -c exo4.c

exo5: exo5.o graphiques.o
	gcc $(CFLAGS) -o exo5 exo5.o graphiques.o $(LDFLAGS)

exo5.o: exo5.c
	gcc $(CFLAGS) -c exo5.c

exo6: exo6.o graphiques.o
	gcc $(CFLAGS) -o exo6 exo6.o graphiques.o $(LDFLAGS)

exo6.o: exo6.c
	gcc $(CFLAGS) -c exo6.c
exo7: exo7.o graphiques.o
	gcc $(CFLAGS) -o exo7 exo7.o graphiques.o $(LDFLAGS)

exo7.o: exo7.c
	gcc $(CFLAGS) -c exo7.c
exo7_bis: exo7_bis.o graphiques.o
	gcc $(CFLAGS) -o exo7_bis exo7_bis.o graphiques.o $(LDFLAGS)

exo7_bis.o: exo7_bis.c
	gcc $(CFLAGS) -c exo7_bis.c

graphiques.o: graphiques.c
		gcc $(CFLAGS) -c graphiques.c

.PHONY: clean
clean:
		rm -f *~ *.o exemple
