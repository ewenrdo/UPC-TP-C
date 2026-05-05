CC = gcc
CFLAGS = -Wall

main: main.o parser.o lexer.o
	$(CC) $(CFLAGS) -o main main.o parser.o lexer.o

parser.o: parser.c parser.h lexer.h
	$(CC) $(CFLAGS) -c parser.c

lexer.o: lexer.c lexer.h
	$(CC) $(CFLAGS) -c lexer.c

# Sous windows, faire : gcc -Wall -o main.exe main.c parser.c lexer.c