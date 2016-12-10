#include "operandsmatrix.h"

#include <cstdlib>
#include <ctime>


OperandsMatrix::OperandsMatrix (char &operands)
{
    //Construction and initialization
    AdjacencyMatrix();
    this->operands = &operands;
    this->setChance (calculateChance());
    initializeField();
}

//Returns the part of operand's repeats among others in the operand's field.
unsigned int OperandsMatrix::calculateChance()
{
    return ((OPERAND_FIELD_CAPACITY * OPERAND_FIELD_CAPACITY) % (expressionArity * 2 + 1));
}

//Initializes all cells of operand's field with random values.
void OperandsMatrix::initializeField()
{
    srand(time(NULL));

    unsigned int i = 0, j = 0;
    unsigned int expressionArity = CExpression.getExpressionArity();
    bool inversionFlag = true;

    //Filling cells with random values
    for (unsigned int k = 0; k < expressionArity; k++)
        for (unsigned int n = 0; n < this->chance; n++)
        {
            //Getting random free position coordinates.
            getRandomPosition (i, j);
            this->field[i][j] = this->operands[k];

            //Inversing of the hulf part of values.
            if (inversionFlag)
            this->field[i][j] |= 128;

            inversionFlag = !inversionFlag;
        }
}

TOperand OperandsMatrix :: getOperandThrowPosition (TCell xCoord, yCoord)
{
    return this->field[i][j];
}


unsigned int OperandsMatrix :: getOperandNumber (TOperand operand)
{
    unsigned int position = 0;
    unsigned int expressionArity = CExpression.getExpressionArity();

    while ((position < expressionArity) & (operand != this->operands[position]))
        position++;

    return position;
}
