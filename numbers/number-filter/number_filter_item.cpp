#include "number_filter_item.h"
#include "number_filter_widget.h"

#include "../number/number.h"

NumberFilterItem::NumberFilterItem()
    : AbstractWindowItem("number filter")
{
    setImage(QImage(":/icons/number-filter/number_filter.png"));

    auto widget = static_cast<NumberFilterWidget*>(allocateWindow());
    setWindow(widget);

    connect(widget, &NumberFilterWidget::modulusChanged, [this](int value) {
        this->_config.setModulus(value);
    });

    _input = addInput(qMetaTypeId<Number*>(), "number filter input");
    _output = addOutput(qMetaTypeId<Number*>(), "filtered output");

    connect(_input, &ItemInput::dataChanged, [this, widget]() {
        Number* numberPtr = qobject_cast<Number*>(_input->data());
        if (numberPtr != nullptr) {
            if (check(*numberPtr)) {
                setOutputData(_output, numberPtr);
            }
        }
    });
}

NumberFilterItem::~NumberFilterItem()
{
}

QMainWindow* NumberFilterItem::allocateWindow()
{
    return new NumberFilterWidget(this);
}

bool NumberFilterItem::check(Number const& number)
{
    auto value = number.value();

    if ((value % _config.modulus()) == 0) {
        return true;
    }

    return false;
}
