#ifndef NUMBER_FILTER_ITEM_H
#define NUMBER_FILTER_ITEM_H

#include "item/abstract_window_item.h"
#include "item/item_input.h"
#include "number/number.h"
#include "number_filter_config.h"

class NumberFilterItem : public AbstractWindowItem
{
    Q_OBJECT

public:
    Q_INVOKABLE NumberFilterItem();
    ~NumberFilterItem();

protected:
    QMainWindow* allocateWindow() override;

private:
    bool check(Number const& number);

    ItemInput*  _input   = nullptr;
    ItemOutput* _output  = nullptr;
    NumberFilterConfig _config;
};

#endif // NUMBER_FILTER_ITEM_H
