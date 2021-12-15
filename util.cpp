#include "util.h"

 int checkWin(std::array<int, 9> set) {
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
        return -1;

    if (os)
        return 1;

    bool flag = false;
    if (!xes && !os) {
        for (int i = 0; i < 9; i++) {
            if (set[i] != 0) {
                flag = true;
            }
        }
        if (!flag)
            return 500;
    }

    return 0;
}


