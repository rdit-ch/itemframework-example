#include "number_emitter_item.h"

#include "item/item_output.h"
#include "number/number.h"

#include <QTimer>

NumberEmitterItem::NumberEmitterItem()
    : AbstractItem("number emitter")
{
    // Load icon
    setImage(QImage(":/icons/number-emitter/number_emitter.png"));

    // Create output
    _output = addOutput(qMetaTypeId<NumberTransporter*>(), "number output");
    setOutputData(_output, &_numberTransporter);

    // Setup and start the timer
    _timer = new QTimer(this);
    connect(_timer, &QTimer::timeout, [this]() {
        _numberTransporter.sendNumber(Number{_counter++});
    });
    _timer->setInterval(500);
    _timer->start();
}

NumberEmitterItem::~NumberEmitterItem()
{
}

