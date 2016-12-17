#include "lifecycle.h"


LifeCycle :: LifeCycle (CExpression *expression)
{
    this->_operandsMatrix = new OperandsMatrix (expression);

    this->_operatorMatrix = new OperatorMatrix ();

    this->_populationList = new PopulationList ();
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









