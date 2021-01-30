#include <cmath>
#include "Population.h"
#include <map>

Population::Population(int _id, int size, int _boardStart)
{
    id = _id;
    solutions.reserve(size);

    auto it = solutions.begin();

    for (int i=0; i<size; i++)
        it = solutions.insert(it, Chromosome(_boardStart));
}

Chromosome Population::getBest()
{
    return solutions[0];
}
    
bool Population::checkSolved()
{
    return solutions[0].solved();
}

void Population::sort()
{
    std::sort(solutions.begin(), solutions.end());
}

void Population::selection(int elites, int cm)
{
   for (int i=elites; i<solutions.size(); i++)
   {
        // only crossover with certain probability
        int r = rand() % cm;
        if (r==0)
            solutions[i].crossover(solutions[i%elites]);
   }
}
void Population::age()
{ 
    id++;
}


void Population::mutate(int mrate)
{
    for (int i=0; i<solutions.size(); i++)
    {
        int r = rand() % mrate;
        if (r == 0)
        {
            switch (rand() % 2)
            {
                case 0:
                    solutions[i].growNoCycle();
                    break;
                case 1:
                    solutions[i].mutate();
                    break;
            }
        }
    }
}

