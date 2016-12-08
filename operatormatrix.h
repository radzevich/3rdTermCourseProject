#ifndef OPERATORMATRIX_H
#define OPERATORMATRIX_H

#include "adjacencymatrix.h"

#define CONJ 0xFF00
#define DISJ 0x00FF

class OperatorMatrix : AdjacencyMatrix
{
private:
    void initializeField();
public:
    OperatorMatrix();
};

#endif // OPERATORMATRIX_H
