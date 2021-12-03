#include "tictactoe.h"
#include "game.h"

#include <iostream>

using namespace std;

int main() {
    bool ai;
    std::cout << "play with ai?" << std::endl;
    // x or o?
    std::cin >> ai;
    Game g(ai);

    int slot = 0;
    // move code to game.h
    // give game an ai?

    std::cout << "first turn \n";
    std::cin >> slot;
    while (g.play_game(slot)) {
        if (g.turn_count % 2 == 0) {
            cin >> slot;
        }
        else if (ai) {
            slot = 9;
        }
        else {
            cin >> slot;
        }
    }

}

