#include "cexpression.h"
#include <cstdlib>
#include <math.h>

CExpression :: CExpression (TExpression &expression)
{
    this->expression = expression;
    calculateExpressionArity (expression);
}

//Check expression validation. Return "false" if invalid symbol have been founded. If expression valid, "true" result will be returned.
bool CExpression :: invalidSymbolsExists()
{
    unsigned int expressionLength = this->expression.length();
    //compare expression's symbols with valid ones
    for (unsigned int i = 0; i < expressionLength; i++)
        if (((this->expression[i] < '(') | ((this->expression[i] > '+') & (this->expression[i] < 'A')) |
           ((this->expression[i] > 'Z') & (this->expression[i] < 'a')) | (this->expression[i] > 'z')   |
           (' ' == this->expression[i])) & ('!' != this->expression[i]))
           return true;

    return false;
}

TExpression *CExpression :: getExpression ()
{
    return &(this->expression);
}


//Remove spaces from the expression.
void CExpression :: removeSpaces()
{
    unsigned int shift = 0;
    unsigned int expressionLength = this->expression.length();
    unsigned int i = 0;
    //Cycle counts the number of spaces and replace forward symbols on it's positions.
    while (i < expressionLength)
    {
        while ((i < expressionLength) & (' ' == this->expression[i + shift]))
        {
            shift++;
            expressionLength--;
        }
        this->expression[i] = this->expression[i + shift];
        i++;
    }
    //Cut off excess symbols from the expression's tail.
    this->expression.resize (expressionLength);
}

//Gives out memmory for operandsArray according to the number of uniq operands used in source expression.
void CExpression :: createOperandsArray()
{
    this->operandsArray = (TOperand*) calloc ((this->expressionArity << 1) * sizeof (TOperand), sizeof (TOperand));
}

//Initializes operansArray with all uniq operands used in native expression.
void CExpression :: initializeOperandsArray()
{
    unsigned int expressionLenght = this->expression.length();
    unsigned int position = 0;

    //Adding of uniq operands to operandsArray.
    for (unsigned int i = 0; i < expressionLenght; i++)
    {
        //Checking for existence of current operand in operandsArray.
        for (unsigned int j = 0; j < this->expressionArity * 2; j++)
            if ((this->operandsArray[i] == this->expression[j]) | (this->operandsArray[i] == (this->expression[j] ^ 128)))
                continue;

        //If operand haven't been added in operandsArray before, it will be added.
        this->operandsArray[position] = this->expression[i];
        this->operandsArray[position + 1] = this->expression[i] | 128;
        position += 2;
    }
}

//Returns number of uniq operands in expression
void CExpression :: calculateExpressionArity (TExpression& expression)
{
    unsigned int expressionLength = expression.length();
    unsigned short int checkarraySize = sizeof(char);
    bool *checkArray = (bool*) calloc (checkarraySize, BLOCK_SIZE);

    for (unsigned int i = 0; i < expressionLength; i++)
        checkArray[(unsigned int)expression[i]] = true;

    for (int i = 97; i < 122; i++)
        this->expressionArity++;
}


unsigned int CExpression :: getExpressionArity()
{
    return expressionArity;
}

unsigned int CExpression :: getExpressionLength()
{
    return CExpression :: expressionLength;
}

void CExpression :: calculateFunctionResultStringLength()
{
    //The length of function result equal to 2 ^ (number of uniq operands).
    fitnessFunctionLength = (unsigned int) round (exp (this->getExpressionArity() * log (2)));
}

unsigned int CExpression :: getFitnessFunctionLength()
{
    return CExpression :: fitnessFunctionLength;
}

TOperand *CExpression::getOperandsArray()
{
    return this->operandsArray;
}

TFitnessFunction CExpression :: getSourceExpressionResult ()
{
    return this->expressionResult;
}



