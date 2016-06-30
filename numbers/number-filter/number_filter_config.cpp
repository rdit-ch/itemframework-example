#include "number_filter_config.h"

void NumberFilterConfig::setModulus(int modulus)
{
    _modulus = modulus;
}

int NumberFilterConfig::modulus() const
{
    return _modulus;
}
