#ifndef POPULATION_H
#define POPULATION_H

#include "chromosome.h"
<<<<<<< HEAD
=======
<<<<<<< HEAD
=======
<<<<<<< HEAD
>>>>>>> 1f6a959e4363710bf4e322eb8115ae1c9b0355bf
>>>>>>> d32fde80b96b758b74be0618f2443b8cac110716
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
>>>>>>> d32fde80b96b758b74be0618f2443b8cac110716
#endif // POPULATION_H
