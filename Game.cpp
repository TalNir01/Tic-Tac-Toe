//
// Created by talni on 14/10/2022.
//

#include "Game.h"
#include "OptimalPlayer.h"

Game::Game() {
    // Game object constructor.
    gb = GameBoard(); // Initialize gameboard
    GameBoard::printRules(); // Print rules

    mode gameMode = Game::getGameMode();

    if (gameMode == REAL_MODE)
    {
        this->realGameMode();
    }
    else if (gameMode == BOT_MODE)
    {
        this->botGameMode();
    }

}

mode Game::getGameMode() {
    int gameMode{};
    try {
        std::cout << "Please chose game mode. 1 or 2" << std::endl;
        std::cout << "System -> mode: ";
        std::cin >> gameMode;
        return (mode)gameMode;
    }
    catch(std::exception& e)
    {
        std::cout << "An error occurred, closing game..." << std::endl;
        return EXIT_MODE;
    }


}

void Game::realGameMode() {
    std::cout << "Alright let's start playing... " << std::endl;
    std::cout << "O starts..." << std::endl;
    signs currentTurn;
    signs winnerSign;
    while(this->gb.winner() == N && this->gb.numOfFreeSpaces > 0)
    {
        currentTurn = this->gb.getCurrentTurn();

        std::cout << this->gb << std::endl; // Printing current game board

        this->userMove(currentTurn);

    }

    winnerSign = this->gb.winner();

    if (winnerSign != N)
    {
        char playerSign;
        if(winnerSign == X)
            playerSign = 'X';
        else
            playerSign = 'O';

        std::cout << std::endl;
        std::cout << std::endl;
        std::cout << "Congrats " << playerSign << ". You are the winner!" << std::endl;

    }


}

void Game::botGameMode() {
    std::cout << "Alright let's start playing... " << std::endl;
    std::cout << "O starts..." << std::endl;
    signs currentTurn;
    signs winnerSign;
    while(this->gb.winner() == N && this->gb.numOfFreeSpaces > 0)
    {
        currentTurn = this->gb.getCurrentTurn();

        std::cout << this->gb << std::endl; // Printing current game board
        if (currentTurn == X)
        {
            this->botMove();
        }
        else{
            this->userMove(O);
        }
    }

    winnerSign = this->gb.winner();

    if (winnerSign != N)
    {
        char playerSign;
        if(winnerSign == X)
            playerSign = 'X';
        else
            playerSign = 'O';

        std::cout << std::endl;
        std::cout << std::endl;
        std::cout << "Congrats " << playerSign << ". You are the winner!" << std::endl;

    }



}

void Game::userMove(signs player) {
    char player_representation;
    int x{}, y{};
    if(player == X)
        player_representation = 'X';
    else
        player_representation = 'O';

    HandlePlayerInput:

    try {
        std::cout << "Hey player " << player_representation << " :)" << std::endl;
        std::cout << "Please enter a valid Y value: ";
        std::cin >> y;
        std::cout << std::endl;
        std::cout << "Please enter a valid X value: ";
        std::cin >> x;

        std::cout << "\nGreat! Lets make that happen!!!" << std::endl;

        if(this->gb.setVal(player, y, x))
        {
            std::cout << player_representation << " has made a move. At y = " << y << " , x = " << x << std::endl;
            std::cout << std::endl;
        }
        else
        {
            //std::cout << x << y << this->gb.numOfFreeSpaces << std::endl;
            std::cout << "Move cannot be made... Let's try again. " << std::endl;
            goto HandlePlayerInput;
        }
    }
    catch (std::exception& e){
        std::cout << "Bad Boy!!! Lets try again..." << std::endl;
        goto HandlePlayerInput;
    }

}

void Game::botMove() {
    int x{}, y{};

    signs board[BOARD_SIZE][BOARD_SIZE]{N, N, N, N, N, N, N, N, N}; // The board initialization

    this->gb.getCurrentGameState(board);// Setting board state


    try {

        OptimalPlayer::Move bestMove = OptimalPlayer::findBestMove(board); // returning best possible move according to minimax

        x = bestMove.col;
        y = bestMove.row;

        if(this->gb.setVal(X, y, x))
        {

            std::cout << "Move has been made :)" << std::endl;

            std::cout << "X has made a move. At y = " << y << " , x = " << x << std::endl;

            std::cout << std::endl;
            std::cout << std::endl;


        }
        else
        {
            std::cout << "Problematic move... Let's try again. " << std::endl;
        }
    }
    catch (std::exception& e){
        std::cout << "Bad Boy!!! Lets try again..." << std::endl;
    }
}
