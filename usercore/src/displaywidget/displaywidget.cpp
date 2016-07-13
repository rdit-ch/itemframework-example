#include "include/displaywidget/displaywidget.h"
#include "ui_displaywidget.h"

#include "helper/startup_helper.h"
#include "gui/gui_manager.h"

#include <QDebug>

STARTUP_ADD_COMPONENT(DisplayWidget)
STARTUP_ADD_SINGLETON(DisplayWidget)

DisplayWidget::DisplayWidget(QWidget *parent) :
    QDockWidget(parent),
    ui(new Ui::DisplayWidget)
{
    qDebug() << "DisplayWidget::DisplayWidget";
    ui->setupUi(this);
}

DisplayWidget::~DisplayWidget()
{
    delete ui;
}

void DisplayWidget::setText(const QString& text)
{
    ui->label->setText(text);
}

void DisplayWidget::init()
{
    qDebug() << "DisplayWidget::init";

    // Get the DisplayWidget singleton instance.
    auto widget = DisplayWidget::instance();

    // Add this Widget to left area of the main window.
    Gui_Manager::instance()->include_In_Layout(widget, Window_Layout::Left_Area);
}

bool DisplayWidget::postInit()
{
    return true;
}

bool DisplayWidget::preDestroy()
{
    return true;
}
