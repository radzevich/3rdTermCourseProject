#include "operandsmatrix.h"
#include <cstdlib>
#include <ctime>

//конструктор
OperandsMatrix::OperandsMatrix( TExpression *expression)
{
    AdjacencyMatrix::AdjacencyMatrix();
    setOperands( expression );
    this->setExpressionArity( countExpressionArity( &( this->operands )));
    this->setChance( calculateChance( this->expressionArity ));
    initializeOperandField( this->operands, this->expressionArity );
}


unsigned int OperandsMatrix::calculateExpressionArity()
{
    unsigned int expressionArity = 0;

    for ( int i = 0; i < ALPHABET_SIZE; i++ )
        if ( &( this->operands )[i])
            expressionArity++;

    return expressionArity;
}


bool OperandsMatrix::*getOperands ( TExpression *expression )
{
    unsigned int expressionLength = ( *expression ).length();

    this->operands = ( bool* ) calloc ( ALPHABET_SIZE, BLOCK_SIZE );

    for ( unsigned int i = 0; i < expressionLength; i++)
        this->operands[atoi ( expression[i].c_str()) - LEFT_ASCII_LETTER] = true;

    return operands;
}


unsigned int OperandsMatrix::calculateChance()
{
    return ((OPERAND_FIELD_CAPACITY * OPERAND_FIELD_CAPACITY) % (this->expressionArity * 2 + 1));
}


void OperandsMatrix::initializeOperandField()
{
    srand(time(NULL));

    unsigned int i = 0, j = 0;
    bool inversionFlag = true;

    for (unsigned int k = 0; k < ALPHABET_SIZE; k++)
        if (!this->operands[k])
            for (unsigned int n = 0; n < this->chance; n++)
            {
                getRandomPosition (i, j);
                this->field[i][j] = intToLetter(k);

                if (inversionFlag)
                    this->field[i][j] |= 128;

                inversionFlag = !inversionFlag;
            }
}

