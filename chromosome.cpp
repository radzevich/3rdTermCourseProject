#include "chromosome.h"
#include <cstdlib>
#include <ctime>
#include <math.h>


Chromosome :: Chromosome ()
{
    this->chromosomeSize = 2 * Chromosome :: sourceExpression->getExpressionLength();

    this->chromosome = (TChromosome) calloc (this->chromosomeSize, sizeof (TGene));

    this->geneCapacity = sizeof (TGene) * BITS_IN_BYTE;

    this->survivalChace = this->calculateSurvivalChance ();

    initializeChromosome();
    //Calculating memmory for fitness function.
    this->fitnessFunction = this->calculateFitnessFunction (0, Chromosome :: sourceExpression->getFitnessFunctionLength() - 1, conjuct);
}


Chromosome :: Chromosome (TChromosome chromosome)
{
    this->chromosomeSize = 2 * Chromosome :: sourceExpression->getExpressionLength();

    this->chromosome = chromosome;

    this->geneCapacity = sizeof (TGene) * BITS_IN_BYTE;

    this->survivalChace = this->calculateSurvivalChance ();

    //Calculating memmory for fitness function.
    this->fitnessFunction = this->calculateFitnessFunction (0, Chromosome :: sourceExpression->getFitnessFunctionLength() - 1, conjuct);
}


Chromosome :: ~Chromosome ()
{
    this->sourceExpression = NULL;

    this->operandsMatrix = NULL;

    this->operatorMatrix = NULL;

    free (this->chromosome);

    free(this->fitnessFunction);
}


void Chromosome :: initializeChromosome()
{
    srand (time (NULL));

    for (unsigned int i = 0; i < this->chromosomeSize; i++)
        if (0 == rand() % CHANCE)
            this->chromosome[i] = rand() % this->geneCapacity;
}


TFitnessFunction Chromosome :: calculateFitnessFunction (unsigned int leftIndex, unsigned int rightIndex, TOperation operation)
{
    TFitnessFunction fitnessFunction = createFitnessFunction();

    if (1 != rightIndex - leftIndex)
    {
        unsigned int lowPriorityPosition = getLowPriorityPosition (leftIndex, rightIndex);

        if ((TGene) CONJ == chromosome[lowPriorityPosition])
            fitnessFunction = conjuction (calculateFitnessFunction (leftIndex, lowPriorityPosition - 1, conjuct),
                                          calculateFitnessFunction (lowPriorityPosition + 2, rightIndex, conjuct));
        else
            fitnessFunction = disjunctive (calculateFitnessFunction (leftIndex, lowPriorityPosition - 1, disjunct),
                                           calculateFitnessFunction (lowPriorityPosition + 2, rightIndex, disjunct));
    }
    else
        fitnessFunction = getElementaryFitnessFunction (leftIndex, rightIndex, operation);

    return fitnessFunction;
}


float Chromosome :: calculateSurvivalChance ()
{
    unsigned int fitnessFunctionLength = this->sourceExpression->getFitnessFunctionLength ();

    float similarity = 0;

    for (unsigned int i = 0; i < fitnessFunctionLength; i++)
        if (this->fitnessFunction[i] == this->sourceExpressionResult[i])
            similarity++;

    return (100.0 / survivalChace);
}


unsigned int Chromosome :: getLowPriorityPosition (unsigned int leftIndex, unsigned int rightIndex)
{
    TCell lowPriority = (unsigned int) round (exp(this->geneCapacity * log (2))) - 1;
    unsigned int lowPriorityPostion = leftIndex + OPERATION_PRIORITY;

    for (unsigned int i = lowPriorityPostion; i < rightIndex; i += BLOCK_SHIFT)
    {
        if (lowPriority >= this->chromosome[i])
        {
            lowPriority = this->chromosome[i];
            lowPriorityPostion = i;
        }
    }

    return lowPriorityPostion;
}


TFitnessFunction Chromosome :: createFitnessFunction()
{
    //Fitness function creating throw allocating space for it. Returns pointer to this space.
    return (TFitnessFunction) calloc (Chromosome :: sourceExpression->getFitnessFunctionLength(), sizeof(bool));
}


TFitnessFunction Chromosome :: conjuction (TFitnessFunction fun1, TFitnessFunction fun2)
{
    unsigned int fitnessFunctionLength = Chromosome :: sourceExpression->getFitnessFunctionLength ();
    //Two strings conjuction.
    for (unsigned int i = 0; i < fitnessFunctionLength; i++)
        fun1[i] &= fun2[i];
    //Freeing memmory.
    free(fun2);

    return fun1;
}


TFitnessFunction Chromosome :: disjunctive (TFitnessFunction fun1, TFitnessFunction fun2)
{
    unsigned int fitnessFunctionLength = Chromosome :: sourceExpression->getFitnessFunctionLength();
    //Two strings disjunctive.
    for (unsigned int i = 0; i < fitnessFunctionLength; i++)
        fun1[i] |= fun2[i];
    //Freeing memmory.
    free(fun2);

    return fun1;
}

