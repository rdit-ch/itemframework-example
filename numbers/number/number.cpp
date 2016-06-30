#include "number.h"

Number::Number(int number, QObject* parent)
    : QObject(parent), _number{number}
{}

int Number::value() const
{
    return _number;
}
