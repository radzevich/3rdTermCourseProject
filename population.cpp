#include "population.h"

PopulationList :: PopulationList(CExpression *expression)
{
    this->sourceExpression = expression;

}


void PopulationList :: createPopulationList ()
{

    populationList = (TPopulationList*) malloc (sizeof (this->sourceExpression->getFitnessFunctionLength ()));
}