TFitnessFunction CExpression :: calculateFunctionResult (unsigned int left, unsigned int right)
{
    //Fitness function creating throw allocating space for it. Returns pointer to this space.
    TFitnessFunction fitnessFunction = (TFitnessFunction) calloc (this->getFitnessFunctionLength (), sizeof(bool));

    unsigned int lowerPriorityPosition = getLowerPriorityPosition (left, right);

    if (this->expression [lowerPriorityPosition] == '*')
        fitnessFunction = conjuction (calculateFunctionResult (left, lowerPriorityPosition - 1),
                                      calculateFunctionResult (lowerPriorityPosition + 2, right), this->fitnessFunctionLength);
    else if (this->expression [lowerPriorityPosition] == '+')
        fitnessFunction = disjunctive (calculateFunctionResult (left, lowerPriorityPosition - 1),
                                      calculateFunctionResult (lowerPriorityPosition + 2, right), this->fitnessFunctionLength);
    else if (this->expression [lowerPriorityPosition] == '!')
        invertFitnessFuntion (calculateFunctionResult (lowerPriorityPosition + 1, right), fitnessFunction);
    else
        initializeSimpleFunction (fitnessFunction, getOperandNumber (this->expression [lowerPriorityPosition]), this->fitnessFunctionLength);

    return fitnessFunction;
}


unsigned int CExpression :: getOperandNumber (TOperand operand)
{
    unsigned int position = 0;
    unsigned int expressionArity = this->expressionArity;

    while ((position < expressionArity) & (operand != this->operandsArray [position]))
        position++;

    return position;
}


void CExpression :: initializeSimpleFunction (TFitnessFunction fitnessFunction, unsigned int operandNumber, unsigned int fitnessFunctionLength)
{
    //Calculating position for fitness function initialize starting.
    unsigned int startPosition = (unsigned int) round (exp (operandNumber * log (2)));

    unsigned int repeatsCount = startPosition;

    //Inialization cycle.
    for (unsigned int i = startPosition; i < fitnessFunctionLength; )
    {
        for (unsigned int j = i; j < repeatsCount; j++)
            fitnessFunction[j] = true;
        i += repeatsCount * 2;
    }
}


TFitnessFunction CExpression :: conjuction (TFitnessFunction fun1, TFitnessFunction fun2, unsigned int fitnessFunctionLength)
{
    //Two strings conjuction.
    for (unsigned int i = 0; i < fitnessFunctionLength; i++)
        fun1[i] &= fun2[i];
    //Freeing memmory.
    free(fun2);

    return fun1;
}


TFitnessFunction CExpression :: disjunctive (TFitnessFunction fun1, TFitnessFunction fun2, unsigned int fitnessFunctionLength)
{
    //Two strings disjunctive.
    for (unsigned int i = 0; i < fitnessFunctionLength; i++)
        fun1[i] |= fun2[i];
    //Freeing memmory.
    free(fun2);

    return fun1;
}


void CExpression :: invertFitnessFuntion (TFitnessFunction sourceFitnessFunction, TFitnessFunction resultFitnessFunction)
{
    for (unsigned int i = 0; i < this->fitnessFunctionLength; i++)
        resultFitnessFunction [i] = ! sourceFitnessFunction [i];
}


unsigned int CExpression :: getLowerPriorityPosition (unsigned int leftIndex, unsigned int righntIndex)
{
    unsigned int position = leftIndex;
    unsigned int lowPriority = INT_MAX;
    unsigned int breackPriority = 0;
    unsigned int operationPriority;

    bool backwardExists = false;

    for (unsigned int i = leftIndex; i <= righntIndex; i++)
    {
        if ('(' == this->expression [i])
        {
            breackPriority += 5;
            backwardExists = true;
        }
        else if ((')' == this->expression[i]) & (backwardExists))
        {
            breackPriority -= 5;
            if (0 == breackPriority)
                backwardExists = false;
        }
        else if ('+' == this->expression[i])
            operationPriority = 0;
        else if ('*' == this->expression[i])
            operationPriority = 1;
        else if (('(' == this->expression[i]) || (')' == this->expression[i]))
            operationPriority = 2;
        else if ('!' == this->expression[i])
            operationPriority = 3;
        else
            operationPriority = 4;

        if (lowPriority >= breackPriority + operationPriority)
        {
            position = i;
            lowPriority = breackPriority + operationPriority;
        }
    }
    return position;
}


int main()
{
}
