#include "lifecycle.h"

TExpression LifeCycle (CExpression *expression)
{
    OperandsMatrix *_operandsMatrix = new OperandsMatrix (expression);

    OperatorMatrix *_operatorMatrix = new OperatorMatrix ();

    PopulationList *population = createInitializedPopulationList (POPULATION, expression, _operandsMatrix, _operatorMatrix);

    population->initializePopulationList ();

    for (unsigned int i = 0; i < GENERATIONS_NUM; i++)
    {
        PopulationList *result = population->lookForResults ();

        if (result != NULL)
            return result->getChromosome ()->translateChromosomeIntoExpression (0, result->getChromosome ()->getChromosomeLength ());

        population->reproducePopulation();

        population->CrossBreedOperator();

        population->reducePopulation();
    }

    return *(expression->getExpression ());
}










