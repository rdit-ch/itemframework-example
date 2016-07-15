#include "include/displaywidget/displaywidget.h"
#include "ui_displaywidget.h"

#include "helper/startup_helper.h"
#include "gui/gui_manager.h"

#include <QDebug>

STARTUP_ADD_SINGLETON(DisplayWidget)

DisplayWidget::DisplayWidget(QWidget *parent) :
    QDockWidget(parent),
    ui(new Ui::DisplayWidget)
{
    ui->setupUi(this);

    // Add this Widget to left area of the main window.
    Gui_Manager::instance()->include_In_Layout(this, Window_Layout::Left_Area);
}

DisplayWidget::~DisplayWidget()
{
    delete ui;
}

void DisplayWidget::setText(QString const& text)
{
    if (ui->listWidget->count() >= _maxListItemsCount) {
        delete ui->listWidget->item(0);
    }

    ui->listWidget->addItem(text);
}

bool DisplayWidget::postInit()
{
    return true;
}

bool DisplayWidget::preDestroy()
{
    return true;
}
