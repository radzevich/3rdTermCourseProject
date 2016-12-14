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

    unsigned int getPopulationListLength ();

    void initializePopulationList ();

    void removeIndividual (PopulationList *individual);

    PopulationList* selectParents ();

    PopulationList* compareSurvivalChance (float survivalChance);

public:
    PopulationList ();

    ~PopulationList ();

    static CExpression *getSourceExpression ();

    PopulationList* createPoulationList (unsigned int population);

    void addIndividual (PopulationList *individual);

    void addIndividual (TChromosome chromosome);
};



#endif // POPULATION_H
