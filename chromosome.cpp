#include "chromosome.h"
#include "cexpression.h"
#include "adjacencymatrix.h"
#include <cstdlib>
#include <ctime>
#include <math.h>


Chromosome::Chromosome (TExpression &expression)
{
    this->chromosomeSize = expression.length();

    this->chromosome = (TChromosome) calloc (this->chromosomeSize, sizeof (TGene));

    this->geneCapacity = sizeof (TGene) * BITS_IN_BYTE;

    initializeChromosome();
}


void Chromosome::initializeChromosome()
{
    srand (time (NULL));

    for (unsigned int i = 0; i < (this->chromosomeSize); i++)
        if (0 == rand() % CHANCE)
            this->chromosome[i] = rand() % this->geneCapacity;
}



int main()
{
    return 0;
}


TFitnessFunction Chromosome::calculateFitnessFunction(CExpression &expression)
{
    unsigned int fitnessFunctionSize = exp(2 * log (expression.getExpressionArity()));
    this->fitnessFunction = (TFitnessFunction) calloc (fitnessFunctionSize, sizeof(bool));
}
