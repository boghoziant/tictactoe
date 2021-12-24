#include "tictactoe.h"
#include "game.h"

#include <iostream>

using std::cout;
using std::endl;
using std::cin;

int main() {
    bool ai;

    std::cout << "play with ai?" << std::endl;
    std::cin >> ai;

    Game g(ai);

    int slot = 0;

    std::cout << "first turn \n";
    std::cin >> slot;

    while (g.play_game(slot)) {
        if (g.turn_count % 2 == 0) {
            cin >> slot;
        } else if (ai) {
            slot = 9;
        } else {
            cin >> slot;
        }
    }
}
