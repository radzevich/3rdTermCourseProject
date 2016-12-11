#ifndef POPULATION_H
#define POPULATION_H

#include "chromosome.h"
<<<<<<< HEAD
#include "cexpression.h"

#define POPULATION 16

typedef struct TPopulationList
{

    TPopulationList()
    {
        data = new Chromosome (CExpression :: getSourceExpression ());
        next = NULL;
    }
} TPopulationList;


class PopulationList
{
private:

    Chromosome *data;

    TPopulationList *next;


    static CExpression *sourceExpression;

    unsigned int populationSize;

    TPopulationList *populationList;

    void createPopulationList ();

public:
    PopulationList(CExpression *expression);

    static CExpression *getSourceExpression ();
};



=======

#define POPULATION 16

class Population
{
private:
    Chromosome population[POPULATION];
public:
    Population();
};

>>>>>>> 60419dbe49e5674adf5b4a11c7815d27be15c0ce
#endif // POPULATION_H
