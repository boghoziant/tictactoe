CC=g++
CFLAGS=-g

tictactoe: main.cpp tictactoe.cpp ai.cpp tictactoe.h game.h ai.h
	$(CC) -o out main.cpp tictactoe.cpp ai.cpp tictactoe.h game.h ai.h $(CFLAGS)
