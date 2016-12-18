#include "lifecycle.h"


LifeCycle :: LifeCycle (CExpression *expression)
{
    OperandsMatrix *_operandsMatrix = new OperandsMatrix (expression);

    OperatorMatrix *_operatorMatrix = new OperatorMatrix ();

    PopulationList *_populationList = new PopulationList ();
}

void initialization()
{

}


void LifeCycle :: cycle ()
{
    PopulationList *population = createInitializedPopulationList (POPULATION);

    population->initializePopulationList ();

    population->reproducePopulation();

    population->CrossBreedOperator();

    population->reducePopulation();

    PopulationList *result = population->lookForResults ();

    if (result != NULL)
        TExpression *expression = result->getChromosome ()->transformChromosomeToExpression ();

}









