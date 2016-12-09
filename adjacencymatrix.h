#ifndef ADJACENCYMATRIX_H
#define ADJACENCYMATRIX_H

#define OPERAND_FIELD_CAPACITY 256

typedef unsigned char TCell;

class AdjacencyMatrix
{
private:
    TCell **field;
    unsigned int chance;

    void setChance (unsigned int chance);
    void getRandomPosition (unsigned int &i, unsigned int &j);
    unsigned int getChance();

public:
    AdjacencyMatrix();
};

#endif // ADJACENCYMATRIX_H
