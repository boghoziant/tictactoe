CC=g++
CFLAGS=-g -Wall -O0

tictactoe: main.cpp tictactoe.cpp ai.cpp util.cpp tictactoe.h game.h ai.h util.h
	$(CC) -o out main.cpp tictactoe.cpp ai.cpp util.cpp tictactoe.h game.h ai.h util.h $(CFLAGS)
