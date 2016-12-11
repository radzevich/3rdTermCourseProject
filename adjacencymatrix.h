#ifndef ADJACENCYMATRIX_H
#define ADJACENCYMATRIX_H

#include "cexpression.h"

#define OPERAND_FIELD_CAPACITY 256

typedef unsigned char TCell;

unsigned int letterToInt (char letter);

class AdjacencyMatrix
{
protected:
    //Two-dimensional matrix, consisting of randomly spreaded operands of source expression.
    TCell **field;
    //The part of operand's repeats among others in the operand's field.
    unsigned int chance;

    void setChance (unsigned int chance);
    void getRandomPosition (unsigned int &i, unsigned int &j);
private:
    unsigned int getChance();

public:
    AdjacencyMatrix ();
};

#endif // ADJACENCYMATRIX_H
