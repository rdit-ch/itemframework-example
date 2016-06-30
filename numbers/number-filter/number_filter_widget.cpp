#include "number_filter_widget.h"
#include "ui_number_filter_widget.h"
#include "number/number.h"
#include "item/abstract_item.h"

#include <QLabel>

NumberFilterWidget::NumberFilterWidget(AbstractItem* item, QWidget* parent)
    : QMainWindow(parent), _ui(new Ui::NumberFilterWidget), _item(item)
{
    _ui->setupUi(this);

    connect(_ui->spinBox, static_cast<void (QSpinBox::*)(int)>(&QSpinBox::valueChanged),
            [this](int value) {
        emit modulusChanged(value);
    });
}

NumberFilterWidget::~NumberFilterWidget()
{
    delete _ui;
}
