#include <vector>
#include <cstring>

#pragma once

class Board
{
private:
    int board[9];
    int moves[4];

    void calcMoves();

public:
    Board(const char *conf);
    Board(const int arrayBoard[9]);
    Board(int hash);

    int calculateHash();
    int calculateManhattanDistance();
    double calculateFitness() { return 1 - calculateManhattanDistance() * 0.01;}
    int * getBoard() { return board; }
    int * getMoves() { calcMoves(); return moves; }
    void prettyPrint();
};

namespace BoardSpace
{
    // The delta board is the correct order cyclically moved 2 places to the right
    // This is because the algorithm we are using uses indexing as a way to calculate the distance a misplaced tile should be placed in
    const int deltaBoard[] = {8, 0, 1, 2, 3, 4, 5, 6, 7 };
    const int goalBoardHash = 123456780;

    int getCol(int);
    int getRow(int);
    void swap(int*, int, int);
}

