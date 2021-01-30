#pragma once

#include <map>
#include <deque>

#include "Board.h"

using namespace std;

class Chromosome
{
public:
        multimap<int, int> map;
        deque<int> list;

        Chromosome(int);
        bool growNoCycle();
        void mutate();
        int getStatus() const;
        bool operator<(const Chromosome& rhs) const;
        double getFitness() const;
        bool solved();
        void print();
        void crossover(Chromosome&);
};