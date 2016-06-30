#ifndef NUMBER_VIEWER_ITEM_H
#define NUMBER_VIEWER_ITEM_H

#include "item/abstract_window_item.h"
#include "item/item_input.h"
#include "number/number.h"

class NumberViewerItem : public AbstractWindowItem
{
    Q_OBJECT

public:
    Q_INVOKABLE NumberViewerItem();
    ~NumberViewerItem();

protected:
    QMainWindow* allocateWindow() override;

private:
    ItemInput* _input = nullptr;
};

#endif // NUMBER_VIEWER_ITEM_H
