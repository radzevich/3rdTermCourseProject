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

    void removeIndividual ();

    PopulationList* selectParents ();

    PopulationList* compareSurvivalChance (float survivalChance);

    PopulationList* getRandomIndividual (PopulationList *populationList);

    Chromosome* selectReproducingItem (float totalSurvivalChance);

    float getTotalChanceValue ();

    void  CrossBreed (PopulationList *populationList);

public:
    PopulationList ();

    ~PopulationList ();

    PopulationList* getNext ();

    PopulationList *getItemThrowIndex (unsigned int index);

    PopulationList *lookForResults ();

    Chromosome *getChromosome ();

    void setNext (PopulationList* next);

    static CExpression *getSourceExpression ();

    void addIndividual (PopulationList *individual);

    void addIndividual (TChromosome chromosome);

    void initializePopulationList ();

    void reproducePopulation ();

    void CrossBreedOperator ();

    void reducePopulation ();

    float getLowerSurvivalChance ();
};

PopulationList* createPoulationList (unsigned int population);

PopulationList* createInitializedPopulationList (unsigned int population);



#endif // POPULATION_H
