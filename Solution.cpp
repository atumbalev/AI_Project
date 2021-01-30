#include <iostream>
#include <ctime>
#include <iostream>
#include "Solution.h"
#include "Board.h"

#define RAND_SEED time(0) 

// for both enhanced and bl use same pop/gen for fairness
#define POPULATION_SIZE 100
#define NUMBER_GENS 500 

// baseline
#define SOLUTION_INIT_SIZE 10
#define ELITES 0.3
#define MUTATION 0.7
#define CROSSOVER 0.1


Solution::Solution(int board) : population(0, POPULATION_SIZE, board)
{
    populationSize = POPULATION_SIZE;
    maxGeneration = NUMBER_GENS;

    elites = (int) (ELITES * populationSize);
    mutation = (int) (1 / MUTATION);
    crossover = (int) (1 / CROSSOVER);
    solved = false;

    // seed random number gen
    srand(RAND_SEED);
    std::cout << "\nSolution Created\n";
    std::cout << "Population: " << populationSize <<
                 ", Generations: " << maxGeneration <<
                 ", Crossover: " << CROSSOVER * 100 << "% , Mutation: " << MUTATION * 100 << '%' << std::endl;

    seedPopulation();
}

void Solution::seedPopulation()
{
    //initialize population
    for (int i=0; i < SOLUTION_INIT_SIZE; i++)
    {
        population.mutate(1.0);
        population.sort();
        if (population.checkSolved())
        {
            population.getBest().print();
            solved = true;
            break;
        }
    }

}

void Solution::start()
{

    int i;
    for(i=0; i < maxGeneration; i++)
    {
        population.mutate(mutation);
        population.sort();
        population.selection(elites, crossover);

        // if solution has been found break;
        if (population.checkSolved()) 
        {
            solved = true;
            break;
        }
        population.age();
    }

    std::cout << std::endl;

    population.getBest().print();
    if (solved)
    {
        std::cout << "Solution Found in " << i + 1 << " generations" << std::endl;
    }
    else
    {
        std::cout << "No solution Found" << std::endl;
    }
}
