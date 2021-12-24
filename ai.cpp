#include "ai.h"
#include "util.h"

#include <bits/stdc++.h>
#include <string>

using namespace std;

int Ai::makeAMove(vector<int> possible_moves, int turnsLeft, std::array<int, 9> set) {
    // pass all possible moves to minimax
    // record which one gets the best score
    int bestMove = INT_MIN;
    int score = 0;
    int move = 0;
    // For every position on the board
    for (int i = 0; i < 9; i++) {
        // if there's an available move
        if (set[i] == 0) {
            // check it's score
            set[i] = 1;
            int result = checkWin(set);
            if (result == 1)
                score = 1;
            else if (result == -1)
                score = -1;
            else if (result == 500)
                score = 0;
            else
                score = miniMax(set, 0, false);

            cout << "score: " << score << " bestMove: " << bestMove << endl;
            set[i] = 0;
            // and remember it if it's the highest so far
            if (score > bestMove && score < 500) {
                bestMove = score;
                move = i;
            }
        }
    }
    return move;
}

int Ai::miniMax(array<int, 9> set, int depth, bool isMax) {
    int score = 0;
    int bestMove;
    if (isMax)
        bestMove = INT_MIN;
    else
        bestMove = INT_MAX;
    for (int i = 0; i < 9; i++) {
        if (isMax) {
            // if there's an available move
            if (set[i] == 0) {
                // check it's score
                set[i] = 1;
                int result = checkWin(set);
                if (result == 1)
                    score = 1;
                else if (result == -1)
                    score = -1;
                else if (result == 500)
                    score = 0;
                else
                    score = miniMax(set, 0, false);

                set[i] = 0;

                if (score > bestMove && score < 500)
                    bestMove = score;
            }
        } else {
            // if there's an available move
            if (set[i] == 0) {
                // check it's score
                set[i] = 2;
                int result = checkWin(set);
                if (result == 1)
                    score = 1;
                else if (result == -1)
                    score = -1;
                else if (result == 500)
                    score = 0;
                else
                    score = miniMax(set, 0, true);

                set[i] = 0;

                if (score < bestMove && score < 500) {
                    bestMove = score;
                }

            } 
         }
    }
    return bestMove;
};

