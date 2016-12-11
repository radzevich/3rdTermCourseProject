#include "lifecycle.h"

LifeCycle :: LifeCycle (/*CExpression expression*/)
{
    //this->_operandsMatrix = *(new OperandsMatrix (&expression));

    this->_operatorMatrix = *(new OperatorMatrix ());

    this->_population = *(new Population());
}

void initialization()
{

}

