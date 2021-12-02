#include "tictactoe.h"
#include "game.h"

#include <iostream>
#include <algorithm>
#include <random>
#include <vector>


using namespace std;

int main() {
    Game g;

    int slot = 0;
    // move code to game.h
    // give game an ai?
    std::vector<int> possible_moves = {0,1,2,3,4,5,6,7,8};

    std::cout << "first turn \n";
    std::cin >> slot;
    possible_moves.erase(std::remove(possible_moves.begin(), possible_moves.end(), slot), possible_moves.end());
    while (g.play_game(slot)) {
        if (g.turn_count % 2 == 0) {
            cin >> slot;
            possible_moves.erase(std::remove(possible_moves.begin(), possible_moves.end(), slot), possible_moves.end());
        }
        else {
            auto rng = std::default_random_engine {};
            std::shuffle(std::begin(possible_moves), std::end(possible_moves), rng);
            slot = possible_moves.back();
            possible_moves.pop_back();
            for (int i = 0; i < possible_moves.size(); i++) {
                std::cout << possible_moves[i];
            }
            std::cout << '\n';
        }
    }

}

