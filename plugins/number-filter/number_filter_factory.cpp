#include "number_filter_factory.h"
#include "number_filter_item.h"
#include "number_filter_config.h"

#include "helper/dom_helper.h"

NumberFilterFactory::NumberFilterFactory()
{}

bool NumberFilterFactory::init()
{
    // Register NumberFilterItem plugin with item framework.
    PluginManager::instance()->addPluginComponent<NumberFilterItem, AbstractItem>();

    // Register custom serializer and deserializer for our NumberFilterConfig
    // class with the item frameworks serialization mechanism.
    static char const* const ModulusAttributeName = "modulus";
    auto serializer = [](QDomDocument&, QDomElement& element, NumberFilterConfig const& config) {
        element.setAttribute(ModulusAttributeName, config.modulus());
        return true;
    };
    auto deserializer = [](QDomElement const& element, bool& outSuccess) {
        NumberFilterConfig config{};
        QString const& modulusStr = element.attribute(ModulusAttributeName);
        if (!modulusStr.isNull()) {
            config.setModulus(modulusStr.toInt());
            outSuccess = true;
        } else {
            outSuccess = false;
        }
        return config;
    };
    DomHelper::registerSerializable<NumberFilterConfig>(serializer, deserializer);

    return true;
}
