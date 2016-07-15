#include "number_filter_item.h"

#include "number_filter_widget.h"
#include "number/number.h"
#include "number/number_transporter.h"

NumberFilterItem::NumberFilterItem()
    : AbstractWindowItem("number filter")
{
    // Load icon
    setImage(QImage(":/icons/number-filter/number_filter.png"));

    // Set window
    auto widget = static_cast<NumberFilterWidget*>(allocateWindow());
    setWindow(widget);

    // Connect config widget
    connect(widget, &NumberFilterWidget::modulusChanged, [this](int value) {
        this->_config.setModulus(value);
    });

    // Create input and output
    _input = addInput(qMetaTypeId<NumberTransporter*>(), "number filter input");
    _output = addOutput(qMetaTypeId<NumberTransporter*>(), "filtered output");
    setOutputData(_output, &_sender);
    connect(_input, &ItemInput::dataChanged, [this]() {
        auto transporter = qobject_cast<NumberTransporter*>(_input->data());
        // Disconnect from previous transporter
        if (_receiver != nullptr) {
            disconnect(_receiverConnection);
            _receiver = nullptr;
        }

        // Connect to new transporter
        if (transporter != nullptr) {
            _receiver = transporter;
            _receiverConnection = connect(_receiver, &NumberTransporter::numberReceived, [this] (Number number) {
                if (check(number)) {
                    _sender.sendNumber(number);
                }
            });
        }
    });
}

NumberFilterItem::~NumberFilterItem()
{
    if (_receiver != nullptr) {
        disconnect(_receiverConnection);
    }
}

QMainWindow* NumberFilterItem::allocateWindow()
{
    return new NumberFilterWidget(this);
}

bool NumberFilterItem::check(Number const& number)
{
    auto value = number.value();
    auto modulus = qMax(1, _config.modulus());

    if ((value % modulus) == 0) {
        return true;
    }

    return false;
}
