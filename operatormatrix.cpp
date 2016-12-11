#include "operatormatrix.h"
<<<<<<< HEAD
=======
<<<<<<< HEAD
=======
#include "adjacencymatrix.h"
>>>>>>> 60419dbe49e5674adf5b4a11c7815d27be15c0ce
>>>>>>> 1f6a959e4363710bf4e322eb8115ae1c9b0355bf
#include <ctime>
#include <cstdlib>

OperatorMatrix::OperatorMatrix()
{
    AdjacencyMatrix();
    initializeField();
}

void OperatorMatrix::initializeField()
{
    srand(time(NULL));

    unsigned int cellsInitialized = 0;
    unsigned int i = 0, j = 0;
    unsigned int fieldSquare = OPERAND_FIELD_CAPACITY * OPERAND_FIELD_CAPACITY / 2;

    while (cellsInitialized < fieldSquare)
    {
        if ((rand() % 2 != 0) & ((TCell) CONJ != field[i][j]))
        {
            this->field[i][j] = (TCell) CONJ;
            cellsInitialized++;
        }
        else
            this->field[i][j] = (TCell) DISJ;

        i++;
        j += i / OPERAND_FIELD_CAPACITY;
        j %= OPERAND_FIELD_CAPACITY;
        i %= OPERAND_FIELD_CAPACITY;
    }
}

