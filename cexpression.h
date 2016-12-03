#ifndef CEXPRESSION_H
#define CEXPRESSION_H

#include <string>


class CExpression
{
private:
    std::string expression;

public:
    CExpression();
    //Check expression validation. Return "false" if invalid symbol have been founded. If expression valid, "true" result will be returned.
    bool invalidSymbolsExists();
    //Remove spaces from the expression.
    void removeSpaces();
};

#endif // CEXPRESSION_H
