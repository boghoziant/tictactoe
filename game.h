#ifndef GAME_H
#define GAME_H

#include "tictactoe.h"
#include "ai.h"

#include <iostream>
#include <vector>

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
                std::cout <<"is this working when it shouldn't?" << std::endl;
                slot = player2.makeAMove(possible_moves, set);
            }

            // check for repeat moves 
            flag = true;
            for (int i = 0; i < possible_moves.size(); i++) {
                if (possible_moves[i] == slot) {
                    flag = false;
                }
            }
            if (flag) {
                std::cout << "slot full, pick another" << std::endl;
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

            // next turn
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
                xes = 1; if (set[1] == 1 && set[4] == 1 && set[7] == 1)
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
        Ai player2;
        bool ai;
        int set[9];
        std::vector<int> possible_moves;
        int turn_count;
        int turn;
        int slot;
        int victor;
        bool flag;
};

#endif
