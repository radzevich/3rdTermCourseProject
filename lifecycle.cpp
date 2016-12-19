#include "lifecycle.h"

#include <iostream>

using namespace std;

TExpression lifeCycle (CExpression *expression)
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

int main ()
{
    TExpression expression = "a*b*c+b*c+c*a*a";

    CExpression *cexpression = new CExpression (expression);

    cout << lifeCycle (cexpression) << endl;

    return 0;
}









