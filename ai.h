#ifndef AI_H
#define AI_H

#include <algorithm>
#include <random>

using namespace std;

class Ai {
    public:
        Ai(){}

        int makeAMove(vector<int> possible_moves, int set[]); 
        int miniMax(int position, int depth, bool maximizingPlayer);
        int evaluate();

        int state[16];
        int *board;
};
#endif
