#ifndef NUMBER_FILTER_WIDGET_H
#define NUMBER_FILTER_WIDGET_H

#include <QMainWindow>

namespace Ui
{
class NumberFilterWidget;
}

class NumberFilterWidget : public QMainWindow
{
    Q_OBJECT

public:
    explicit NumberFilterWidget(class AbstractItem* item, QWidget* parent = nullptr);
    ~NumberFilterWidget();

    void setModulus(int value);

signals:
    void modulusChanged(int value);

private:
    Ui::NumberFilterWidget* _ui;
    AbstractItem* _item;
};

#endif // NUMBER_FILTER_WIDGET_H
