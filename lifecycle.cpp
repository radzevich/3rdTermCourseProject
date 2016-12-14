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


void LifeCycle :: CrossBreed (PopulationList *populationList)
{
    PopulationList *pnt = populationList;

    PopulationList *father;

    while (pnt->next != NULL)
        if (!pnt->next->data->getCrossBreedingStatus ())
        {
            father = getRandomIndividual (pnt);

            pnt = pnt->next;

            father->data->setCrossBreedingStatus (true);

            pnt->data->crossBreeded = true;
        }
    }

    TChromosome sun =  (TChromosome) calloc (this->chromosomeSize, sizeof (TGene));

    TChromosome daughter = (TChromosome) calloc (this->chromosomeSize, sizeof (TGene));

}


PopulationList* LifeCycle :: getRandomIndividual (PopulationList *populationList)
{
    PopulationList *pnt;

    unsigned int populationListLength = populationList->getPopulationListLength ();
    unsigned int repeats;

    while (true)
    {
        pnt = populationList;
        repeats = rand () % populationListLength;

        for (unsigned int i = 0; i < repeats; i++)
            pnt = pnt->next;

        if (!pnt->next->data->getCrossBreedingStatus ())
            return pnt->next;
    }


}







