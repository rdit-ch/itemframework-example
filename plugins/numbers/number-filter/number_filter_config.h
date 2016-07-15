#ifndef NUMBER_FILTER_CONFIG_H
#define NUMBER_FILTER_CONFIG_H

#include <QObject>

class NumberFilterConfig
{
    Q_GADGET

public:
    void setModulus(int modulus);
    int modulus() const;

private:
    int _modulus = 1;
};

#endif // NUMBER_FILTER_CONFIG_H
