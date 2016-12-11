#ifndef POPULATION_H
#define POPULATION_H

#include "chromosome.h"
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



#endif // POPULATION_H
