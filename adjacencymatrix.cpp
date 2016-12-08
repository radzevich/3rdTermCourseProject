#include "adjacencymatrix.h"
#include "cexpression.h"

AdjacencyMatrix::AdjacencyMatrix()
{
    //выделение памяти под поле операндов
    field = ( TCell** )calloc( OPERAND_FIELD_CAPACITY, sizeof( TCell* ));

    //выделение памяти под столбцы
    for ( unsigned int i = 0; i < OPERAND_FIELD_CAPACITY; i++ )
        field[i] = ( TCell* )calloc( OPERAND_FIELD_CAPACITY, sizeof( TCell ));
}


void AdjacencyMatrix::setChance( unsigned int chance )
{
    this->chance = chance;
}


void AdjacencyMatrix::setExpressionArity( unsigned int expressionArity )
{
    this->expressionArity = expressionArity;
}


unsigned int AdjacencyMatrix::getChance()
{
    return this->chance;
}


unsigned int AdjacencyMatrix::getExpressionArity()
{
    return this->expressionArity;
}


void getRandomPosition ( unsigned int &i, unsigned int &j )
{
    while (0 == letterToInt (this->field[i][j]))
    {
        i = rand () % OPERAND_FIELD_CAPACITY;
        j = rand () % OPERAND_FIELD_CAPACITY;
    }
}
