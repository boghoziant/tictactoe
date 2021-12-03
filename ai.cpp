#include "ai.h"

#include <bits/stdc++.h>

using namespace std;

int Ai::makeAMove(vector<int> possible_moves, int set[]) {
    board = set;
    auto rng = std::default_random_engine {};
    std::shuffle(std::begin(possible_moves), std::end(possible_moves), rng);
    int slot = possible_moves.back();
    possible_moves.pop_back();
    return slot;
}

int Ai::miniMax(int position, int depth, bool maximizingPlayer) {
	if (depth == 0) //or game over in position
		return evaluate();

	if (maximizingPlayer) {
		int maxEval = INT_MIN;
		for (int i = 1; i < 3; i++) {
			int eval = miniMax(2 * position + i, depth - 1, false);
			int maxEval = max(maxEval, eval);
        }
		return maxEval;
    } else {
		int minEval = INT_MAX;
		for (int i = 1; i < 3; i++) {
			int eval = miniMax(2 * position + i, depth - 1, true);
			int minEval = min(minEval, eval);
        }
		return minEval;
    }
}

int Ai::evaluate() {

    // positive for anything in a row
    // so look at board and rate based on how many 
    // markers each side has
    // e.g., 2 x's in a row is positive 2 o's negative
    // does the game evaluate or the AI?
    // could also pass in the board state, i guess I have to

    int eval = 0;
    int prev = 0;
    for (int i = 0; i < 9; i++) {
        if (board[i] == 1 && board[i] == prev) {
            eval++;
        }

        if (board[i] == 2 && board[i] == prev) {
            eval--;
        }
        prev = board[i];
    }

    return eval;
}
