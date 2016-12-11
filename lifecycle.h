#ifndef LIFECYCLE_H
#define LIFECYCLE_H

#include "adjacencymatrix.h"
#include "cexpression.h"
#include "chromosome.h"
#include "operandsmatrix.h"
#include "operatormatrix.h"
#include "population.h"

TExpression *getInputExpression();

class LifeCycle
{
private:
    CExpression _expression;

    OperandsMatrix _operandsMatrix;

    OperatorMatrix _operatorMatrix;

    Population _population;

public:
    LifeCycle (/*CExpression expression*/);
};

#endif // LIFECYCLE_H
