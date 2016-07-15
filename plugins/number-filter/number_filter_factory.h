#ifndef NUMBER_FILTER_FACTORY_H
#define NUMBER_FILTER_FACTORY_H

#include "plugin/interface_factory.h"

class NumberFilterFactory : public InterfaceFactory
{
    Q_OBJECT

    Q_PLUGIN_METADATA(IID "NumberFilterFactory" FILE "number_filter.json")
    Q_INTERFACES(InterfaceFactory)

public:
    NumberFilterFactory();
    bool init() override;
};

#endif // NUMBER_FILTER_FACTORY_H
