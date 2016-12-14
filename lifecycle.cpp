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

