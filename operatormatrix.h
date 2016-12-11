#ifndef OPERATORMATRIX_H
#define OPERATORMATRIX_H

#include "adjacencymatrix.h"

#define CONJ 0xFF00
#define DISJ 0x00FF
#define BOOL_CONJ true
#define BOOL_DISJ false

typedef enum {conjuct = BOOL_CONJ, disjunct = BOOL_DISJ} TOperation;

class OperatorMatrix : AdjacencyMatrix
{
private:
    void initializeField();
public:
    OperatorMatrix();
};

#endif // OPERATORMATRIX_H
