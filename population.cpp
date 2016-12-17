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

    tmp->data->setCrossBreedingStatus (true);

    tmp->data->mutationOperator ();

    this->addIndividual(tmp);
}


void PopulationList :: removeIndividual ()
{
   PopulationList *pnt = this;

   this->next = this->next->next;

   pnt->data->~Chromosome();

   free(pnt);
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

Chromosome *PopulationList :: getChromosome ()
{
    return this->data;
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


//*******************************************************Crossing_over*******************************************************

void PopulationList :: CrossBreedOperator ()
{
    srand (time (NULL));
    unsigned int index = rand () % POPULATION;

    for (unsigned int i = 0; i < (POPULATION >> 1); i++)
    {
        PopulationList *mother = this->getItemThrowIndex (index);
        mother->data->setCrossBreedingStatus (true);

        PopulationList *father = this->getItemThrowIndex (index);
        father->data->setCrossBreedingStatus (true);

        this->addIndividual (Chromosome :: crossBreede (father->data, mother->data));
    }
}


PopulationList *PopulationList :: getItemThrowIndex (unsigned int index)
{
    unsigned int i = 0;

    PopulationList *pnt = this;

    while (true)
    {
        if (pnt->next != NULL)
            if ((i >= index) & (!pnt->next->data->getCrossBreedingStatus ()))
                return pnt->next;
            else
            {
                i++;
                pnt = pnt->next;
            }
         else
            pnt = this;
    }
}

//******************************************************************************************************************************

void PopulationList :: reducePopulation ()
{
    PopulationList *pnt = this;

    PopulationList *endangered;

    float lowerSurvivalChance;

    for (int i = (POPULATION - this->getPopulationListLength ()); i > 0; i--)
    {
        endangered = this;
        lowerSurvivalChance = pnt->next->data->getSurvivalChance ();

        while (pnt->next != NULL)
        {
            if (pnt->next->data->getSurvivalChance () < lowerSurvivalChance)
            {
                lowerSurvivalChance = pnt->next->data->getSurvivalChance ();
                endangered = pnt;
            }
            pnt = pnt->next;
        }
        endangered->removeIndividual ();
    }
}


/*float PopulationList :: getLowerSurvivalChance ()
{
    PopulationList *pnt;

    float maximumSurvivalChance = 1, iterationMaximumSurvivalChance, survivalChance;

    unsigned int repeatCounter;

    for (unsigned int i = 0; i < POPULATION; i++)
    {
        iterationMaximumSurvivalChance = 0;
        repeatCounter = 0;
        pnt = this;

        while (pnt->next != NULL)
        {
            survivalChance = pnt->data->getSurvivalChance ();

            if (survivalChance = currentSurvivalChance)
                repeatCounter++;
            else if ((survivalChance > iterationMaximumSurvivalChance) & (survivalChance < maximumSurvivalChance))
            {
                repeatCounter = 0;
                iterationMaximumSurvivalChance = survivalChance;
            }

            pnt = pnt->next;
        }

        maximumSurvivalChance = iterationMaximumSurvivalChance;

        i += repeatCounter;
    }

    return maximumSurvivalChance;
}*/


PopulationList *PopulationList :: lookForResults ()
{
    PopulationList *pnt = this;

    while (pnt->next != NULL)
    {
        if (1 - (pnt->next->data->getSurvivalChance ()) < 0.001)
            return pnt->next;

        pnt = pnt->next;
    }

    return NULL;
}

