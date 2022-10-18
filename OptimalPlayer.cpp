//
// Created by talni on 17/10/2022.
//

#include "OptimalPlayer.h"

// This function returns true if there are moves
// remaining on the board. It returns false if
// there are no moves left to play.
bool OptimalPlayer::isMovesLeft(signs (*board)[3]) {
    for (int i = 0; i<3; i++)
        for (int j = 0; j<3; j++)
            if (board[i][j] == N)
                return true;
    return false;
}


int OptimalPlayer::evaluate(signs (*board)[3]) {
// Checking for Rows for X or O victory.
    for (int row = 0; row<3; row++)
    {
        if (board[row][0]==board[row][1] &&
                board[row][1]==board[row][2])
        {
            if (board[row][0]==player)
                return +10;
            else if (board[row][0]==opponent)
                return -10;
        }
    }

    // Checking for Columns for X or O victory.
    for (int col = 0; col<3; col++)
    {
        if (board[0][col]==board[1][col] &&
            board[1][col]==board[2][col])
        {
            if (board[0][col]==player)
                return +10;
            else if (board[0][col]==opponent)
                return -10;
        }
    }

    // Checking for Diagonals for X or O victory.
    if (board[0][0]==board[1][1] && board[1][1]==board[2][2])
    {
        if (board[0][0]==player)
            return +10;
        else if (board[0][0]==opponent)
            return -10;
    }

    if (board[0][2] == board[1][1] && board[1][1] == board[2][0])
    {
        if (board[0][2]==player)
            return +10;
        else if (board[0][2]==opponent)
            return -10;
    }

    // Else if none of them have won then return 0
    return 0;
}

int OptimalPlayer::minimax(signs (*board)[3], int depth, bool isMax) {
    int score = evaluate(board);

    // If Maximizer has won the game return his/her
    // evaluated score
    if (score == 10)
        return score;

    // If Minimizer has won the game return his/her
    // evaluated score
    if (score == -10)
        return score;

    // If there are no more moves and no winner then
    // it is a tie
    if (!isMovesLeft(board))
        return 0;

    // If this maximizer's move
    if (isMax)
    {
        int best = -1000;

        // Traverse all cells
        for (int i = 0; i<3; i++)
        {
            for (int j = 0; j<3; j++)
            {
                // Check if cell is empty
                if (board[i][j]== N)
                {
                    // Make the move
                    board[i][j] = player;

                    // Call minimax recursively and choose
                    // the maximum value
                    best = std::max( best,
                                minimax(board, depth+1, !isMax) );

                    // Undo the move
                    board[i][j] = N;
                }
            }
        }
        return best;
    }// If this minimizer's move
    else
    {
        int best = 1000;

        // Traverse all cells
        for (int i = 0; i<3; i++)
        {
            for (int j = 0; j<3; j++)
            {
                // Check if cell is empty
                if (board[i][j]== N)
                {
                    // Make the move
                    board[i][j] = opponent;

                    // Call minimax recursively and choose
                    // the minimum value
                    best = std::min(best, minimax(board, depth+1, !isMax));

                    // Undo the move
                    board[i][j] = N;
                }
            }
        }
        return best;
    }
}

OptimalPlayer::Move OptimalPlayer::findBestMove(signs (*board)[3]) {
    int bestVal = -1000;
    OptimalPlayer::Move bestMove;
    bestMove.row = -1;
    bestMove.col = -1;

    // Traverse all cells, evaluate minimax function for
    // all empty cells. And return the cell with optimal
    // value.
    for (int i = 0; i<3; i++)
    {
        for (int j = 0; j<3; j++)
        {
            // Check if cell is empty
            if (board[i][j] == N)
            {
                // Make the move
                board[i][j] = player;

                // compute evaluation function for this
                // move.
                int moveVal = minimax(board, 0, false);

                // Undo the move
                board[i][j] = N;

                // If the value of the current move is
                // more than the best value, then update
                // best/
                if (moveVal > bestVal)
                {
                    bestMove.row = i;
                    bestMove.col = j;
                    bestVal = moveVal;
                }
            }
        }
    }

    printf("The value of the best Move is : %d\n\n",
           bestVal);

    return bestMove;
}
