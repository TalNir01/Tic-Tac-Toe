//
// Created by talni on 13/10/2022.
//

#include "GameBoard.h"

signs GameBoard::winner() {

    // --------- Check Rows

    //Check Row 0
    if(this->board[0][0] == this->board[0][1] && this->board[0][1] == this->board[0][2] && this->board[0][0] != N)
        return this->board[0][0];

    //Check Row 1
    if(this->board[1][0] == this->board[1][1] && this->board[1][1] == this->board[1][2] && this->board[1][0] != N)
        return this->board[1][0];

    //Check Row 2
    if(this->board[2][0] == this->board[2][1] && this->board[2][1] == this->board[2][2] && this->board[2][0] != N)
        return this->board[2][0];


    // ------- Check Columns

    //Check column 0
    if(this->board[0][0] == this->board[1][0] && this->board[1][0] == this->board[2][0] && this->board[0][0] != N)
        return this->board[0][0];

    //Check column 1
    if(this->board[0][1] == this->board[1][1] && this->board[1][1] == this->board[2][1] && this->board[0][1] != N)
        return this->board[0][1];

    //Check column 2
    if(this->board[0][2] == this->board[1][2] && this->board[1][2] == this->board[2][2] && this->board[0][2] != N)
        return this->board[0][2];


    // ------- Check Diagonals

    //Check diagonal 1
    if(this->board[0][0] == this->board[1][1] && this->board[1][1] == this->board[2][2] && this->board[0][0] != N)
        return this->board[0][0];

    //Check diagonal 2
    if(this->board[0][2] == this->board[1][1] && this->board[1][1] == this->board[2][0] && this->board[0][0] != N)
        return this->board[0][2];

    return N;
}

signs GameBoard::getVal(int y, int x) { //[y][x]
    if(x < 0 || x >= BOARD_SIZE || y < 0 || y >= BOARD_SIZE)
        return D;
    else
        return this->board[y][x];
}


bool GameBoard::setVal(signs player_sign, int y, int x) {
    if(x < 0 || x >= BOARD_SIZE || y < 0 || y >= BOARD_SIZE || this->numOfFreeSpaces == 0 || this->turn != player_sign)
        return false;

    if(this->board[y][x] != N)
        return false;

    this->turn = (signs)(3 - this->turn);


    this->board[y][x] = player_sign;

    this->numOfFreeSpaces--;

    return true;

}

std::ostream &operator<<(std::ostream &out, const GameBoard &point) {
    //y,x


    std::string printOut;

    for(int y = 0; y < BOARD_SIZE; ++y) {
        printOut.append(" | ");
        for(int x = 0; x < BOARD_SIZE; ++x) {
            if (point.board[y][x] == N)
                printOut.append(" ");
            else if(point.board[y][x] == X)
                printOut.append("X");
            else
                printOut.append("O");
            printOut.append(" | ");

        }
        printOut.append("\n");
        printOut.append("--------------");
        printOut.append("\n");


    }

    out << printOut << std::endl;

    return out;
}



void GameBoard::printRules() {
    std::cout << "Welcome to TIC-TAC_TOE!!!!" << std::endl;
    std::cout << "The rules are the same as the regular game" << std::endl;
    std::cout << "In each turn the player will chose the X, Y coordinates he would like to play in." << std::endl;
    std::cout << "'O' starts..." << std::endl;
    std::cout << "The Board game: (y,x) format" << std::endl;
    std::cout << "| (0,0) | (0,1) | (0,2) |" << std::endl;
    std::cout << "-------------------------" << std::endl;
    std::cout << "| (1,0) | (1,1) | (1,2) |" << std::endl;
    std::cout << "-------------------------" << std::endl;
    std::cout << "| (2,0) | (2,1) | (2,2) |" << std::endl;

    std::cout << "There are 2 main games modes:" << std::endl;
    std::cout << "Mode #1 - Two real players play using the stdio format." << std::endl;
    std::cout << "Mode #2 - You (O) play against an optimal-strategy bot (X)" << std::endl;

}

signs GameBoard::getCurrentTurn() {
    return this->turn;
}

void GameBoard::getCurrentGameState(signs board[BOARD_SIZE][BOARD_SIZE]) {
    for (int y = 0; y < BOARD_SIZE; ++y) {

        for (int x = 0; x < BOARD_SIZE; ++x) {
            board[y][x] = this->board[y][x];
        }
    }

}
