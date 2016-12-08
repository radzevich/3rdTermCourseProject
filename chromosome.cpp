#include "chromosome.h"
#include "cexpression.h"
#include "calculator.h"




void getRandomPosition(unsigned int &i, unsigned int &j);
void initializeOperandField (bool *checkArray, unsigned int expressionArity);

template <typename T>
unsigned int letterToInt(T letter);
unsigned char intToLetter(const int num);


Chromosome::Chromosome(TExpression &expression)
{
    unsigned int chromosomeSize = expression.length();

    this->chromosome = (TChromosome*)calloc(chromosomeSize, sizeof(TChromosome));
}



int main()
{
    return 0;
}
