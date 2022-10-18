//
// Created by talni on 17/10/2022.
//

#ifndef TICTACTOE_OPTIMALPLAYER_H
#define TICTACTOE_OPTIMALPLAYER_H

#include "GameBoard.h"


class OptimalPlayer {
public:

    struct Move{
        int row, col; // col = x , row = y
    };

    static const signs player = X, opponent = O;

    static bool isMovesLeft(signs board[BOARD_SIZE][BOARD_SIZE]);

    static int evaluate(signs board[BOARD_SIZE][BOARD_SIZE]);

    static int minimax(signs board[BOARD_SIZE][BOARD_SIZE], int depth, bool isMax);

    static Move findBestMove(signs board[BOARD_SIZE][BOARD_SIZE]);



};


#endif //TICTACTOE_OPTIMALPLAYER_H
