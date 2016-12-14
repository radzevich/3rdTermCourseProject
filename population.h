#ifndef POPULATION_H
#define POPULATION_H

#include "chromosome.h"
#include "cexpression.h"
#include <math.h>

#define POPULATION 16
#define PARENTS_NUM 4


class PopulationList
{
private:

    Chromosome *data;

    PopulationList *next;

    static CExpression *sourceExpression;

    unsigned int getPopulationListLength ();

    void removeIndividual (PopulationList *individual);

    PopulationList* selectParents ();

    PopulationList* compareSurvivalChance (float survivalChance);

    PopulationList* createSourcePopulationList (unsigned int population);

    PopulationList* reproducePopulation (PopulationList *populationList);

    PopulationList* getRandomIndividual (PopulationList *populationList);

    Chromosome* selectReproducingItem (PopulationList *populationList, float totalSurvivalChance);

    float getTotalChanceValue (PopulationList *populationList);

    void  CrossBreed (PopulationList *populationList);

public:
    PopulationList ();

    ~PopulationList ();

    static CExpression *getSourceExpression ();

    PopulationList* createPoulationList (unsigned int population);

    void addIndividual (PopulationList *individual);

    void addIndividual (TChromosome chromosome);

    void initializePopulationList ();


};



#endif // POPULATION_H
