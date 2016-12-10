#ifndef CHROMOSOME_H
#define CHROMOSOME_H

#include "cexpression.h"

#define BITS_IN_BYTE 8
#define CHANCE 4

#define X_OPERAND_COORD 0
#define Y_OPERAND_COORD 1
#define OPERATION 2
#define OPERATION_PRIORITY 3
#define BLOCK_SHIFT 4

typedef unsigned char TGene;
typedef TGene* TChromosome;

class Chromosome
{
private:
    TChromosome chromosome;
    //Maximum length of chromosome (equal with source expression length).
    unsigned int chromosomeSize = 0;
    //The amount of values chromosome can consist.
    unsigned int geneCapacity;
    //The result of source expression calculation.
    static TFitnessFunction sourceExpressionResult;
    //The result of the expression  calculation.
    TFitnessFunction fitnessFunction;
    
    void initializeChromosome();
    //Allocates memmory and returns pointer on fitness function array.
    TFitnessFunction createFitnessFunction();

    TFitnessFunction calculateFitnessFunction (unsigned int leftIndex = 0, unsigned int rightIndex = (this->chromosomeSize - 1));
public:

    TFitnessFunction calculateFitnessFunction (CExpression &expression);

    TFitnessFunction calculateFitnessFunction ();

    void setFitnessFunction ();

    TFitnessFunction getFitnessFunction ();

    TFitnessFunction conjuction (TFitnessFunction fun1, TFitnessFunction fun2);

    TFitnessFunction disjunctive (TFitnessFunction fun1, TFitnessFunction fun2);

    Chromosome (CExpression &expression);

};






#endif // CHROMOSOME_H
