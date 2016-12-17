#include "population.h"


PopulationList* createPoulationList (unsigned int population)
{
    PopulationList *populationList = new PopulationList ();

    PopulationList *pnt = populationList;

    for (unsigned int i = 0; i < population; i++)
    {
        pnt->setNext (new PopulationList ());
        pnt = pnt->getNext ();
    }

    return populationList;
}


PopulationList* createInitializedPopulationList (unsigned int population)
{
    PopulationList *sourcePopulation = createPoulationList (population);

    sourcePopulation->initializePopulationList ();

    return sourcePopulation;
}


PopulationList :: PopulationList ()
{
    this->data = NULL;

    this->next = NULL;
}


PopulationList :: ~PopulationList ()
{
    if (this->next != NULL)
        this->next->~PopulationList ();

    free (this);
}


PopulationList* PopulationList :: getNext ()
{
    return this->next;
}


void PopulationList :: setNext (PopulationList *next)
{
    this->next = next;
}


unsigned int PopulationList :: getPopulationListLength ()
{
    PopulationList *pnt = this;

    unsigned int populationListLength = 0;

    while (pnt->next != NULL)
    {
        populationListLength++;
        pnt = pnt->next;
    }

    return populationListLength;
}


void PopulationList :: initializePopulationList ()
{
    PopulationList *pnt = this;

    while (pnt->next != NULL)
    {
        pnt->next->data = new Chromosome ();
        pnt = pnt->next;
    }
}


void PopulationList :: addIndividual (PopulationList *individual)
{
    PopulationList *pnt = this;

    while (NULL != pnt->next)
        pnt = pnt->next;

    pnt->next = individual;
}


void PopulationList :: addIndividual (TChromosome chromosome)
{
    PopulationList *tmp = new PopulationList ();

    tmp->data = new Chromosome (chromosome);

    this->addIndividual(tmp);
}


void PopulationList :: removeIndividual (PopulationList *individual)
{
    PopulationList *pnt = this;

    while (pnt->next != individual)
        pnt = pnt->next;

   PopulationList *tmp = pnt->next;

   pnt->next = pnt->next->next;

   tmp->data->~Chromosome();

   free(tmp);
}


PopulationList* PopulationList :: selectParents ()
{
    PopulationList* parentsList = createPoulationList (PARENTS_NUM);

    PopulationList* pnt = this;

    while (pnt->next != NULL)
    {
        PopulationList *passPosition = parentsList->compareSurvivalChance (pnt->next->data->getSurvivalChance ());

        if (passPosition != NULL)
            parentsList->data = pnt->data;
    }

    return parentsList;
}


PopulationList* PopulationList :: compareSurvivalChance (float survivalChance)
{
    PopulationList *populationList = this;

    while (populationList->next != NULL)
    {
        if ((NULL == populationList->next->data) || (populationList->next->data->getSurvivalChance () < survivalChance))
            return populationList->next;

        populationList = populationList->next;
    }

    return NULL;
}


/*
void PopulationList :: crossingOperator (PopulationList* parentsList)
{
    PopulationList *pnt;

    while (parentsList->next->next != NULL)
    {
        pnt = parentsList->next;

        while (pnt->next != NULL)
        {

        }
    }
}


TChromosome crossChromosome (Chromosome father, Chromosome mather)
{
    Chromosome chromosome = new Chromosome ();


}
*/



void PopulationList :: reproducePopulation ()
{
    float chance = getTotalChanceValue ();

    PopulationList *pnt = this;

    while (pnt->next != NULL)
    {
        pnt->next->data = selectReproducingItem (chance);
        pnt = pnt->next;
    }
}


Chromosome* PopulationList :: selectReproducingItem (float totalSurvivalChance)
{
    srand (time (NULL));

    unsigned int resultChance = rand () % ((unsigned int) (round (totalSurvivalChance * 100)));

    float sumChance;

    PopulationList *pnt = this;

    while ((resultChance > sumChance ) & (pnt->next != NULL))
    {
        pnt = pnt->next;
        sumChance += (pnt->data->getSurvivalChance ()) * 100;
    }

    return pnt->data;
}


float PopulationList :: getTotalChanceValue ()
{
    float chance = 0;

    PopulationList *pnt = this;

    while (pnt->next != NULL)
    {
        chance += pnt->next->data->getSurvivalChance ();
        pnt = pnt->next;
    }

    return chance;
}

