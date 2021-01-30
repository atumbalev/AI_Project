#pragma once

#include <vector>
#include <algorithm>
#include "Chromosome.h"

class Population
{
    private:
        int id;
        vector<Solution> solutions;
        map<int,int> uniques;

    public:
        Population(int, int, int);
        void sort();
        void age();
        bool checkSolved();
        Solution getBest();
        void mutate(int);
        void selection(int, int);
        int getUniqueIndividuals();
};

