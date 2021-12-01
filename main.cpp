#include "tictactoe.h"

#include <iostream>


using namespace std;

int main() {
    tictactoe game;
    for (int i = 0; i < 9; i++) {
        if (i % 2 == 0) {
            game.write_xo(1, i);
        } else
            game.write_xo(0, i);
    }
    game.display_board();
}
