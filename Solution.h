#pragma once

#include "Population.h"


class Solution
{
    private:
        int populationSize;
        int maxGeneration;
        int mutation;
        int crossover;
        int elites;
        Population population;
        void seedPopulation();

        
    public:
        Solution(int);
        void start();
        bool solved;
};