//Check if operand inversed. Returns true if it is.
bool operanedInverted (TOperand operand)
{
    return (operand && 127 != 0);
}


//Returns simple one-operand function result array.
TFitnessFunction Chromosome :: getElementaryFitnessFunction(TOperand xCoord, TOperand yCoord, TOperation operation)
{
    //Fitness function creating.
    TFitnessFunction fitnessFunction = createFitnessFunction();

    //Getting operand value throw it's coordinates.
    TOperand operand = this->operandsMatrix->getOperandThrowPosition(xCoord, yCoord);

    //Check if operand is not empty
    if (0 != operand)
        initializeSimpleFunction (&fitnessFunction, operand);
    else
        initializeEmptyFunction (&fitnessFunction, operation);

    return fitnessFunction;
}


void Chromosome :: initializeSimpleFunction (TFitnessFunction *fitnessFunction, TOperand operand)
{
    //Getting operand index among other ones in source expression.
    unsigned int operandNumber = this->operandsMatrix->getOperandNumber(operand);

    //Calculating number of same values repeats in result array.
    unsigned int repeatsCount = (unsigned int)round (exp (operandNumber * log (2)));

    //Calculating position for fitness function initialize starting.
    unsigned int startPosition;

    unsigned int fitnessFunctionLength = Chromosome :: sourceExpression->getFitnessFunctionLength ();

    //If operand haven't been inverted, it will be initialized from the (2 ^ operandNumber) position with "true" value.
    //In other way array will be inverted by initializing with "false" value instead of "true".
    if (operanedInverted (operand))
        startPosition = 0;
    else
        startPosition = repeatsCount;

    //Inialization cycle.
    for (unsigned int i = startPosition; i < fitnessFunctionLength; )
    {
        for (unsigned int j = i; j < repeatsCount; j++)
            (*fitnessFunction)[j] = true;
        i += repeatsCount * 2;
    }
}


void Chromosome :: initializeEmptyFunction (TFitnessFunction *fitnessFunction, TOperation operation)
{
    unsigned int fitnessFunctionLength = Chromosome :: sourceExpression->getFitnessFunctionLength ();

    for (unsigned int i = 0; i < fitnessFunctionLength; i++)
        (*fitnessFunction)[i] = operation;
}


float Chromosome :: getSurvivalChance ()
{
    return this->survivalChace;
}


void Chromosome :: setCrossBreedingStatus (bool status)
{
    this->crossBreeded = status;
}


bool Chromosome :: getCrossBreedingStatus ()
{
    return this->crossBreeded;
}


TChromosome Chromosome :: getChromosomeValue ()
{
    return this->chromosome;
}


void Chromosome :: crossBreede (Chromosome *chromosome)
{
    TChromosome chromosomeValue = chromosome->getChromosomeValue ();

    srand (time (NULL));

    unsigned int chromosomeSize = (this->chromosomeSize * BITS_IN_BYTE);

    unsigned int breakPoint = rand () % (chromosomeSize - 1) + 1;

    TChromosome sun = (this->chromosome = (TChromosome) calloc (this->chromosomeSize, sizeof (TGene)));

    TChromosome daughter = (this->chromosome = (TChromosome) calloc (this->chromosomeSize, sizeof (TGene)));


}


unsigned int Chromosome :: getBreakedBlockNum (unsigned int breakPoint)
{
    unsigned int position = 0;
    unsigned int blockNum = 0;

    for ( ; position < breakPoint; position += BITS_IN_BYTE)
        blockNum++;

    return blockNum - 1;
}


TGene Chromosome :: getInitializeValue (unsigned int position)
{
    if (1 == position)
        return 1;
    else
        return 2 * getInitializeValue (position - 1);
}


void Chromosome :: born (TChromosome father, TChromosome sun, TChromosome daughter, unsigned int breakPoint)
{
    unsigned int breakedBlock = getBreakedBlockNum (breakPoint);

    for (unsigned int i = 0; i < breakedBlock; i++)
    {
        sun [i] = father [i];
        daughter [i] = this->chromosome [i];
    }

    for (unsigned int i = 0; i < breakedBlock; i++)
    {
        sun [i] = this->chromosome [i];
        daughter [i] = father [i];
    }

    TGene initalizationValue = getInitializeValue(breakPoint - (breakedBlock * BITS_IN_BYTE));
    TGene invertedInitializationValue = !initalizationValue;

    TGene fatherHeadValue = father [breakedBlock] & invertedInitializationValue;
    TGene fatherTailValue = father [breakedBlock] & initalizationValue;

    TGene motherHeadValue = this->chromosome [breakedBlock] & invertedInitializationValue;
    TGene motherTailValue = this->chromosome [breakedBlock] & initalizationValue;

    sun [breakedBlock] = fatherHeadValue + motherTailValue;
    daughter [breakedBlock] = motherHeadValue + fatherTailValue;
}












