#ifndef CHROMOSOME_H
#define CHROMOSOME_H

#include "cexpression.h"

#define CONJ 0xFF00
#define DISJ 0x00FF
#define LEFT_ASCII_LETTER 'a'
#define ALPHABET_SIZE 26
#define OPERAND_FIELD_CAPACITY 256

typedef unsigned char TCell;

TCell **_operandField;



typedef unsigned char TChromosome;

class Chromosome
{
private:
    TChromosome *chromosome;
public:
    Chromosome (TExpression &expression);
};






#endif // CHROMOSOME_H
