#ifndef CEXPRESSION_H
#define CEXPRESSION_H

#include <string>


#define BLOCK_SIZE 1

typedef std::string TExpression;


class CExpression
{
private:
    TExpression expression;
    //array of all uniq operands used in native string expression.
    char *operandsArray;

    unsigned int expressionArity;

    //Returns operand's name according to it's position in operansArray.
    char getOperandThrowIndex (unsigned int index);
    //Expression validation check. Return "false" if invalid symbol have been founded. If expression valid, "true" result will be returned.
    bool invalidSymbolsExists();
    //Removes spaces from the expression.
    void removeSpaces();
    //Gives out memmory for operandsArray.
    void createOperandsArray();
    //Initializes operandsArray with all uniq values.
    void initializeOperandsArray();
    //Calculates the number of uniq operands in expression
    void calculateExpressionArity (TExpression& expression);

public:
    CExpression(TExpression& expression);
    //Returns expressionArity.
    unsigned int getExpressionArity();



};

#endif // CEXPRESSION_H
