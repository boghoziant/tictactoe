CC=g++
CFLAGS=-g

tictactoe: main.cpp tictactoe.cpp tictactoe.h game.h
	$(CC) -o out main.cpp tictactoe.cpp tictactoe.h game.h $(CFLAGS)
