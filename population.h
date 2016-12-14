#ifndef POPULATION_H
#define POPULATION_H

#include "chromosome.h"
#include "cexpression.h"

#define POPULATION 16
#define PARENTS_NUM 4


class PopulationList
{
private:

    Chromosome *data;

    PopulationList *next;

    static CExpression *sourceExpression;

    void createPopulationList ();

public:
    PopulationList ();

    static CExpression *getSourceExpression ();

    PopulationList* createPoulationList ();

    void addIndividual (PopulationList *individual);
};



#endif // POPULATION_H
