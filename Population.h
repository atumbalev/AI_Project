#pragma once

#include <vector>
#include <algorithm>
#include "Chromosome.h"

class Population
{
    private:
        int id;
        vector<Chromosome> solutions;

    public:
        Population(int, int, int);
        void sort();
        void age();
        bool checkSolved();
        Chromosome getBest();
        void mutate(int);
        void selection(int, int);
};

