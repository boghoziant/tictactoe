#ifndef TIC_H
#define TIC_H

#include <iostream>

class tictactoe {
    public:

        tictactoe();
        
        void write_xo(int type, int slot);
    
        void display_board();
    
        int rows;
        int columns;
        int xes[9];
        int os[9];
        char board_buffer[8][17];

};

#endif
