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
    this->operandsArray = (TOperand*) calloc (CExpression :: expressionArity * sizeof (TOperand), sizeof (TOperand));
}

//Initializes operansArray with all uniq operands used in native expression.
void CExpression :: initializeOperandsArray()
{
    unsigned int expressionLenght = this->expression.length();
    unsigned int position = 0;
    bool operandRepeats;

    //Adding of uniq operands to operandsArray.
    for (unsigned int i = 0; i < expressionLenght; i++)
    {
        operandRepeats = false;

        //Checking for existence of current operand in operandsArray.
        for (unsigned int j = 0; j < CExpression :: expressionArity; j++)
            if (this->operandsArray[i] == this->expression[j])
                operandRepeats = true;

        //If operand haven't been added in operandsArray before, it will be added
        if (!operandRepeats)
        {
            this->operandsArray[position] = this->expression[i];
            position++;
        }
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
    functionResultSize = (unsigned int) round (exp (this->getExpressionArity() * log (2)));
}

unsigned int CExpression :: getFitnessFunctionLength()
{
    return CExpression :: functionResultSize;
}

TOperand *CExpression::getOperandsArray()
{
    return this->operandsArray;
}

TFitnessFunction CExpression :: getSourceExpressionResult ()
{
    return this->expressionResult;
}

int main()
{
}
