#include "number_viewer_item.h"

#include "number_viewer_widget.h"
#include "number/number.h"
#include "displaywidget/displaywidget.h"

NumberViewerItem::NumberViewerItem()
    : AbstractWindowItem("number viewer")
{
    // Load icon
    setImage(QImage(":/icons/number-viewer/number_viewer.png"));

    // Set window
    auto widget = static_cast<NumberViewerWidget*>(allocateWindow());
    setWindow(widget);

    // Create input
    _input = addInput(qMetaTypeId<NumberTransporter*>(), "number input");
    connect(_input, &ItemInput::dataChanged, [this, widget]() {
        auto transporter = qobject_cast<NumberTransporter*>(_input->data());
        // Disconnect from previous transporter
        if (_receiver != nullptr) {
            disconnect(_receiverConnection);
            _receiver = nullptr;
        }

        // Connect to new transporter
        if (transporter != nullptr) {
            _receiver = transporter;
            _receiverConnection = connect(_receiver, &NumberTransporter::numberReceived, [widget] (Number number) {
                // Show number in widget window
                widget->addNumber(number);

                // Show number in global display widget
                auto displayWidget = DisplayWidget::instance();
                if (displayWidget != nullptr) {
                    displayWidget->setText(QString::number((number.value())));
                }
            });
        }
    });
}

NumberViewerItem::~NumberViewerItem()
{
    if (_receiver != nullptr) {
        disconnect(_receiverConnection);
    }
}

QMainWindow* NumberViewerItem::allocateWindow()
{
    return new NumberViewerWidget(this); // TODO this own
}
