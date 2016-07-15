#include "numbers_factory.h"
#include "number-emitter/number_emitter_item.h"
#include "number-viewer/number_viewer_item.h"

NumbersFactory::NumbersFactory()
{}

bool NumbersFactory::init()
{
    PluginManager::instance()->addPluginComponent<NumberEmitterItem, AbstractItem>();
    PluginManager::instance()->addPluginComponent<NumberViewerItem, AbstractItem>();

    AbstractItem::registerConnectorStyle(Qt::blue, qMetaTypeId<NumberTransporter*>());

    return true;
}
