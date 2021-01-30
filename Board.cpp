#include <iostream>
#include <cmath>
#include "Board.h"

using namespace std;
using namespace BoardSpace;


Board::Board(const char *conf)
{
    for (int i=0; i<9; i++)
    {
        // convert from ascii to decimal
        board[i] =  ((int)conf[i]) - 48;
    }
}

Board::Board(const int arrayBoard[9])
{
    for (int i=0; i<9; i++)
        board[i] = arrayBoard[i];
}

Board::Board(int hash)
{
    int hashCopy = hash;
    for (int i = 0; i < 9; i++)
    {
        board[8 - i] = hashCopy % 10;
        hashCopy /= 10;
    }

}

void Board::prettyPrint()
{
    for (int i = 0; i < 9; i++)
    {
        std::cout << board[i] << ' ';
        if (i>1 && ( i + 1) % 3 == 0)
        {
            std::cout << std::endl;
        }
    }
    std::cout << std::endl;
}

void Board::calcMoves()
{
    int i;

    // clear moves
    for (i=0; i<4; i++)
        moves[i] = 0;

    // find zero spot
    for(i=0; i<9; i++)
        if (board[i] == 0) break;

    // to keep track of what move is on
    int j = 0;
    int *b = getBoard();
    switch (i)
    {
        case 0:
            swap(b, 0, 1);
            moves[j++] = Board(b).calculateHash();
            swap(b, 0, 1);
            swap(b, 0, 3);
            moves[j++] = Board(b).calculateHash();
            swap(b, 0, 3);
            break;
        case 1:
            swap(b, 1, 0);
            moves[j++] = Board(b).calculateHash();
            swap(b, 1, 0);
            swap(b, 1, 2);
            moves[j++] = Board(b).calculateHash();
            swap(b, 1, 2);
            swap(b, 1, 4);
            moves[j++] = Board(b).calculateHash();
            swap(b, 1, 4);
            break;
        case 2:
            swap(b, 2, 1);
            moves[j++] = Board(b).calculateHash();
            swap(b, 2, 1);
            swap(b, 2, 5);
            moves[j++] = Board(b).calculateHash();
            swap(b, 2, 5);
            break;
        case 3:
            swap(b, 3, 0);
            moves[j++] = Board(b).calculateHash();
            swap(b, 3, 0);
            swap(b, 3, 4);
            moves[j++] = Board(b).calculateHash();
            swap(b, 3, 4);
            swap(b, 3, 6);
            moves[j++] = Board(b).calculateHash();
            swap(b, 3, 6);
            break;
        case 4:
            swap(b, 4, 1);
            moves[j++] = Board(b).calculateHash();
            swap(b, 4, 1);
            swap(b, 4, 3);
            moves[j++] = Board(b).calculateHash();
            swap(b, 4, 3);
            swap(b, 4, 5);
            moves[j++] = Board(b).calculateHash();
            swap(b, 4, 5);
            swap(b, 4, 7);
            moves[j++] = Board(b).calculateHash();
            swap(b, 4, 7);
            break;
        case 5:
            swap(b, 5, 2);
            moves[j++] = Board(b).calculateHash();
            swap(b, 5, 2);
            swap(b, 5, 4);
            moves[j++] = Board(b).calculateHash();
            swap(b, 5, 4);
            swap(b, 5, 8);
            moves[j++] = Board(b).calculateHash();
            swap(b, 5, 8);
            break;
        case 6:
            swap(b, 6, 3);
            moves[j++] = Board(b).calculateHash();
            swap(b, 6, 3);
            swap(b, 6, 7);
            moves[j++] = Board(b).calculateHash();
            swap(b, 6, 7);
            break;
        case 7:
            swap(b, 7, 4);
            moves[j++] = Board(b).calculateHash();
            swap(b, 7, 4);
            swap(b, 7, 6);
            moves[j++] = Board(b).calculateHash();
            swap(b, 7, 6);
            swap(b, 7, 8);
            moves[j++] = Board(b).calculateHash();
            swap(b, 7, 8);
            break;
        case 8:
            swap(b, 8, 5);
            moves[j++] = Board(b).calculateHash();
            swap(b, 8, 5);
            swap(b, 8, 7);
            moves[j++] = Board(b).calculateHash();
            swap(b, 8, 7);
            break;
    }
}

int Board::calculateHash()
{
    int hash = 0;
    for (int i=0; i<9; i++)
        hash = hash + board[8-i] * (int) pow(10.0, (double) i);

    return hash;
}

int Board::calculateManhattanDistance()
{
    int manhattan = 0;
    for (int i=0; i<9; i++)
    {
        int xd = abs(getCol(i) - getCol(deltaBoard[board[i]]));
        int yd = abs(getRow(i) - getRow(deltaBoard[board[i]]));

        manhattan += xd + yd;
    }
    return manhattan;
}

int BoardSpace::getCol(int i)
{
    return i % 3;
}

int BoardSpace::getRow(int i)
{
    return i / 3;
}

void BoardSpace::swap(int* board, int src, int dest)
{
    int temp = board[dest];
    board[dest] = board[src];
    board[src] = temp;
}