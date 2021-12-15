#ifndef AI_H
#define AI_H

#include <algorithm>
#include <random>
#include <array>
#include <vector>

using namespace std;

class Ai {
    public:
        Ai(){}

        int makeAMove(vector<int> possible_moves, int turnsLeft, std::array<int, 9> set); 
        int miniMax(array<int, 9> set, int depth, bool isMax);
        int evaluate();

        int state[16];
        //int *board;
};
#endif
