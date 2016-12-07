#include "chromosome.h"
#include "cexpression.h"
#include "calculator.h"
#include <cstdlib>
#include <ctime>


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


unsigned int getExpressionArity (bool &checkArray)
{
    unsigned int expressionArity = 0;

    for (int i = 0; i < ALPHABET_SIZE; i++)
        if ((&checkArray)[i])
            expressionArity++;

    return expressionArity;
}


bool *getOperands (TExpression *expression)
{
    unsigned int expressionLength = (*expression).length();

    bool *checkArray = (bool*) calloc (ALPHABET_SIZE, BLOCK_SIZE);

    for (unsigned int i = 0; i < expressionLength; i++)
        checkArray[atoi (expression[i].c_str() ) - LEFT_ASCII_LETTER] = true;

    return checkArray;
}


void createOperandField(bool *checkArray, unsigned int expressionArity)
{
    //выделение памяти под поле операндов
    _operandField = (TCell**) malloc (OPERAND_FIELD_CAPACITY);

    //выделение памяти под столбцы
    for (unsigned int i = 0; i < OPERAND_FIELD_CAPACITY; i++)
        _operandField[i] = (TCell*) malloc (OPERAND_FIELD_CAPACITY);

    initializeOperandField (checkArray, expressionArity);
}


void initializeOperandField (bool *checkArray, unsigned int expressionArity)
{
    srand(time(NULL));

    unsigned int i = 0, j = 0;
    unsigned int chance = ((OPERAND_FIELD_CAPACITY * OPERAND_FIELD_CAPACITY) % (expressionArity * 2 + 1));
    bool inversionFlag = true;

    for (unsigned int k = 0; k < ALPHABET_SIZE; k++)
        if (!checkArray[k])
            for (unsigned int n = 0; n < chance; n++)
            {
                getRandomPosition (i, j);
                _operandField[i][j] = intToLetter(k);
                if (inversionFlag)
                    _operandField[i][j] |= 128;
                inversionFlag = !inversionFlag;
            }
}


void getRandomPosition (unsigned int &i, unsigned int &j)
{
    while (0 == letterToInt (_operandField[i][j]))
    {
        i = rand () % OPERAND_FIELD_CAPACITY;
        j = rand () % OPERAND_FIELD_CAPACITY;
    }
}




int main()
{
    return 0;
}
