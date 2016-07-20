#ifndef NUMBER_FILTER_ITEM_H
#define NUMBER_FILTER_ITEM_H

#include "item/abstract_window_item.h"
#include "item/item_input.h"
#include "number/number.h"
#include "number/number_transporter.h"
#include "number_filter_config.h"

class NumberFilterItem : public AbstractWindowItem
{
    Q_OBJECT
    Q_PROPERTY(NumberFilterConfig config READ config WRITE setConfig USER true)

public:
    Q_INVOKABLE NumberFilterItem();
    ~NumberFilterItem();

    NumberFilterConfig config() const;
    void setConfig(NumberFilterConfig const & config);

protected:
    QMainWindow* allocateWindow() override;

private:
    bool check(Number const& number);

    ItemInput*         _input    = nullptr;
    ItemOutput*        _output   = nullptr;

    NumberTransporter* _receiver = nullptr;
    QMetaObject::Connection _receiverConnection;
    NumberTransporter  _sender;

    NumberFilterConfig _config;
};

#endif // NUMBER_FILTER_ITEM_H
