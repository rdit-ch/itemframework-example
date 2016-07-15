#ifndef NUMBER_H
#define NUMBER_H

#include <QDebug>

#include "appcore.h"

class CORE_EXPORT Number
{
public:
    explicit Number(int number);
    int value() const;

private:
    int _number;
};

#endif
