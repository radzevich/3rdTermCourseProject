#ifndef OPERANDSMATRIX_H
#define OPERANDSMATRIX_H

#include "adjacencymatrix.h"
#include "cexpression.h"

#define ALPHABET_SIZE 26

typedef unsigned char TOperand;

//Two-dimensional matrix, consisting of randomly spreaded operands of source expression.
class OperandsMatrix : AdjacencyMatrix
{
private:
    //Array of all uniq different operands.
    TOperand *operands;

    //Returns the part or operand's repeats among others in the operand's field.
    unsigned int calculateChance();

    //Initializes all cells of operand's field with random values.
    void initializeField();

public:
    OperandsMatrix(TOperand &operands);

    TOperand getOperandThrowPosition (TCell xCoord, TCell yCoord);

    unsigned int getOperandNumber (TOperand operand);
};

#endif // OPERANDSMATRIX_H
