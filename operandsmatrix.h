#ifndef OPERANDSMATRIX_H
#define OPERANDSMATRIX_H

#include "adjacencymatrix.h"
#include "cexpression.h"

#define ALPHABET_SIZE 26

<<<<<<< HEAD
=======
typedef unsigned char TOperand;

>>>>>>> 60419dbe49e5674adf5b4a11c7815d27be15c0ce
//Two-dimensional matrix, consisting of randomly spreaded operands of source expression.
class OperandsMatrix : AdjacencyMatrix
{
private:
    //Array of all uniq different operands.
    TOperand *operands;

<<<<<<< HEAD
    static CExpression *sourceExpression;

=======
>>>>>>> 60419dbe49e5674adf5b4a11c7815d27be15c0ce
    //Returns the part or operand's repeats among others in the operand's field.
    unsigned int calculateChance();

    //Initializes all cells of operand's field with random values.
    void initializeField();

public:
<<<<<<< HEAD
    OperandsMatrix (CExpression *expression);
=======
    OperandsMatrix(TOperand &operands);
>>>>>>> 60419dbe49e5674adf5b4a11c7815d27be15c0ce

    TOperand getOperandThrowPosition (TCell xCoord, TCell yCoord);

    unsigned int getOperandNumber (TOperand operand);
};

#endif // OPERANDSMATRIX_H
