#include "chromosome.h"
#include "cexpression.h"
#include "adjacencymatrix.h"
#include <cstdlib>
#include <ctime>


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

    for (int i = 0; i < this->chromosomeSize; i++)
        if (0 == rand() % CHANCE)
            this->chromosome[i] = rand() % this->geneCapacity;
}



int main()
{
    return 0;
}
