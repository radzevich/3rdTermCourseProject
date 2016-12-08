#ifndef CHROMOSOME_H
#define CHROMOSOME_H

#include "cexpression.h"

#define CONJ 0xFF00
#define DISJ 0x00FF


typedef unsigned char TChromosome;

class Chromosome
{
private:
    TChromosome *chromosome;
public:
    Chromosome (TExpression &expression);
};






#endif // CHROMOSOME_H
