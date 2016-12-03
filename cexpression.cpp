#include "cexpression.h"

CExpression::CExpression()
{

}

//Check expression validation. Return "false" if invalid symbol have been founded. If expression valid, "true" result will be returned.
bool CExpression::invalidSymbolsExists()
{
    unsigned int expressionLength = this->expression.length();
    //compare expression's symbols with valid ones
    for (unsigned int i = 0; i < expressionLength; i++)
        if ((this->expression[i] < '(') | ((this->expression[i] > '+') & (this->expression[i] < 'A')) |
           ((this->expression[i] > 'Z') & (this->expression[i] < 'a')) | (this->expression[i] > 'z'))
            return true;

    return false;
}

//Remove spaces from the expression.
void CExpression::removeSpaces()
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
    this->expression.resize(expressionLength);
}
