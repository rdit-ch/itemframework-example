#include "number_emitter_item.h"
#include "item/item_output.h"
#include "number/number.h"

#include <QTimer>

NumberEmitterItem::NumberEmitterItem()
    : AbstractItem("number emitter")
{
    // Load icon.
    setImage(QImage(":/icons/number-emitter/number_emitter.png"));

    // Create output.
    _output = addOutput(qMetaTypeId<Number*>(), "number output");

    // Setup and start the timer.
    _timer = new QTimer(this);
    connect(_timer, &QTimer::timeout, [this] () {
        if (_number != nullptr) {
            setOutputData(_output, nullptr);
            _number->deleteLater();
        }

        _number = new Number(_counter++);
        setOutputData(_output, _number);
    });
    _timer->setInterval(500);
    _timer->start();
}

NumberEmitterItem::~NumberEmitterItem()
{
}

