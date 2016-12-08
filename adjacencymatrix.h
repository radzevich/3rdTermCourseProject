#ifndef ADJACENCYMATRIX_H
#define ADJACENCYMATRIX_H

#define OPERAND_FIELD_CAPACITY 256

typedef unsigned char TCell;

class AdjacencyMatrix
{
private:
    TCell **field;
    unsigned int chance;
    unsigned int expressionArity;

    void setChance( unsigned int chance );
    void getRandomPosition ( unsigned int &i, unsigned int &j );
    unsigned int getChance();
    unsigned int getExpressionArity();

public:
    AdjacencyMatrix();
    void setExpressionArity( unsigned int expressionArity );
};

#endif // ADJACENCYMATRIX_H
