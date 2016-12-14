#include "population.h"

PopulationList :: PopulationList ()
{
    this->data = NULL;

    this->next = NULL;
}


PopulationList* PopulationList :: createPoulationList (unsigned int population)
{
    PopulationList *populationList = new PopulationList ();

    PopulationList *pnt = populationList;

    for (unsigned int i = 0; i < population; i++)
    {
        pnt->next = new PopulationList ();
        pnt = pnt->next;
    }

    return populationList;
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
        PopulationList *passPosition = parentsList->compareSurvicalChance (pnt->next->data->getSurvivalChance ());

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



