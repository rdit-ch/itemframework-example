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

    auto displayWidget = DisplayWidget::instance();

    connect(_input, &ItemInput::dataChanged, [this, widget, displayWidget]() {
        Number* numberPtr = qobject_cast<Number*>(_input->data());
        if (numberPtr != nullptr) {
            widget->addNumber(*numberPtr);

            // Also show in global display widget
            if (displayWidget != nullptr) {
                qDebug() << "got display";
                displayWidget->setText(QString::number((numberPtr->value())));
            } else {
                qDebug() << "NOT got display";
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
