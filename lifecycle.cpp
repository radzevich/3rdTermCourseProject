#include "lifecycle.h"


LifeCycle :: LifeCycle (CExpression *expression)
{
    this->_operandsMatrix = new OperandsMatrix (expression);

    this->_operatorMatrix = new OperatorMatrix ();

    Chromosome :: sourceExpression = expression;

    this->_populationList = new PopulationList ();
}

void initialization()
{

}


void LifeCycle :: cycle ()
{
    PopulationList *sourcePosulationList = createSourcePopulation (POPULATION);

    sourcePopulation->initializePopulationList ();

    PopulationList *reproducedPopulationList = reproducePopulation (sourcePosulationList);

    sourcePosulationList->~PopulationList ();



}


PopulationList* LifeCycle :: createSourcePopulationList (unsigned int population)
{
    PopulationList *sourcePopulation = new PopulationList ();

    sourcePopulation->createPoulationList (population);

    return sourcePopulation;
}


PopulationList* LifeCycle :: reproducePopulation (PopulationList *populationList)
{
    float chance = getTotalChanceValue (populationList);

    PopulationList *intermediatePopulation = createSourcePopulation (POPULATION);

    PopulationList *pnt = populationList;

    while (pnt->next != NULL)
    {
        pnt->next->data = selectReproducingItem (populationList, chance);
        pnt = pnt->next;
    }

    return populationList;
}


Chromosome* LifeCycle :: selectReproducingItem (PopulationList *populationList, float totalSurvivalChance)
{
    srand (time (NULL));

    unsigned int chance = round (totalSurvivalChance * 100);

    unsigned int resultChance;

    float sumChance;

    PopulationList *pnt = populationList;

    while ((resultChance > sumChance ) & (populationList->next != NULL))
    {
        pnt = pnt->next;
        sumChance += (pnt->data->getSurvivalChance ()) * 100;
    }

    return pnt->data;
}


float LifeCycle :: getTotalChanceValue (PopulationList *populationList)
{
    float chance = 0;

    while (populationList->next != NULL)
    {
        chance += populationList->next->data->getSurvivalChance ();
        populationList = populationList->next;
    }

    return chance;
}









