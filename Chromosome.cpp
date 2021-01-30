#include <iostream>
#include "Chromosome.h"
#include "Board.h"

Chromosome::Chromosome(int b)
{
    map.insert(make_pair(b, 0));
    list.push_front(b);
}

void Chromosome::mutate()
{
    // guard against removing original
    if (list.size() <= 1)
        return;

    // get current position
    Board b(list.back());

    //remove from solution
    list.pop_back();
    map.erase(b.calculateHash());

    //grow
    growNoCycle();

}


bool Chromosome::growNoCycle()
{
    Board b(list.back());
    int* moves = b.getMoves();

    // calculate how many moves there are
    int i;
    for (i = 0; i < 4; i++)
    {
        if (moves[i] == 0)
        {
            break;
        }
    }
    // goto random move that hasn't been explored before 
    for(int j=0; j<i; j++)
    {
        // get random index
        int r = rand() % i;

        if (map.count(moves[r]) == 0)
        {
            // add to map and list
            map.insert(make_pair(moves[r], list.size()));
            list.push_back(moves[r]);
            return true;
        }
    }

    return false;

}

int Chromosome::getStatus() const
{
    return list.back();
}

double Chromosome::getFitness() const
{
    return Board(getStatus()).calculateFitness();
}

bool Chromosome::operator<(const Chromosome& rhs) const
{
    if ((getFitness() - rhs.getFitness()) <= 0) return false;
    return true;
}

bool Chromosome::solved()
{
    if (getStatus() == BoardSpace::goalBoardHash) return true;
    else return false;
}

void Chromosome::print()
{
    std::cout << "Initial Position:" << std::endl;
    Board(list[0]).prettyPrint();

    for(int i=1; i<list.size(); i++)
    {
        std::cout << "Move Number: " << i << std::endl;
        std::cout << "Manhattan Distance:" << Board(list[i]).calculateManhattanDistance() << std::endl;
        std::cout << "Fitness: " << Board(list[i]).calculateFitness() << std::endl;
        Board(list[i]).prettyPrint();
    }
}

void Chromosome::crossover(Chromosome& strong)
{
    
    // can always insert at start so keep that is worst point
    int left = 0;
    int right = 0; 
    for (int i=strong.list.size()-1; i>=0; i--)
    {
        if (map.count(strong.list[i]))
        {
            auto weak = map.find(strong.list[i]);

            if (weak->second > left)
            {
                left = weak->second;
                right = i;
            }

        }
    }

    // remove everything to the right of left in weak
    int weak_size = list.size();
    for (int i=(left+1); i<weak_size; i++)
    {
        int weak_hash = list[list.size()-1];
        list.pop_back();
        map.erase(weak_hash);
    }


    //copy over strongs right side
    for (int i=(right+1); i<strong.list.size(); i++)
    {
        map.insert(make_pair(strong.list[i], i));
        list.push_back(strong.list[i]);
    }

}

