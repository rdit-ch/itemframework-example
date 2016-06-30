#ifndef NUMBERS_FACTORY_H
#define NUMBERS_FACTORY_H

#include "plugin/interface_factory.h"

class NumbersFactory : public InterfaceFactory
{
    Q_OBJECT

    Q_PLUGIN_METADATA(IID "NumbersFactory" FILE "numbers.json")
    Q_INTERFACES(InterfaceFactory)

public:
    NumbersFactory();
    bool init() override;
};

#endif // NUMBERS_FACTORY_H
