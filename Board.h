#pragma once

#include <vector>
#include <cstring>

class Board
{
    private:
        int board[9];
        int hash;
        int manhattan;
        int moves[4];
        double fitness;

        void calcHash();
        void calcManhattan();

        void calcMoves();
        void calcFitness();

    public:
        Board(const char *conf);
        Board(const int arrayBoard[9]);
        Board(const int hash); 

        int getHash() { calcHash(); return hash; }
        int getManhattan() { calcManhattan(); return manhattan; }
        double getFitness() { calcFitness(); return fitness; }
        int * getBoard() { return board; }
        int * getMoves() { calcMoves(); return moves; }
        void prettyPrint();
        void printConf();
};

namespace BoardSpace
{
    const int goalBoard[9] = { 8, 0, 1, 2, 3, 4, 5, 6, 7 };
    const int goalBoardHash = 123456780; 

    int getCol(int);
    int getRow(int);
    void swap(int*, int, int);
}

