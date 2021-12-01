#include <iostream>
#include "tictactoe.h"

using namespace std;

tictactoe::tictactoe() {
    // todo: switch i's and j's to this
    rows = 8;
    columns = 17;

    // no x's or o's
    for (int i = 0; i < 9; i++) {
        xes[i] = 0;
        os[i] = 0;
    }

    // draw board
    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 17; j++) {
            board_buffer[i][j] = ' ';
        }
    }

    // columns
    for (int i = 0; i < 8; i++) {
        board_buffer[i][5] = '|';
        board_buffer[i][10] = '|';
    }

    // rows
    for (int i = 0; i < 17; i++) {
        board_buffer[2][i] = '-';
        board_buffer[5][i] = '-';
    }


}

void tictactoe::write_xo(int type, int slot) {
    int row_offset = 0;
    int col_offset = 0;
    switch (slot) {
        case 0:
            row_offset = 0;
            col_offset = 0;
            break;
        case 1:
            row_offset = 0;
            col_offset = 5;
            break;
        case 2:
            row_offset = 0;
            col_offset = 10;
            break;
        case 3:
            row_offset = 3;
            col_offset = 0;
            break;
        case 4:
            row_offset = 3;
            col_offset = 5;
            break;
        case 5:
            row_offset = 3;
            col_offset = 10;
            break;
        case 6:
            row_offset = 6;
            col_offset = 0;
            break;
        case 7:
            row_offset = 6;
            col_offset = 5;
            break;
        case 8:
            row_offset = 6;
            col_offset = 10;
            break;
    }

    if (type == 0) {
        board_buffer[0+row_offset][1+col_offset] = '\\';
        board_buffer[0+row_offset][3+col_offset] = '/';
        board_buffer[1+row_offset][1+col_offset] = '/';
        board_buffer[1+row_offset][3+col_offset] = '\\';
    } else {
        board_buffer[0+row_offset][2+col_offset] = '_';
        board_buffer[1+row_offset][1+col_offset] = '(';
        board_buffer[1+row_offset][2+col_offset] = '_';
        board_buffer[1+row_offset][3+col_offset] = ')';
    }
}

void tictactoe::display_board() {
    for (int i = 0; i < 8; i++) { 
        for (int j = 0; j < 17; j++) {
            cout << board_buffer[i][j];
        }
        cout << '\n';
    }
}
