#include "operatormatrix.h"
#include "adjacencymatrix.h"
#include <ctime>
#include <cstdlib>

OperatorMatrix::OperatorsMatrix()
{
    AdjacencyMatrix::AdjacencyMatrix();
    initializeField();
}

void OperatorMatrix::initializeField()
{
    srand(time(NULL));

    unsigned int cellsInitialized = 0;
    unsigned int i = 0; j = 0;
    unsigned int fieldSquare = OPERAND_FIELD_CAPACITY * OPERAND_FIELD_CAPACITY / 2;

    while (cellsInitialized < fieldSquare)
    {
        if ((rand() % 2 != 0) & (CONJ != this->field[i][j]))
        {
            this->field[i][j] = CONJ;
            cellsInitialized++;
        }
        else
            this->field[i][j] = DISJ;

        i++;
        j += i / OPERAND_FIELD_CAPACITY;
        j %= OPERAND_FIELD_CAPACITY;
        i %= OPERAND_FIELD_CAPACITY;
    }
}
