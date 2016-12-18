#ifndef POPULATION_H
#define POPULATION_H

#include "chromosome.h"
#include "cexpression.h"
#include "operandsmatrix.h"
#include "operatormatrix.h"
#include <math.h>

#define POPULATION 16
#define PARENTS_NUM 4


class PopulationList
{
private:

    Chromosome *data;

    PopulationList *next;

    OperandsMatrix *operandsMatrix;

    OperatorMatrix *operatorMatrix;

    CExpression *expression;

    //CExpression *sourceExpression;

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

    //CExpression *getSourceExpression ();

    void addIndividual (PopulationList *individual);

    void addIndividual (TChromosome chromosome);

    void initializePopulationList ();

    void reproducePopulation ();

    void CrossBreedOperator ();

    void reducePopulation ();

    float getLowerSurvivalChance ();

    CExpression *getExpression ();

    void setExpression (CExpression *expression);

    OperandsMatrix *getOperandsMatrix ();

    void setOperandsMatrix (OperandsMatrix *operandsMatrix);

    OperatorMatrix *getOperatorMatrix ();

    void SetOperatorMatrix (OperatorMatrix *operatorMatrix);
};


PopulationList* createPoulationList (unsigned int population, CExpression *expression, OperandsMatrix *operandsMatrix, OperatorMatrix *operatorMatrix);

PopulationList* createInitializedPopulationList (unsigned int population, CExpression *expression, OperandsMatrix *operandsMatrix, OperatorMatrix *operatorMatrix);

#endif // POPULATION_H
