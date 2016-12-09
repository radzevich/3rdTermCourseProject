#ifndef CHROMOSOME_H
#define CHROMOSOME_H

#include "cexpression.h"

#define BITS_IN_BYTE 8
#define CHANCE 4

typedef unsigned char TGene;
typedef TGene* TChromosome;

class Chromosome
{
private:
    TChromosome chromosome;
    unsigned int chromosomeSize = 0;
    unsigned int geneCapacity;
    
    void initializeChromosome();
public:
    Chromosome (TExpression &expression);
};






#endif // CHROMOSOME_H
