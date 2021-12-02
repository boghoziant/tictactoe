#ifndef GAME_H
#define GAME_H

#include "tictactoe.h"

#include <iostream>

class Game {
    public:
        Game() {
            turn_count = 0;
            turn = 0;
            victor = 0;
            for(int i = 0; i < 9; i++) {
                set[i] = 0;
            }

            // display welcome message
            std::cout << "Welcome, press 0-8 to place your xo on the board," << std::endl;
        }


        bool play_game(int slot) {
            // make it impossible to make a move in a spot where there's a x or o
            std::cout << "pick a slot 0-8" << std::endl;
            std::cout << "turn " << turn_count << std::endl;
            bool flag = false;
            for (int i = 0; i < set.size(); i++) {
                if (set[i] == slot) {
                    flag = true;
                }
            }
            if (flag) {
                std::cout << "slot full, pick another" << std::endl;
                return true;
            }
            g.write_xo(turn, slot);


            if (turn)
                set[slot] = 1;
            else
                set[slot] = 2;

            g.display_board();
            turn = !turn;
            turn_count++;
            victor = end();
            if (victor == 1) {
                std::cout << "x's win \n";
                return false;
            } else if (victor == 2) {
                std::cout << "o's win \n";
                return false;
            }
            if (turn_count == 9) {
                std::cout << "tie \n";
                return false;
            }
            return true;
        }

        int end() {
            // who wins?
            // theres like 8 ways to win
            // just check for those
            int xes = 0;
            int os = 0;
            // horizontal
            if (set[0] == 1 && set[1] == 1 && set[2] == 1)
                xes = 1;
            if (set[3] == 1 && set[4] == 1 && set[5] == 1)
                xes = 1;
            if (set[6] == 1 && set[7] == 1 && set[8] == 1)
                xes = 1;

            if (set[0] == 2 && set[1] == 2 && set[2] == 2)
                os = 1;
            if (set[3] == 2 && set[4] == 2 && set[5] == 2)
                os = 1;
            if (set[6] == 2 && set[7] == 2 && set[8] == 2)
                os = 1;
            // vertical
            if (set[0] == 1 && set[3] == 1 && set[6] == 1)
                xes = 1;
            if (set[1] == 1 && set[4] == 1 && set[7] == 1)
                xes = 1;
            if (set[2] == 1 && set[5] == 1 && set[8] == 1)
                xes = 1;

            if (set[0] == 2 && set[3] == 2 && set[6] == 2)
                os = 1;
            if (set[1] == 2 && set[4] == 2 && set[7] == 2)
                os = 1;
            if (set[2] == 2 && set[5] == 2 && set[8] == 2)
                os = 1;

            //diagonal
            if (set[0] == 1 && set[4] == 1 && set[8] == 1)
                xes = 1;
            if (set[6] == 1 && set[4] == 1 && set[2] == 1)
                xes = 1;

            if (set[0] == 2 && set[4] == 2 && set[8] == 2)
                os = 1;
            if (set[6] == 2 && set[4] == 2 && set[2] == 2)
                os = 1;

            if (xes)
                return 2;

            if (os)
                return 1;

            return 0;
        }

        tictactoe g;
        int set[9];
        int turn_count;
        int turn;
        int slot;
        int victor;
};

#endif
