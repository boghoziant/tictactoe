#include "util.h"

 int checkWin(std::array<int, 9> set) {
    // who wins?
    // theres like 8 ways to win
    // just check for thxese
    int os = 0;
    int xes = 0;
    // horizontal
    if (set[0] == 1 && set[1] == 1 && set[2] == 1)
        os = 1;
    if (set[3] == 1 && set[4] == 1 && set[5] == 1)
        os = 1;
    if (set[6] == 1 && set[7] == 1 && set[8] == 1)
        os = 1;

    if (set[0] == 2 && set[1] == 2 && set[2] == 2)
        xes = 1;
    if (set[3] == 2 && set[4] == 2 && set[5] == 2)
        xes = 1;
    if (set[6] == 2 && set[7] == 2 && set[8] == 2)
        xes = 1;
    // vertical
    if (set[0] == 1 && set[3] == 1 && set[6] == 1) 
        os = 1; 
    if (set[1] == 1 && set[4] == 1 && set[7] == 1)
        os = 1;
    if (set[2] == 1 && set[5] == 1 && set[8] == 1)
        os = 1;

    if (set[0] == 2 && set[3] == 2 && set[6] == 2)
        xes = 1;
    if (set[1] == 2 && set[4] == 2 && set[7] == 2)
        xes = 1;
    if (set[2] == 2 && set[5] == 2 && set[8] == 2)
        xes = 1;

    //diagonal
    if (set[0] == 1 && set[4] == 1 && set[8] == 1)
        os = 1;
    if (set[6] == 1 && set[4] == 1 && set[2] == 1)
        os = 1;

    if (set[0] == 2 && set[4] == 2 && set[8] == 2)
        xes = 1;
    if (set[6] == 2 && set[4] == 2 && set[2] == 2)
        xes = 1;

    if (os)
        return 1;

    if (xes)
        return -1;

    bool noMovesLeft = true;
    for (int i = 0; i < 9; i++) {
        if (set[i] == 0) {
            noMovesLeft = false;
        }
    }
    if (noMovesLeft)
        return 500;

    return 0;
}


