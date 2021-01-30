#include <cstdlib>
#include <cstdio>
#include <ctime>
#include <iostream>
#include "Solution.h"
#include "Population.h"
#include "Board.h"

#define RAND_SEED time(0) 

// for both enhanced and bl use same pop/gen for fairness
#define POPULATION_SIZE 100
#define NUMBER_GENS 500 

// baseline
#define BL_SOLUTION_INIT_SIZE 10 
#define BL_ELITES 0.3
#define BL_MUTATION 1.0
#define BL_CROSSOVER 0.1


World::World(int board) : population(0, POPULATION_SIZE, board)
{
    pop_size = POPULATION_SIZE; 
    num_gens = NUMBER_GENS;
    origin = board;

    elites = (int) (BL_ELITES * pop_size);
    mutation = (int) 1 / BL_MUTATION;
    crossover = (int) 1 / BL_CROSSOVER;
    solved = false;

    // seed random number gen
    srand(RAND_SEED);
    std::cout << "\nWorld Created\n";
    std::cout << "Board: ";
    Board(origin).printConf();
    printf(", Population: %d, Generations: %d, Pc: %f, Pm: %f\n", 
            pop_size, num_gens, BL_CROSSOVER, BL_MUTATION);

    seedPopulation();
}

void World::seedPopulation()
{
    //initialize population
    for (int i=0; i< BL_SOLUTION_INIT_SIZE; i++)
    {
        population.mutate(1.0);
        population.sort();
        if (population.checkSolved())
        {
            printf("Got really lucky and grew into solution on initial population creation.\n");
            population.getBest().print();
            solved = true;
            break;
        }
    }

}

void World::start()
{

    int i;
    for(i=0; i<num_gens; i++)
    {
        // the following line is population^2 so really slow, only useful for
        // visualization in tuning
        // population.calcDiversity();
        int uniques = population.getUniqueIndividuals();

        population.mutate(mutation);
        population.sort();
        population.selection(elites,crossover);

        // if solution has been found break;
        if (population.checkSolved()) 
        {
            solved = true;
            break;
        }
        population.age();
    }

    printf("\n");

    population.getBest().print();
    if (solved)
    {
        printf("Solution Found in %d generations\n", i+1);
    }
    else printf("No solution Found\n");
}
