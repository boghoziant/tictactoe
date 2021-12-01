CC=g++
CFLAGS=

tictactoe: main.cpp tictactoe.cpp tictactoe.h
	$(CC) -o out main.cpp tictactoe.cpp tictactoe.h
