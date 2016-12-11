#ifndef POPULATION_H
#define POPULATION_H

#include "chromosome.h"
<<<<<<< HEAD
=======
<<<<<<< HEAD
>>>>>>> 1f6a959e4363710bf4e322eb8115ae1c9b0355bf
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



<<<<<<< HEAD
=======
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
>>>>>>> 1f6a959e4363710bf4e322eb8115ae1c9b0355bf
#endif // POPULATION_H
