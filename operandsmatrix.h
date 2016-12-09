#ifndef OPERANDSMATRIX_H
#define OPERANDSMATRIX_H

#include "adjacencymatrix.h"
#include "cexpression.h"

#define ALPHABET_SIZE 26

//Two-dimensional matrix, consisting of randomly spreaded operands of source expression.
class OperandsMatrix : AdjacencyMatrix
{
private:
    //The number of uniq operands in source expression.
    unsigned int expressionArity;
    //Array of all uniq different operands.
    char *operands;

    //Returns the part or operand's repeats among others in the operand's field.
    unsigned int calculateChance();
    //Initializes all cells of operand's field with random values.
    void initializeField();

public:
    OperandsMatrix(unsigned int expressionArity, char &operands);
};

#endif // OPERANDSMATRIX_H
