#include "operandsmatrix.h"

#include <cstdlib>
#include <ctime>


OperandsMatrix::OperandsMatrix (unsigned int expressionArity, char &operands)
{
    //Construction and initialization
    AdjacencyMatrix::AdjacencyMatrix();
    this->expressionArity = expressionArity;
    this->operands = &operands;
    this->setChance (calculateChance());
    initializeField();
}

//Returns the part or operand's repeats among others in the operand's field.
unsigned int OperandsMatrix::calculateChance()
{
    return ((OPERAND_FIELD_CAPACITY * OPERAND_FIELD_CAPACITY) % (expressionArity * 2 + 1));
}

//Initializes all cells of operand's field with random values.
void OperandsMatrix::initializeField()
{
    srand(time(NULL));

    unsigned int i = 0, j = 0;
    bool inversionFlag = true;

    //Filling cells with random values
    for (unsigned int k = 0; k < expressionArity; k++)
        for (unsigned int n = 0; n < this->chance; n++)
        {
            //Getting random free position's coordinates.
            getRandomPosition (i, j);
            this->field[i][j] = intToLetter(k);

            //Inversing of the hulf part of values
            if (inversionFlag)
            this->field[i][j] |= 128;

            inversionFlag = !inversionFlag;
        }
}

