//
// Created by talni on 14/10/2022.
//

#ifndef TICTACTOE_GAME_H
#define TICTACTOE_GAME_H
#include "GameBoard.h"

class Game {
public:

    Game();

private:

    static mode getGameMode();

    GameBoard gb;

    void userMove(signs player);

    void realGameMode();

    void botGameMode();

    void botMove();

};


#endif //TICTACTOE_GAME_H
