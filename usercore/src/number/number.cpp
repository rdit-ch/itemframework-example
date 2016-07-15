#include "number/number.h"

Number::Number(int number)
    : _number{number}
{}

int Number::value() const
{
    return _number;
}
