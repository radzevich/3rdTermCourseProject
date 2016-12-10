#ifndef POPULATION_H
#define POPULATION_H

#include "chromosome.h"

#define POPULATION 16

class Population
{
private:
    Chromosome population[POPULATION];
public:
    Population();
};

#endif // POPULATION_H
