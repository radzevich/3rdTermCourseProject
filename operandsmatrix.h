#ifndef OPERANDSMATRIX_H
#define OPERANDSMATRIX_H

#include "adjacencymatrix.h"
#include "cexpression.h"

#define ALPHABET_SIZE 26


class OperandsMatrix : AdjacencyMatrix
{
private:
    bool *operands;

    bool OperandsMatrix::*getOperands ( TExpression *expression );
    unsigned int calculateExpressionArity();
    unsigned int calculateChance();
    void initializeOperandField();

public:
    OperandsMatrix(TExpression *expression);
};

#endif // OPERANDSMATRIX_H
