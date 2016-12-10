#include "chromosome.h"
#include "cexpression.h"
#include "adjacencymatrix.h"
#include <cstdlib>
#include <ctime>
#include <math.h>


Chromosome :: Chromosome (CExpression &expression)
{
    this->chromosomeSize = 2 * expression.getExpressionLength();

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

int main()
{
    return 0;
}




TFitnessFunction Chromosome :: calculateFitnessFunction (unsigned int leftIndex = 0, unsigned int rightIndex = (this->chromosomeSize - 1))
{
    TFitnessFunction fitnessFunction = createFitnessFunction();

    if (1 != rightIndex - leftIndex)
    {
        unsigned int lowPriorityPosition = getLowPriorityPosition (leftIndex, rightIndex);

        if (!(leftIndex == lowPriorityPosition) & !(rightIndex == lowPriorityPosition))
            if ((TChromosome) CONJ == this->chromosome[lowPriorityPosition])
                conjuction (calculateFitnessFunction (leftIndex, lowPriorityPosition - 1), calculateFitnessFunction (lowPriorityPosition + 2, rightIndex));
            else
                disjunctive (calculateFitnessFunction (leftIndex, lowPriorityPosition - 1), calculateFitnessFunction (lowPriorityPosition + 2, rightIndex));
        else
            TFitnessFunction
    }


}

unsigned int getLowPriorityPosition (unsigned int leftIndex, unsigned int rightIndex)
{
    TCell lowPriority = exp(2 * log (this->geneCapacity)) - 1;
    unsigned int lowPriorityPostion = leftIndex + OPERATION_PRIORITY;

    for (unsigned int i = lowPriorityPostion; i < rightIndex; i + BLOCK_SHIFT)
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
    return (TFitnessFunction) calloc (CExpression.getFitnessFunctionLength(), sizeof(bool));
}

TFitnessFunction Chromosome :: conjuction (TFitnessFunction fun1, TFitnessFunction fun2)
{
    unsigned int fitnessFunctionLength = CExpression.getFitnessFunctionLength();
    //Two strings conjuction.
    for (unsigned int i = 0; i < fitnessFunctionLength; i++)
        fun1[i] &= fun2[i];
    //Freeing memmory.
    free(fun2);

    return fun1;
}

TFitnessFunction Chromosome :: disjunctive (TFitnessFunction fun1, TFitnessFunction fun2)
{
    unsigned int fitnessFunctionLength = CExpression.getFitnessFunctionLength();
    //Two strings disjunctive.
    for (unsigned int i = 0; i < fitnessFunctionLength; i++)
        fun1[i] |= fun2[i];
    //Freeing memmory.
    free(fun2);

    return fun1;
}

TFitnessFunction Chromosome :: getSourceOneOperandFitnessFunction(TCell xCoord, yCoord)

{

}
