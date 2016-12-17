#ifndef CHROMOSOME_H
#define CHROMOSOME_H

#include "cexpression.h"
#include "operandsmatrix.h"
#include "operatormatrix.h"
#include <ctime>


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

    //The result of the expression  calculation.
    TFitnessFunction fitnessFunction;

    //Two-dimensional matrix, consisting of randomly spreaded operands of source expression.
    OperandsMatrix *operandsMatrix;

    //Two-dimensional matrix of randomly spreaded conjunctions and disjunctives.
    //The first value is operation priority, the second - operation type.
    OperatorMatrix *operatorMatrix;

    float survivalChace;

    bool crossBreeded = false;
    
    void initializeChromosome();
    
    //Allocates memmory and returns pointer on fitness function array.
    TFitnessFunction createFitnessFunction();
    
    //Divide chromosome on parts due to priority of operations.
    //The dividing point is the lowest priority operation in subexpression, limited by leftIndex and RightPosition values.
    TFitnessFunction calculateFitnessFunction (unsigned int leftIndex, unsigned int rightIndex, TOperation operation);

    //Returns the simplest result of one operand function
    TFitnessFunction getElementaryFitnessFunction(TOperand xCoord, TOperand yCoord, TOperation operation);

    unsigned int getLowPriorityPosition (unsigned int leftIndex, unsigned int rightIndex);

    void initializeSimpleFunction (TFitnessFunction *fitnessFunction, TOperand operand);

    void initializeEmptyFunction (TFitnessFunction *fitnessFunction, TOperation operation);

    float calculateSurvivalChance ();

    TChromosome crossBreede (Chromosome *chromosome);

    void initializeBufferChromosome (TChromosome buffer, unsigned int breakPoint);

    TGene getInitializeValue (unsigned int position);

    TGene crossGenes (TGene gene1, TGene gene2, unsigned int breakPoint);

    unsigned int getBreakedBlockNum (unsigned int position);

    void born (TChromosome parent, TChromosome child, unsigned int breakPoint);

public:
    CExpression *sourceExpression;

    //Calculate expression result.
    TFitnessFunction calculateFitnessFunction ();
    
    //Conjuct two fitness functions.
    TFitnessFunction conjuction (TFitnessFunction fun1, TFitnessFunction fun2);
    
    //Disjunct two fitness functions.
    TFitnessFunction disjunctive (TFitnessFunction fun1, TFitnessFunction fun2);

    unsigned int getChromosomeLength ();

    float getSurvivalChance ();

    void setCrossBreedingStatus (bool status);

    bool getCrossBreedingStatus ();


    TChromosome getChromosomeValue ();
    
    Chromosome ();

    Chromosome (CExpression *expression);

    Chromosome (TChromosome chromosome);

    ~Chromosome ();
};






#endif // CHROMOSOME_H
