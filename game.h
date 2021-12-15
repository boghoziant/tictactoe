#ifndef GAME_H
#define GAME_H

#include "tictactoe.h"
#include "ai.h"
#include "util.h"

#include <iostream>
#include <vector>
#include <array>

class Game {
    public:
        Game(bool p2) {
            if (p2)
                ai = true;
            else
                ai = false;

            turn_count = 0;
            turn = 0;
            victor = 0;
            for(int i = 0; i < 9; i++) {
                set[i] = 0;
            }
            possible_moves = {0,1,2,3,4,5,6,7,8};

            // display welcome message
            std::cout << "Welcome, press 0-8 to place your xo on the board," << std::endl;
        }


        bool play_game(int slot) {
            std::cout << "pick a slot 0-8" << std::endl;
            std::cout << "turn " << turn_count << std::endl;

            if (ai && turn_count % 2 != 0) {
                slot = player2.makeAMove(possible_moves, 9 - turn, set);
            }

            // check for repeat moves 
            flag = true;
            for (unsigned int i = 0; i < possible_moves.size(); i++) {
                if (possible_moves[i] == slot) {
                    flag = false;
                }
            }
            if (flag) {
                std::cout << "slot : " << slot << " full, pick another" << std::endl;
                return true;
            }

            // write to buffer and remove move from possibilities
            g.write_xo(turn, slot);
            possible_moves.erase(std::remove(possible_moves.begin(), possible_moves.end(), slot), possible_moves.end());

            // remember who put what where
            if (turn)
                set[slot] = 1;
            else
                set[slot] = 2;

            // display board
            g.display_board();

            // next players turn
            turn = !turn;
            turn_count++;

            // did someone win?
            victor = checkWin(set);
            if (victor == -1) {
                std::cout << "x's win \n";
                return false;
            } else if (victor == 1) {
                std::cout << "o's win \n";
                return false;
            } else if (victor == 500) {
                std::cout << "tie \n";
                return false;
            }

            // next turn
            return true;
        }

        tictactoe g;
        Ai player2;
        bool ai;
        std::array<int, 9> set;
        std::vector<int> possible_moves;
        int turn_count;
        int turn;
        int slot;
        int victor;
        bool flag;
};

#endif
