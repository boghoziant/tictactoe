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
    int move;
    // For every position on the board
    for (int i = 0; i < 9; i++) {
        // if there's an available move
        if (set[i] == 0) {
            // check it's score
            set[i] = 1;
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
   // doesn't check for tie
   // check for win
   int result = checkWin(set);
   if (result == -1) {
       return -1;
   } else if (result == 1) {
       return 1;
   } else if (result == 500) {
       return 0;
   }

    int bestMove = 10;
    int score = 0;
   if (isMax) {
    for (int i = 0; i < 9; i++) {
        // if there's an available move
        if (set[i] == 0) {
            // check it's score
            set[i] = 2;
            score = miniMax(set, depth + 1, false);
            set[i] = 0;
            // and remember it if it's the highest so far
            if (score > bestMove && score < 500) {
                bestMove = score;
            }
        }
    }
    return bestMove;
   } else {
    for (int i = 0; i < 9; i++) {
        // if there's an available move
        if (set[i] == 0) {
            // check it's score
            set[i] = 1;
            score = miniMax(set, depth + 1, true);
            set[i] = 0;
            // and remember it if it's the highest so far
            if (score < bestMove) {
                bestMove = score;
            }
        }
    }
    return bestMove;
   }
}

int Ai::evaluate() {
    int eval = 0;
    return eval;
}
