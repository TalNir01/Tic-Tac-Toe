//
// Created by talni on 13/10/2022.
//

#ifndef TICTACTOE_GAMEBOARD_H
#define TICTACTOE_GAMEBOARD_H

#include "utility.h"

#define BOARD_SIZE 3

// Row Number == Y value;
// Columns == X value;

class GameBoard {

public:

    GameBoard()
    {
        this->numOfFreeSpaces = 9;
        this->turn = O; // O starts
    }

    signs getVal(int y, int x); // Location is [y][x]

    static void printRules(); // Will print the main rules

    void getCurrentGameState(signs board[BOARD_SIZE][BOARD_SIZE]);

    bool setVal(signs player_sign, int y, int x);// Location is [y][x], also switch turn

    friend std::ostream& operator<< (std::ostream& out, const GameBoard& gb); // overload for the << cout output.

    signs winner(); // Return the winner sign or if there's none return N

    int numOfFreeSpaces; // Counter of left spaces.

    signs getCurrentTurn();

private:

    signs board[BOARD_SIZE][BOARD_SIZE]{N, N, N, N, N, N, N, N, N}; // The board initialization

    signs turn; // will hold the sign of the current player turn.


};


#endif //TICTACTOE_GAMEBOARD_H
