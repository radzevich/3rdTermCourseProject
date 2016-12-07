#ifndef CEXPRESSION_H
#define CEXPRESSION_H

#include <string>


#define BLOCK_SIZE 1

typedef std::string TExpression;


class CExpression
{
private:
    TExpression expression;

public:
    CExpression();
    //Check expression validation. Return "false" if invalid symbol have been founded. If expression valid, "true" result will be returned.
    bool invalidSymbolsExists();
    //Remove spaces from the expression.
    void removeSpaces();
};

#endif // CEXPRESSION_H
