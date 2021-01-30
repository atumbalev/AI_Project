#pragma once

#include "Population.h"


class World
{
    private:
        int pop_size;
        int num_gens;
        int mutation;
        int crossover;
        int origin;
        int elites;
        Population population;
        void seedPopulation();

        
    public:
        World(int);
        void start();
        bool solved;
};
