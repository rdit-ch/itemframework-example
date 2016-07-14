#include "number_viewer_item.h"
#include "number_viewer_widget.h"

#include "number/number.h"

#include "displaywidget/displaywidget.h"

#include <QDebug>

NumberViewerItem::NumberViewerItem()
    : AbstractWindowItem("number viewer")
{
    setImage(QImage(":/icons/number-viewer/number_viewer.png"));

    auto widget = static_cast<NumberViewerWidget*>(allocateWindow());
    setWindow(widget);

    _input = addInput(qMetaTypeId<Number*>(), "number input");

    connect(_input, &ItemInput::dataChanged, [this, widget]() {
        Number* numberPtr = qobject_cast<Number*>(_input->data());
        if (numberPtr != nullptr) {
            widget->addNumber(*numberPtr);

            // Also show in global display widget
            auto displayWidget = DisplayWidget::instance();
            if (displayWidget != nullptr) {
                displayWidget->setText(QString::number((numberPtr->value())));
            }
        }
    });
}

NumberViewerItem::~NumberViewerItem()
{
}

QMainWindow* NumberViewerItem::allocateWindow()
{
    return new NumberViewerWidget(this);
}
