#ifndef CEXPRESSION_H
#define CEXPRESSION_H

#include <string>


class CExpression
{
private:
    std::string expression;

public:
    CExpression();

    bool invalidSymbolsExists();
    void removeSpaces();
};

#endif // CEXPRESSION_H
