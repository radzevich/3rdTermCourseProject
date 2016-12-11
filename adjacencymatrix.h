#ifndef ADJACENCYMATRIX_H
#define ADJACENCYMATRIX_H

<<<<<<< HEAD
#include "cexpression.h"

=======
<<<<<<< HEAD
#include "cexpression.h"

=======
<<<<<<< HEAD
#include "cexpression.h"

=======
>>>>>>> 60419dbe49e5674adf5b4a11c7815d27be15c0ce
>>>>>>> 1f6a959e4363710bf4e322eb8115ae1c9b0355bf
>>>>>>> d32fde80b96b758b74be0618f2443b8cac110716
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
<<<<<<< HEAD
    AdjacencyMatrix ();
=======
<<<<<<< HEAD
    AdjacencyMatrix ();
=======
<<<<<<< HEAD
    AdjacencyMatrix ();
=======
    AdjacencyMatrix();
>>>>>>> 60419dbe49e5674adf5b4a11c7815d27be15c0ce
>>>>>>> 1f6a959e4363710bf4e322eb8115ae1c9b0355bf
>>>>>>> d32fde80b96b758b74be0618f2443b8cac110716
};

#endif // ADJACENCYMATRIX_H
