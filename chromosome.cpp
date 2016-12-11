#include "chromosome.h"
<<<<<<< HEAD
=======
<<<<<<< HEAD
=======
<<<<<<< HEAD
=======
#include "cexpression.h"
#include "adjacencymatrix.h"
>>>>>>> 60419dbe49e5674adf5b4a11c7815d27be15c0ce
>>>>>>> 1f6a959e4363710bf4e322eb8115ae1c9b0355bf
>>>>>>> d32fde80b96b758b74be0618f2443b8cac110716
#include <cstdlib>
#include <ctime>
#include <math.h>


<<<<<<< HEAD
=======
<<<<<<< HEAD
=======
<<<<<<< HEAD
>>>>>>> 1f6a959e4363710bf4e322eb8115ae1c9b0355bf
>>>>>>> d32fde80b96b758b74be0618f2443b8cac110716
Chromosome :: Chromosome (CExpression *expression)
{
    this->sourceExpression = expression;

    this->chromosomeSize = 2 * expression->getExpressionLength();
<<<<<<< HEAD
=======
<<<<<<< HEAD
=======
=======
Chromosome :: Chromosome (CExpression &expression)
{
    this->chromosomeSize = 2 * expression.getExpressionLength();
>>>>>>> 60419dbe49e5674adf5b4a11c7815d27be15c0ce
>>>>>>> 1f6a959e4363710bf4e322eb8115ae1c9b0355bf
>>>>>>> d32fde80b96b758b74be0618f2443b8cac110716

    this->chromosome = (TChromosome) calloc (this->chromosomeSize, sizeof (TGene));

    this->geneCapacity = sizeof (TGene) * BITS_IN_BYTE;

    initializeChromosome();
    //Getting memmory for fitness function.
    this->fitnessFunction = createFitnessFunction();

    calculateFitnessFunction();
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
<<<<<<< HEAD
    return (TFitnessFunction) calloc (this->sourceExpression->getFitnessFunctionLength(), sizeof(bool));
=======
<<<<<<< HEAD
    return (TFitnessFunction) calloc (this->sourceExpression->getFitnessFunctionLength(), sizeof(bool));
=======
<<<<<<< HEAD
    return (TFitnessFunction) calloc (this->sourceExpression->getFitnessFunctionLength(), sizeof(bool));
=======
    return (TFitnessFunction) calloc (CExpression :: getFitnessFunctionLength(), sizeof(bool));
>>>>>>> 60419dbe49e5674adf5b4a11c7815d27be15c0ce
>>>>>>> 1f6a959e4363710bf4e322eb8115ae1c9b0355bf
>>>>>>> d32fde80b96b758b74be0618f2443b8cac110716
}


TFitnessFunction Chromosome :: conjuction (TFitnessFunction fun1, TFitnessFunction fun2)
{
<<<<<<< HEAD
    unsigned int fitnessFunctionLength = this->sourceExpression->getFitnessFunctionLength ();
=======
<<<<<<< HEAD
    unsigned int fitnessFunctionLength = this->sourceExpression->getFitnessFunctionLength ();
=======
<<<<<<< HEAD
    unsigned int fitnessFunctionLength = this->sourceExpression->getFitnessFunctionLength ();
=======
    unsigned int fitnessFunctionLength = CExpression :: getFitnessFunctionLength();
>>>>>>> 60419dbe49e5674adf5b4a11c7815d27be15c0ce
>>>>>>> 1f6a959e4363710bf4e322eb8115ae1c9b0355bf
>>>>>>> d32fde80b96b758b74be0618f2443b8cac110716
    //Two strings conjuction.
    for (unsigned int i = 0; i < fitnessFunctionLength; i++)
        fun1[i] &= fun2[i];
    //Freeing memmory.
    free(fun2);

    return fun1;
}


TFitnessFunction Chromosome :: disjunctive (TFitnessFunction fun1, TFitnessFunction fun2)
{
<<<<<<< HEAD
    unsigned int fitnessFunctionLength = this->sourceExpression->getFitnessFunctionLength();
=======
<<<<<<< HEAD
    unsigned int fitnessFunctionLength = this->sourceExpression->getFitnessFunctionLength();
=======
<<<<<<< HEAD
    unsigned int fitnessFunctionLength = this->sourceExpression->getFitnessFunctionLength();
=======
    unsigned int fitnessFunctionLength = CExpression :: getFitnessFunctionLength();
>>>>>>> 60419dbe49e5674adf5b4a11c7815d27be15c0ce
>>>>>>> 1f6a959e4363710bf4e322eb8115ae1c9b0355bf
>>>>>>> d32fde80b96b758b74be0618f2443b8cac110716
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

<<<<<<< HEAD
    unsigned int fitnessFunctionLength = this->sourceExpression->getFitnessFunctionLength ();
=======
<<<<<<< HEAD
    unsigned int fitnessFunctionLength = this->sourceExpression->getFitnessFunctionLength ();
=======
<<<<<<< HEAD
    unsigned int fitnessFunctionLength = this->sourceExpression->getFitnessFunctionLength ();
=======
    unsigned int fitnessFunctionLength = CExpression :: getFitnessFunctionLength ();
>>>>>>> 60419dbe49e5674adf5b4a11c7815d27be15c0ce
>>>>>>> 1f6a959e4363710bf4e322eb8115ae1c9b0355bf
>>>>>>> d32fde80b96b758b74be0618f2443b8cac110716

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
<<<<<<< HEAD
    unsigned int fitnessFunctionLength = this->sourceExpression->getFitnessFunctionLength ();
=======
<<<<<<< HEAD
    unsigned int fitnessFunctionLength = this->sourceExpression->getFitnessFunctionLength ();
=======
<<<<<<< HEAD
    unsigned int fitnessFunctionLength = this->sourceExpression->getFitnessFunctionLength ();
=======
    unsigned int fitnessFunctionLength = CExpression :: getFitnessFunctionLength ();
>>>>>>> 60419dbe49e5674adf5b4a11c7815d27be15c0ce
>>>>>>> 1f6a959e4363710bf4e322eb8115ae1c9b0355bf
>>>>>>> d32fde80b96b758b74be0618f2443b8cac110716

    for (unsigned int i = 0; i < fitnessFunctionLength; i++)
        (*fitnessFunction)[i] = operation;
}


