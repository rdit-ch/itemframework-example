#ifndef NUMBER_EMITTER_ITEM_H
#define NUMBER_EMITTER_ITEM_H

#include "item/abstract_item.h"
#include "number/number_transporter.h"

class NumberEmitterItem : public AbstractItem
{
    Q_OBJECT

public:
    Q_INVOKABLE NumberEmitterItem();
    ~NumberEmitterItem();

private:
    class ItemOutput* _output = nullptr;
    class NumberTransporter _numberTransporter;
    class QTimer* _timer = nullptr;
    int _counter = 1;
};

#endif // NUMBER_EMITTER_ITEM_H
