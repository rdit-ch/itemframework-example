#ifndef NUMBER_VIEWER_WIDGET_H
#define NUMBER_VIEWER_WIDGET_H

#include <QMainWindow>

namespace Ui
{
class NumberViewerWidget;
}

class NumberViewerWidget : public QMainWindow
{
    Q_OBJECT

public:
    explicit NumberViewerWidget(class AbstractItem* item, QWidget* parent = nullptr);
    ~NumberViewerWidget();

public slots:
    void addNumber(const class Number& number);

private:
    Ui::NumberViewerWidget* _ui;
    AbstractItem* _item;
};

#endif // NUMBER_VIEWER_WIDGET_H
