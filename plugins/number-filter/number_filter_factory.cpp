#include "number_filter_factory.h"
#include "number_filter_item.h"

NumberFilterFactory::NumberFilterFactory()
{}

bool NumberFilterFactory::init()
{
    PluginManager::instance()->addPluginComponent<NumberFilterItem, AbstractItem>();

    return true;
}
