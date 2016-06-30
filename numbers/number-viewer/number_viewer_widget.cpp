#include "number_viewer_widget.h"
#include "ui_number_viewer_widget.h"
#include "number/number.h"
#include "item/abstract_item.h"

#include <QListWidget>

NumberViewerWidget::NumberViewerWidget(AbstractItem* item, QWidget* parent)
    : QMainWindow(parent), _ui(new Ui::NumberViewerWidget), _item(item)
{
    _ui->setupUi(this);
}

NumberViewerWidget::~NumberViewerWidget()
{
    delete _ui;
}

void NumberViewerWidget::addNumber(Number const& number)
{
    auto text = QString("Number %1").arg(number.value());

    _ui->listWidget->addItem(text);
    _ui->listWidget->scrollToBottom();
}
