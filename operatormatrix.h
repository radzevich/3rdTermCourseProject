#ifndef OPERATORMATRIX_H
#define OPERATORMATRIX_H

#include "adjacencymatrix.h"

class OperatorMatrix : AdjacencyMatrix
{
private:
    void initializeField();
public:
    OperatorMatrix();
};

extern OperatorMatrix *_operatorMatrix;

#endif // OPERATORMATRIX_H
